/*
 *                         OpenSplice DDS
 *
 *   This software and documentation are Copyright 2006 to TO_YEAR PrismTech
 *   Limited, its affiliated companies and licensors. All rights reserved.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 */
#ifndef C_LAPTIME_H
#define C_LAPTIME_H

#if defined (__cplusplus)
extern "C" {
#endif
#include "os_if.h"

#ifdef OSPL_BUILD_CORE
#define OS_API OS_API_EXPORT
#else
#define OS_API OS_API_IMPORT
#endif
/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

typedef struct c_laptime_s *c_laptime;

OS_API c_laptime c_laptimeCreate (const char *id);
OS_API void      c_laptimeDelete (c_laptime laptime);
OS_API void      c_laptimeReset  (c_laptime laptime);
OS_API void      c_laptimeStart  (c_laptime laptime);
OS_API void      c_laptimeStop   (c_laptime laptime);
OS_API void      c_laptimeReport (c_laptime laptime, const char *info);

#undef OS_API

#if defined (__cplusplus)
}
#endif

#endif /* C_LAPTIME_H */
