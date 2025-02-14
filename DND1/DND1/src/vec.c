/*
    File: vec.c
    Desc: Vector math.

    Copyright (C) 2024-2025 Gabriel Grigoleto Cunha
*/
#include "vec.h"

//------------------------------------------------------------
// vec2
vec2_t vec2_add(vec2_t a, vec2_t b) {
    return (vec2_t) { a.x + b.x, a.y + b.y };
}

vec2_t vec2_sub(vec2_t a, vec2_t b) {
    return (vec2_t) { a.x - b.x, a.y - b.y };
}

vec2_t vec2_mul(vec2_t a, vec2_t b) {
    return (vec2_t) { a.x* b.x, a.y* b.y };
}

vec2_t vec2_div(vec2_t a, vec2_t b) {
    return (vec2_t) { a.x / b.x, a.y / b.y };
}

//------------------------------------------------------------
// vec3
vec3_t vec3_add(vec3_t a, vec3_t b) {
    return (vec3_t) { a.x + b.x, a.y + b.y, a.z + b.z };
}

vec3_t vec3_sub(vec3_t a, vec3_t b) {
    return (vec3_t) { a.x - b.x, a.y - b.y, a.z - b.z };
}

vec3_t vec3_mul(vec3_t a, vec3_t b) {
    return (vec3_t) { a.x* b.x, a.y* b.y, a.z* b.z };
}

vec3_t vec3_div(vec3_t a, vec3_t b) {
    return (vec3_t) { a.x / b.x, a.y / b.y, a.z / b.z };
}

//------------------------------------------------------------
// vec4
vec4_t vec4_add(vec4_t a, vec4_t b) {
    return (vec4_t) { a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w };
}

vec4_t vec4_sub(vec4_t a, vec4_t b) {
    return (vec4_t) { a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w };
}

vec4_t vec4_mul(vec4_t a, vec4_t b) {
    return (vec4_t) { a.x* b.x, a.y* b.y, a.z* b.z, a.w* b.w };
}

vec4_t vec4_div(vec4_t a, vec4_t b) {
    return (vec4_t) { a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w };
}

//------------------------------------------------------------
// projection
vec2_t project_ortho(vec3_t a) {
    return (vec2_t) { a.x, a.y };
}

vec2_t project_linear(vec3_t a) {
    return (vec2_t) { a.x / a.z, a.y / a.z };
}