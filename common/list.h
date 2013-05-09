/**
 * xrdp: A Remote Desktop Protocol server.
 *
 * Copyright (C) Jay Sorg 2004-2012
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * simple list
 */

#if !defined(LIST_H)
#define LIST_H

#include "arch.h"

/* list */
struct list
{
	tbus* items;
	int count;
	int alloc_size;
	int grow_by;
	int auto_free;
};
typedef struct list xrdpList;

xrdpList* APP_CC list_create(void);
void APP_CC list_delete(xrdpList* self);
void APP_CC list_add_item(xrdpList* self, tbus item);
tbus APP_CC list_get_item(xrdpList* self, int index);
void APP_CC list_clear(xrdpList* self);
int APP_CC list_index_of(xrdpList* self, tbus item);
void APP_CC list_remove_item(xrdpList* self, int index);
void APP_CC list_insert_item(xrdpList* self, int index, tbus item);
void APP_CC list_append_list_strdup(xrdpList* self, xrdpList* dest, int start_index);
void APP_CC list_dump_items(xrdpList* self);

#endif
