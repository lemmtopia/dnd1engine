/*
    File: renderer.c
    Desc: Platform stuff. Where the rendering happens.

    Copyright (C) 2024-2025 Gabriel Grigoleto Cunha
*/
#include "renderer.h"
#include "mat4.h"
#include "utils.h"

#include <string.h>

renderer_t global_renderer;
extern float dt;

void renderer_init(renderer_t* renderer) {
    // Setup buffers and arrays
    glGenVertexArrays(1, &renderer->vao);
    glGenBuffers(1, &renderer->vbo);

    // Setup shader
    char* sh_vertex;
    char* sh_fragment;
    GLuint vs, fs;

    sh_vertex = (char*)utils_alloc(utils_get_file_size("src/vertex.glsl") + 1);
    sh_fragment = (char*)utils_alloc(utils_get_file_size("src/fragment.glsl") + 1);

    utils_read_file_bin(sh_vertex, "src/vertex.glsl");
    utils_read_file_bin(sh_fragment, "src/fragment.glsl");

    vs = shader_compile(GL_VERTEX_SHADER, sh_vertex);
    fs = shader_compile(GL_FRAGMENT_SHADER, sh_fragment);
    renderer->sh_program = shader_make_program(vs, fs);

    utils_free(sh_vertex);
    utils_free(sh_fragment);

    // initizalize matrices
    mat4_t identity = MAT4_IDENTITY;

    for (int i = 0; i < 16; i++) {
        renderer->view[i] = identity[i];
        renderer->model[i] = identity[i];
    }

    // setup view
    renderer->view[10] = 0.0f;

    // setup perspective
    float* temp = mat4_perspective(PI / 2, 800 / 600, 1000.0f, 0.01f);

    for (int i = 0; i < 16; i++) {
        renderer->perspective[i] = temp[i];
    }

    utils_free(temp);
}

void renderer_push_triangle(renderer_t* renderer, render_vertex_t* vertices) {
    int start = renderer->triangle_count * 3;
    for (int i = 0; i < 3; i++) {
        renderer->vertices[start + i] = vertices[i];
    }

    renderer->triangle_count++;
}

void renderer_send_data_to_buffer(GLenum buffer_type, GLuint buffer, int size, void* data, GLenum usage) {
    glBindBuffer(buffer_type, buffer);
    glBufferData(
        buffer_type,
        size,
        data,
        usage);
}

void renderer_send_data(renderer_t* renderer) {
    glGenVertexArrays(1, &renderer->vao);
    glGenBuffers(1, &renderer->vbo);

    glBindVertexArray(renderer->vao);

    renderer_send_data_to_buffer(
        GL_ARRAY_BUFFER,
        renderer->vbo,
        renderer->triangle_count * 3 * sizeof(render_vertex_t),
        renderer->vertices,
        GL_STATIC_DRAW);

    // pos
    glVertexAttribPointer(
        0,
        3,
        GL_FLOAT,
        GL_FALSE,
        6 * sizeof(float),
        (void*)0);
    glEnableVertexAttribArray(0);

    // color
    glVertexAttribPointer(
        1,
        3,
        GL_FLOAT,
        GL_FALSE,
        6 * sizeof(float),
        (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void renderer_shutdown(renderer_t* renderer) {
    //...
}

void renderer_clear(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void renderer_set_clear_color(float r, float g, float b) {
    glClearColor(r, g, b, 1.0f);
}

void renderer_draw_arrays(renderer_t renderer) {
    glUseProgram(renderer.sh_program);

    renderer_set_uniforms(renderer);

    glBindVertexArray(renderer.vao);
    glBindBuffer(GL_ARRAY_BUFFER, renderer.vbo);

    glDrawArrays(GL_TRIANGLES, 0, renderer.triangle_count * 3);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glUseProgram(0);
}

void renderer_set_uniforms(renderer_t renderer) {
    glUniformMatrix4fv(
        glGetUniformLocation(renderer.sh_program, "u_view"),
        1,
        GL_FALSE,
        renderer.view);

    glUniformMatrix4fv(
        glGetUniformLocation(renderer.sh_program, "u_model"),
        1,
        GL_FALSE,
        renderer.model);

    glUniformMatrix4fv(
        glGetUniformLocation(renderer.sh_program, "u_perspective"),
        1,
        GL_FALSE,
        renderer.perspective);

    float offset_arr[] = { renderer.offset.x, renderer.offset.y, renderer.offset.z };

    glUniform3fv(
        glGetUniformLocation(renderer.sh_program, "u_offset"),
        1,
        offset_arr);
}

void renderer_set_offset(renderer_t* renderer, vec3_t new_offset) {
    renderer->offset = new_offset;
}