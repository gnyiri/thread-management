/*!
 * \file thread-manager.cxx
 * \author gergely.nyiri@gmail.com
 */

#include "thread-manager.hxx"

namespace gtm
{
  //----------------------------------------------------------------------------------------
  thread_manager::thread_manager()
  {
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
  }
}
