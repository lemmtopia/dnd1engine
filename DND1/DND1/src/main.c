/*
	File: main.c
	Desc: Main file

	Copyright (C) 2024-2025 Gabriel Grigoleto Cunha
*/

#include "defs.h"
#include "window.h"
#include "renderer.h"

boolean is_running = FALSE;

#include <math.h>

float time;

vec3_t my_offset = { 0, 0, 0 };

int last_ticks = 0;
float dt;

void game_initialize(void) {
	renderer_set_clear_color(0.1, 0.2, 0.3);

	render_vertex_t v[] = {
		{ 0.5f,  0.5f, 0.0f,     1.0f, 0.0f, 0.0f, },
		{ 0.5f, -0.5f, 0.0f,     0.0f, 1.0f, 0.0f, },
		{-0.5f,  0.5f, 0.0f,     1.0f, 0.5f, 0.5f, }
	};
	renderer_push_triangle(&global_renderer, v);

	render_vertex_t v2[] = {
		{ 0.5f, -0.5f, 0.0f,     0.0f, 1.0f, 0.0f, },
		{-0.5f, -0.5f, 0.0f,     0.0f, 0.0f, 1.0f, },
		{-0.5f,  0.5f, 0.0f,     1.0f, 0.5f, 0.5f, }
	};
	renderer_push_triangle(&global_renderer, v2);


	// Send the data when we are ready
	renderer_send_data(&global_renderer);

	last_ticks = SDL_GetTicks();
}

void game_update(void) {
	dt = (SDL_GetTicks() - last_ticks) / 1000.0f;
	last_ticks = SDL_GetTicks();

	time += dt;

	float* m0 = mat4_rotate_x(time);
	float* m1 = mat4_rotate_y(time);
	float* m2 = mat4_rotate_z(time);

	float* mat = mat4_mul(m0, mat4_mul(m1, m2));

	for (int i = 0; i < MAT4_SIZE; i++) {
		global_renderer.model[i] = mat[i];
	}

	const u8* kb_state = SDL_GetKeyboardState(0);

	my_offset.x += dt * (kb_state[SDL_SCANCODE_D] - kb_state[SDL_SCANCODE_A]);
	my_offset.y += dt * (kb_state[SDL_SCANCODE_W] - kb_state[SDL_SCANCODE_S]);

	renderer_set_offset(&global_renderer, my_offset);

	utils_free(mat);
	utils_free(m0);
	utils_free(m1);
	utils_free(m2);
}

void game_render(void) {
	// Set clear color
	renderer_clear();

	renderer_draw_arrays(global_renderer);

	window_swap_buffers();
}

int main(int argc, char* argv[]) {
	is_running = window_initialize();

	if (is_running) {
		// mainloop
		game_initialize();
		while (is_running) {
			game_update();
			game_render();

			is_running = !window_should_close();
		}

		window_destroy(); // quit only if we have entered
	}

	return 0;
}