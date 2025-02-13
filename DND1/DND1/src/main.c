/*
	File: main.c
	Desc: Main file

	Copyright (C) 2024-2025 Gabriel Grigoleto Cunha
*/

#include "defs.h"
#include "window.h"

boolean is_running = FALSE;

void initialize_game(void) {

}

void update_game(void) {

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
	glClearColor(0.1, 0.2, 0.3, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

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