/*
    File: mat4.h
    Desc: Matrix math.

    Copyright (C) 2024-2025 Gabriel Grigoleto Cunha
*/
#ifndef MAT4_H
#define MAT4_H

#define MAT4_SIZE 16 // 4 * 4
#define MAT4_IDENTITY {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f}

// typedef
typedef float mat4_t[MAT4_SIZE];

// functions
float* mat4_mul(float* a, float* b);
float* mat4_perspective(float fov, float aspect_ratio, float zfar, float znear);

float* mat4_rotate_x(float angle);
float* mat4_rotate_y(float angle);
float* mat4_rotate_z(float angle);

#endif