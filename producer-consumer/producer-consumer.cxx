/*!
 * \file producer-consumer.cxx
 * \author gergely.nyiri@gmail.com
 */

#include <producer-consumer.hxx>

namespace gtm
{
  //----------------------------------------------------------------------
  producer_consumer::producer_consumer(const int p_num_producer_threads = 1, const int num_consumer_threads = 1)
  {
    pthread_mutex_init(&m_log_mtx, 0);

    m_logfile.open("/tmp/producer_consumer.log");

    if (!m_logfile.is_open())
    {

    }
  }
  //----------------------------------------------------------------------
  producer_consumer::~producer_consumer()
  {
  }
  //----------------------------------------------------------------------
  void producer_consumer::log(const char* p_msg, ...)
  {
    char l_buff[300];
    va_list l_arglist;
    va_start(t_arglist, p_msg);
    vsnprintf(l_buff, 300, p_msg, l_arglist);
    va_end(l_arglist);


  }
}
