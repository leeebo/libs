/**
 * @file osal_thread.h
 * @author Li Bo (libo_go@163.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef OSAL_THREAD_H
#define OSAL_THREAD_H

#include "export_global.h"
#ifdef _WIN32 //If Windows Platform
#include "pthread_win32/pthread.h"
#else //If Linux/UNIX Platform
#include "pthread.h"
#endif

typedef void* thread_handle_t;
typedef void* (*thread_code)(void*);

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief starts a new thread in the calling process.  The new thread starts execution by
 *      invoking thread_code; arg is passed as the sole argument of thread_code.
 * 
 * @param thread thread handle
 * @param code thread_code the new thread will operate
 * @param arg thread_code arguments
 * @return ** int  On  success, pthread_create() returns 0; on error, it returns an error number, and the contents of *thread are
 *      undefined.
 */
int osal_thread_create(thread_handle_t *thread, thread_code code, void *arg);

/**
 * @brief send a cancellation request to a thread, Whether and when the target
 *      thread reacts to the cancellation request depends on two attributes that are under the control of that thread:
 *      its cancelability state and type.
 * 
 * @param thread thread handle
 * @return ** int On success returns 0; on error, it returns a nonzero error number.
 */
int osal_thread_cancel(thread_handle_t thread);

/**
 * @brief  join with a terminated thread, waits for the thread specified by thread to terminate.  If that thread has already
 *      terminated, then pthread_join() returns immediately.  The thread specified by thread must be joinable.
 * 
 * @param thread thread handle
 * @param value_ptr If value_ptr is not NULL, then pthread_join() copies the exit status of the target thread
 * @return ** int On success, returns 0; on error, it returns an error number.
 */
int osal_thread_join(thread_handle_t thread, void **value_ptr);

/**
 * @brief Detaching a Thread, marks the thread identified by thread as detached.  When a detached thread ter‐
 *      minates, its resources are automatically released back to the system without the need for  another  thread  to
 *      join with the terminated thread.
 * 
 * @param thread thread handle
 * @return ** int On success, returns 0; on error, it returns an error number
 */
int osal_thread_detach(thread_handle_t thread);

#ifdef __cplusplus
}
#endif

#endif
