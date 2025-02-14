/*
    File: shader.c
    Desc: Shaders!

    Copyright (C) 2024-2025 Gabriel Grigoleto Cunha
*/
#include "shader.h"

GLuint shader_compile(GLuint sh_type, char* sh_src) {
    GLuint sh;
    int success;
    char info_log[512];

    sh = glCreateShader(sh_type);
    glShaderSource(sh, 1, (const GLchar**)&sh_src, 0);
    glCompileShader(sh);

    glGetShaderiv(sh, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(sh, 512, 0, info_log);

        switch (sh_type) {
        case GL_VERTEX_SHADER:
            printf("ERROR:SHADER::VERTEX::COMPILE_ERROR: %s\n", info_log);
            break;
        case GL_FRAGMENT_SHADER:
            printf("ERROR:SHADER::FRAGMENT::COMPILE_ERROR: %s\n", info_log);
            break;
        }
    }

    return sh;
}

GLuint shader_make_program(GLuint vs, GLuint fs) {
    GLuint sh_program;

    sh_program = glCreateProgram();
    glAttachShader(sh_program, vs);
    glAttachShader(sh_program, fs);
    glLinkProgram(sh_program);
    return sh_program;
}