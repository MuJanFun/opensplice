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
#ifndef NN_GROUPSET_H
#define NN_GROUPSET_H

struct nn_groupset;

typedef int (*nn_groupset_foreach_t) (v_group g, void *arg);

int nn_groupset_add_group (struct nn_groupset *gs, v_group g);

/* groupset_add locks ADD, then calls groupset_add_group, which locks
   GS. Don't do groupset_add(a,b) PAR groupset_add(b,a). */
int nn_groupset_add (struct nn_groupset *gs, const struct nn_groupset *add);

void nn_groupset_free (struct nn_groupset *gs);
int nn_groupset_fromqos (struct nn_groupset *gs, v_kernel kernel, const nn_xqos_t *qos);
struct nn_groupset *nn_groupset_new (void);

/* groupset_foreach locks GS, and keeps it locked across calls to f() */
int nn_groupset_foreach (const struct nn_groupset *gs, nn_groupset_foreach_t f, void *arg);
int nn_groupset_empty (const struct nn_groupset *gs);

#endif /* NN_GROUPSET_H */

/* SHA1 not available (unoffical build.) */
