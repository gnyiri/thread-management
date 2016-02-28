/*!
 * \file producer-consumer.hxx
 * \author gergely.nyiri@gmail.com
 */

#include <pthread.h>
#include <fstream>

namespace gtm
{
  /*!
   * \class producer_consumer
   * \brief producer/consumer model
   */
  class producer_consumer
  {
  public:
    /*!
     * \brief CTOR
     */
    producer_consumer(const int p_num_producer_threads = 1, const int num_consumer_threads = 1);
    /*!
     * \brief DTOR
     */
    virtual ~producer_consumer();
    /*!
     * \brief log
     */
    void log(const char* p_msg, ...);
  private:
    /*!
     * \brief log file
     */
    std::ofstream m_logfile;
    /*!
     * \brief log mutex
     */
    pthread_mutex_t m_log_mtx;
  };
}
