/*
    File: utils.c
    Desc: Simple utility functions. Not SDL2/OpenGL dependant.

    Copyright (C) 2024-2025 Gabriel Grigoleto Cunha
*/
#include "utils.h"

int utils_get_file_size(const char* path) {
    int sz;
    FILE* f;

    fopen_s(&f, path, "rb");

    fseek(f, 0, SEEK_END);
    sz = ftell(f);
    rewind(f);

    fclose(f);
    return sz;
}

void utils_read_file_bin(char* dest, const char* path) {
    int sz;
    FILE* f;

    fopen_s(&f, path, "rb");

    fseek(f, 0, SEEK_END);
    sz = ftell(f);
    rewind(f);

    fread_s(dest, sz, 1, sz, f);
    dest[sz] = '\0';

    fclose(f);
}

void* utils_alloc(size_t size) {
    return malloc(size);
}

void utils_free(void* buff) {
    free(buff);
}