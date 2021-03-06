/*!
 * \file producer-consumer.cxx
 * \author gergely.nyiri@gmail.com
 */

#include "producer-consumer.hxx"

namespace gtm
{
  //----------------------------------------------------------------------
  producer_consumer::producer_consumer(const int p_num_producer_threads, const int num_consumer_threads)
  {
    log("Create producer/consumer object");
  }
  //----------------------------------------------------------------------
  producer_consumer::~producer_consumer()
  {
    log("Destroy producer/consumer object");
  }
}
