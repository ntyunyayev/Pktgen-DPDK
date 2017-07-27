/*-
 * Copyright (c) <2010-2017>, Intel Corporation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in
 *   the documentation and/or other materials provided with the
 *   distribution.
 *
 * - Neither the name of Intel Corporation nor the names of its
 *   contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/* Created 2011 by Keith Wiles @ intel.com */

#ifndef LUA_SHELL_H_
#define LUA_SHELL_H_

#define lua_c
#include "lua.h"
#include "lauxlib.h"

#ifdef __cplusplus
extern "C" {
#endif

#define IO_PREFIX       "_IO_"
#define IOPREF_LEN      (sizeof(IO_PREFIX)/sizeof(char) - 1)
#define IO_INPUT        (IO_PREFIX "input")
#define IO_OUTPUT       (IO_PREFIX "output")

#define MAX_NEW_LIBS	16
typedef void (*newlib_t)(lua_State * L);

int lua_newlib_add(newlib_t n);
void lua_newlibs_init(lua_State * L);

LUALIB_API int luaL_setprivate(lua_State * L, void * val);
LUALIB_API void * luaL_getprivate(lua_State * L);

LUA_API void (lua_setprivate) (lua_State * L, void * val) ;
LUA_API void * (lua_getprivate) (lua_State * L);

void createstdfile (lua_State *L, FILE *f, const char *k,
                           const char *fname);

#ifdef __cplusplus
}
#endif

#endif /* LUA_SHELL_H_ */
