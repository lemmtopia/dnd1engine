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

int last_ticks = 0;
float dt;

void initialize_game(void) {
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

void update_game(void) {
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

	utils_free(mat);
	utils_free(m0);
	utils_free(m1);
	utils_free(m2);
}

void render_game(void) {
	//SDL_RenderClear(renderer);

	//char* pixels;
	//int pitch;

	//SDL_LockTexture(framebuffer, 0, (void**)&pixels, &pitch);

	//// clear screen
	//for (int i = 0; i < WIDTH * HEIGHT; i++) {
	//	char* pixel = pixels + (i * 4);

	//	*pixel = 0xff;
	//	*(pixel + 1) = 0x00;
	//	*(pixel + 2) = 0xff;
	//	*(pixel + 3) = 0xff;
	//}

	//SDL_UnlockTexture(framebuffer);

	//SDL_RenderTexture(renderer, framebuffer, NULL, NULL);
	//SDL_RenderPresent(renderer);

	// Set clear color
	renderer_clear();

	renderer_draw_arrays(global_renderer);

	swap_window_buffers();
}

int main(int argc, char* argv[]) {
	is_running = initialize_window();

	if (is_running) {
		// mainloop
		initialize_game();
		while (is_running) {
			update_game();
			render_game();

			is_running = !window_should_close();
		}

		destroy_window(); // quit only if we have entered
	}

	return 0;
}