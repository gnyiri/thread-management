/*!
 * \file producer-consumer.hxx
 * \author gergely.nyiri@gmail.com
 */

#include <pthread.h>
#include <fstream>

namespace gtm
{
  /*!
   * \class thread_manager
   * \brief thread manager base class
   */
  class thread_manager
  {
  public:
    /*!
     * \brief CTOR
     */
    thread_manager();
    /*!
     * \brief DTOR
     */
    virtual ~thread_manager();
    /*!
     * \brief log
     */
    void log(const char* p_msg, ...);
  private:
    /*!
     * \brief log file
     */
    std::ofstream m_logfile;
  };
}
