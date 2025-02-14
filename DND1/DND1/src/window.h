/*
    File: window.h
    Desc: Platform application instance handling

    Copyright (C) 2024-2025 Gabriel Grigoleto Cunha
*/
#ifndef WINDOW_H
#define WINDOW_H

#include "defs.h"

#include <SDL3/SDL.h>
#include <GL/glew.h>

#define WIDTH 800
#define HEIGHT 600

boolean window_initialize(void);
boolean window_should_close(void);
void window_destroy(void);

void window_swap_buffers(void);

#endif