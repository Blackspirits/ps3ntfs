#ifndef __PS3NTFS_INC__
#define __PS3NTFS_INC__

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <sys/prx.h>

#include "ntfs.h"

#define ps3ntfs_running() (sys_prx_get_module_id_by_name("NTFSD", 0, NULL) > 0)

ntfs_md* ps3ntfs_prx_mounts(void);
int ps3ntfs_prx_num_mounts(void);

void ps3ntfs_automount(uint64_t ptr);

#ifdef __cplusplus
}
#endif

#endif
