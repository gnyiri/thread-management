/*!
 * \author gergely.nyiri@gmail.com
 * \brief thread utilities
 */

#ifndef _THREAD_UTILS_HXX_
#define _THREAD_UTILS_HXX_

#include <stdexcept>
#include <pthread.h>

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
   * \class thread_lock_guard
   * \brief lock guard
   */
  class thread_lock_guard
  {
  public:
    /*!
     * \brief CTOR
     */
    thread_lock_guard(pthread_mutex_t* p_mutex)
    {
      m_mutex = p_mutex;
      pthread_mutex_lock(m_mutex);
    }
    /*!
     * \brief DTOR
     */
    ~thread_lock_guard()
    {
      pthread_mutex_unlock(m_mutex);
    }
  private:
    /*!
     * \brief mutex to hold
     */
    pthread_mutex_t* m_mutex;
    /*!
     * \brief disable default CTOR
     */
    thread_lock_guard();
    /*!
     * \brief disable copy CTOR
     */
    thread_lock_guard(const thread_lock_guard&);
    /*!
     * \brief disable assignment operator
     */
    thread_lock_guard& operator=(const thread_lock_guard&);
  };
}

#endif
