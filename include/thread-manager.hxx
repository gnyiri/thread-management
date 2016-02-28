/*!
 * \file thread-manager.hxx
 * \author gergely.nyiri@gmail.com
 */

#ifndef _THREAD_MANAGER_HXX_
#define _THREAD_MANAGER_HXX_

#include <pthread.h>
#include <fstream>
#include <iostream>
#include <stdexcept>

namespace gtm
{
  /*!
   * \class thread_exception
   * \brief exception class
   */
  class thread_exception : public std::exception
  {
  public:
    /*!
     * \brief CTOR
     */
    explicit thread_exception(const std::string& p_what)
    {
      std::cout << "Exception! Details: " << p_what << std::endl;
    }
  };
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
    virtual ~thread_manager() = 0;
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

#endif
