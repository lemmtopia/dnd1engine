/*
    File: renderer.h
    Desc: Platform stuff. Where the rendering happens.

    Copyright (C) 2024-2025 Gabriel Grigoleto Cunha
*/
#ifndef RENDERER_H
#define RENDERER_H

#include <SDL3/SDL.h>
#include <GL/glew.h>

#include "vec.h"
#include "mat4.h"
#include "defs.h"

typedef struct render_vertex_t {
    vec3_t pos;
    vec3_t col;
} render_vertex_t;

#define MAX_TRIANGLES 128
#define MAX_VERTICES MAX_TRIANGLES * 3

typedef struct renderer_t {
    GLuint vao, vbo, ebo;
    GLuint sh_program;

    mat4_t model, view, perspective;
    vec3_t offset;

    render_vertex_t vertices[MAX_VERTICES];
    u32 triangle_count;
} renderer_t;

extern renderer_t global_renderer;

void renderer_init(renderer_t* renderer);
void renderer_push_triangle(renderer_t* renderer, render_vertex_t* vertices);
void renderer_send_data(renderer_t* renderer);
void renderer_shutdown(renderer_t* renderer);

void renderer_clear(void);
void renderer_set_clear_color(float r, float g, float b);
void renderer_draw_arrays(renderer_t renderer);
void renderer_set_uniforms(renderer_t renderer);

void renderer_set_offset(renderer_t* renderer, vec3_t new_offset);

#endif