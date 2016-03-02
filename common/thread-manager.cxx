/*!
 * \file thread-manager.cxx
 * \author gergely.nyiri@gmail.com
 */

#include "thread-manager.hxx"

#include <stdarg.h>
#include <unistd.h>

namespace gtm
{
  //----------------------------------------------------------------------------------------
  thread_manager::thread_manager()
  {
    pthread_mutexattr_t l_attr;
    pthread_mutexattr_init(&l_attr);
    pthread_mutex_init(&m_log_mtx, &l_attr);

    m_logfile.open("/tmp/thread_manager.log", std::ios::out | std::ios::app);

    if (!m_logfile.is_open())
    {
      throw new thread_exception("Could not open logfile!");
    }
  }
  //----------------------------------------------------------------------------------------
  thread_manager::~thread_manager()
  {
    m_logfile.close();
  }
  //----------------------------------------------------------------------------------------
  void thread_manager::log(const char* p_msg, ...)
  {
    thread_lock_guard l_lock_guard(&m_log_mtx);

    int l_pid = getpid();

    char l_buff[200];
    va_list l_arg_list;
    va_start(l_arg_list, p_msg);
    vsnprintf(l_buff, 200, p_msg, l_arg_list);
    va_end(l_arg_list);

    m_logfile << "[" << l_pid << "] - " << l_buff << std::endl;
  }
}
