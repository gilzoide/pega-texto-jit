/*
 * Copyright 2019 Gil Barbosa Reis <gilzoide@gmail.com>
 * This file is part of pega-texto-jit.
 * 
 * Pega-texto-jit is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Pega-texto-jit is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with pega-texto-jit.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Any bugs should be reported to <gilzoide@gmail.com>
 */

/** @file pega-texto-jit.h
 */

#ifndef __PEGA_TEXTO_JIT_H__
#define __PEGA_TEXTO_JIT_H__

/// Pega-texto major version number
#define PT_JIT_VERSION_MAJOR 0
/// Pega-texto minor version number
#define PT_JIT_VERSION_MINOR 1
/// Pega-texto patch version number
#define PT_JIT_VERSION_PATCH 0
/// Pega-texto version string
#define PT_JIT_VERSION "0.1.0"

#ifdef __cplusplus
extern "C" {
#endif

#include <pega-texto.h>

/**
 * The JIT context used to compile pega-texto grammars.
 */
typedef struct pt_jit_context pt_jit_context;

pt_jit_context *pt_jit_create_context();
void pt_jit_destroy_context(pt_jit_context *ctx);


#ifdef __cplusplus
}
#endif

#endif


