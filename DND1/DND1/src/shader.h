/*
    File: shader.h
    Desc: Shaders!

    Copyright (C) 2024-2025 Gabriel Grigoleto Cunha
*/
#ifndef SHADER_H
#define SHADER_H

#include "defs.h"

#include <stdio.h>

GLuint shader_compile(GLuint sh_type, char* sh_src);
GLuint shader_make_program(GLuint vs, GLuint fs);

#endif