#ifndef NVK_PRIVATE_H
#define NVK_PRIVATE_H 1

#include <assert.h>

#include "nvk_entrypoints.h"

#include "util/log.h"
#include "util/u_memory.h"
#include "vulkan/runtime/vk_log.h"
#include "vulkan/util/vk_alloc.h"
#include "vulkan/util/vk_util.h"
#include "vulkan/runtime/vk_pipeline_layout.h"

#include <fcntl.h>
#include <xf86drm.h>

#define NVK_MAX_SETS 8
#define NVK_MAX_PUSH_SIZE 128
#define NVK_MAX_DYNAMIC_BUFFERS 64
#define NVK_MAX_RTS 8
#define NVK_MIN_SSBO_ALIGNMENT 64
#define NVK_MIN_UBO_ALIGNMENT 64
#define NVK_MAX_VIEWPORTS 16
#define NVK_MAX_DESCRIPTOR_SIZE 16
#define NVK_MAX_PUSH_DESCRIPTORS 32
#define NVK_MAX_DESCRIPTOR_SET_SIZE (1u << 30)
#define NVK_PUSH_DESCRIPTOR_SET_SIZE \
   (NVK_MAX_PUSH_DESCRIPTORS * NVK_MAX_DESCRIPTOR_SIZE)
#define NVK_SSBO_BOUNDS_CHECK_ALIGNMENT 4
#define NVK_MAX_MULTIVIEW_VIEW_COUNT 32

struct nvk_addr_range {
   uint64_t addr;
   uint64_t range;
};

/**
 * Warn on ignored extension structs.
 *
 * The Vulkan spec requires us to ignore unsupported or unknown structs in
 * a pNext chain.  In debug mode, emitting warnings for ignored structs may
 * help us discover structs that we should not have ignored.
 *
 *
 * From the Vulkan 1.0.38 spec:
 *
 *    Any component of the implementation (the loader, any enabled layers,
 *    and drivers) must skip over, without processing (other than reading the
 *    sType and pNext members) any chained structures with sType values not
 *    defined by extensions supported by that component.
 */
#define nvk_debug_ignored_stype(sType)                                                             \
   mesa_logd("%s: ignored VkStructureType %u\n", __func__, (sType))

#endif
