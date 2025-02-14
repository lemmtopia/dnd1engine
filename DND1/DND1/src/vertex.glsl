#version 330 core

layout (location = 0) in vec3 a_pos;
layout (location = 1) in vec3 a_col;

out vec3 our_col;

uniform vec3 u_offset;
uniform mat4 u_view;
uniform mat4 u_model;
uniform mat4 u_perspective;

void main() {
    gl_Position = u_perspective * u_view * u_model * vec4(
        u_offset.x + a_pos.x,
        u_offset.y + a_pos.y,
        u_offset.z + a_pos.z,
        1.0); 

    our_col = a_col;
}