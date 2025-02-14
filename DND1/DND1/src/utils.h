/*
    File: utils.h
    Desc: Simple utility functions. Not SDL2/OpenGL dependant.

    Copyright (C) 2024-2025 Gabriel Grigoleto Cunha
*/
#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int utils_get_file_size(const char* path);
void utils_read_file_bin(char* dest, const char* path);

void* utils_alloc(size_t size);
void utils_free(void* buff);

#endif