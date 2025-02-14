/*
    File: mat4.h
    Desc: Matrix math.

    Copyright (C) 2024-2025 Gabriel Grigoleto Cunha
*/

#include "mat4.h"
#include "utils.h"
#include <math.h>

float* mat4_mul(float* a, float* b)
{
    float* result = (float*)utils_alloc(sizeof(float) * MAT4_SIZE);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result[i * 4 + j] = 0.0f;

            for (int k = 0; k < 4; k++) {
                result[i * 4 + j] += a[i * 4 + k] * b[k * 4 + j];
            }
        }
    }

    return result;
}

float* mat4_perspective(float fov, float aspect_ratio, float zfar, float znear) {
    float* result = (float*)utils_alloc(sizeof(float) * MAT4_SIZE);

    for (int i = 0; i < 16; i++) {
        result[i] = 0;
    }

    float factor = 1 / tanf(fov / 2);

    result[0] = aspect_ratio * factor;
    result[5] = factor;
    result[10] = zfar / (zfar - znear);
    result[11] = (-zfar * znear) / (zfar - znear);
    result[14] = 1.0f;
    result[15] = 1.0f;

    return result;
}

float* mat4_rotate_x(float angle)
{
    float* newview_buff = (float*)utils_alloc(sizeof(float) * MAT4_SIZE);

    float newview[] = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, cos(angle), -sin(angle), 0.0f,
        0.0f, sin(angle), cos(angle), 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    memcpy(newview_buff, newview, sizeof(newview));

    return newview_buff;
}

float* mat4_rotate_y(float angle)
{
    float* newview_buff = (float*)utils_alloc(sizeof(float) * MAT4_SIZE);

    float newview[] = {
        cos(angle), 0.0f, sin(angle), 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        -sin(angle), 0.0f, cos(angle), 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    memcpy(newview_buff, newview, sizeof(newview));

    return newview_buff;
}

float* mat4_rotate_z(float angle)
{
    float* newview_buff = (float*)utils_alloc(sizeof(float) * MAT4_SIZE);

    float newview[] = {
        cos(angle), -sin(angle), 0.0f, 0.0f,
        sin(angle), cos(angle), 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    memcpy(newview_buff, newview, sizeof(newview));

    return newview_buff;
}