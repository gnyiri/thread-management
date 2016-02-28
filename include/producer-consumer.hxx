/*!
 * \file producer-consumer.hxx
 * \author gergely.nyiri@gmail.com
 */

#ifndef _PRODUCER_CONSUMER_HXX_
#define _PRODUCER_CONSUMER_HXX_

#include "thread-manager.hxx"

namespace gtm
{
  /*!
   * \class producer_consumer
   * \brief producer/consumer model
   */
  class producer_consumer : thread_manager
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
  private:
  };
}

#endif
