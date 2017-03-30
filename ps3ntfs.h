#ifndef __PS3NTFS_INC__
#define __PS3NTFS_INC__

#include <stddef.h>
#include <sys/synchronization.h>

#include "ntfs.h"

#define ps3ntfs_running() (sys_prx_get_module_id_by_name("NTFSD", 0, NULL) > 0)
#define ps3ntfs_prx_lock() sys_lwmutex_trylock(ps3ntfs_prx_mutex_ptr())
#define ps3ntfs_prx_unlock() sys_lwmutex_unlock(ps3ntfs_prx_mutex_ptr())

#ifdef __cplusplus
extern "C" {
#endif

ntfs_md* ps3ntfs_prx_mounts(void);
int ps3ntfs_prx_num_mounts(void);

sys_lwmutex_t* ps3ntfs_prx_mutex_ptr(void);

void ps3ntfs_automount(uint64_t ptr);

#ifdef __cplusplus
}
#endif

#endif
