#version 330 core

out vec4 frag_color;
in vec3 our_col;

void main() {
    frag_color = vec4(our_col, 1.0);
}