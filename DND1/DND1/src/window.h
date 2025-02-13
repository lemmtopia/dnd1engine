/*
    File: window.h
    Desc: Platform application instance handling

    Copyright (C) 2024-2025 Gabriel Grigoleto Cunha
*/
#ifndef WINDOW_H
#define WINDOW_H

#include "defs.h"

#include <SDL3/SDL.h>
#include <SDL3/SDL_opengl.h>

#define WIDTH 800
#define HEIGHT 600

boolean initialize_window(void);
boolean window_should_close(void);
void destroy_window(void);

void swap_window_buffers(void);

#endif