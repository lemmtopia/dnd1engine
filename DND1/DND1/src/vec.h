/*
    File: vec.h
    Desc: Vector math.

    Copyright (C) 2024-2025 Gabriel Grigoleto Cunha
*/
#ifndef VEC_H
#define VEC_H

typedef struct {
    float x, y;
} vec2_t;

typedef struct {
    float x, y, z;
} vec3_t;

typedef struct {
    float x, y, z, w;
} vec4_t;

vec2_t vec2_add(vec2_t a, vec2_t b);
vec2_t vec2_sub(vec2_t a, vec2_t b);
vec2_t vec2_mul(vec2_t a, vec2_t b);
vec2_t vec2_div(vec2_t a, vec2_t b);

vec3_t vec3_add(vec3_t a, vec3_t b);
vec3_t vec3_sub(vec3_t a, vec3_t b);
vec3_t vec3_mul(vec3_t a, vec3_t b);
vec3_t vec3_div(vec3_t a, vec3_t b);

vec4_t vec4_add(vec4_t a, vec4_t b);
vec4_t vec4_sub(vec4_t a, vec4_t b);
vec4_t vec4_mul(vec4_t a, vec4_t b);
vec4_t vec4_div(vec4_t a, vec4_t b);

vec2_t project_ortho(vec3_t a);
vec2_t project_linear(vec3_t a);

#endif