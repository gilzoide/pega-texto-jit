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

#include "pega-texto-jit.h"

#include <jit/jit.h>

#include <stdlib.h>

typedef struct pt_jit_context {
	jit_context_t jit;
} pt_jit_context;


pt_jit_context *pt_jit_create_context() {
	pt_jit_context *ctx;
	if(ctx = malloc(sizeof(pt_jit_context))) {
		if((ctx->jit = jit_context_create()) == NULL) {
			free(ctx);
			ctx = NULL;
		}
	}
	return ctx;
}

void pt_jit_destroy_context(pt_jit_context *ctx) {
	if(ctx) {
		jit_context_destroy(ctx->jit);
		free(ctx);
	}
}

