/*
	File: window.c
	Desc: Platform application instance handling

	Copyright (C) 2024-2025 Gabriel Grigoleto Cunha
*/
#include "window.h"
#include "renderer.h"

SDL_Window* window;
SDL_GLContext gl_context;

extern renderer_t global_renderer;

boolean window_initialize(void) {
	if (!SDL_Init(SDL_INIT_VIDEO)) { // now 0 is failure, bitches
		return FALSE;
	}

	window = SDL_CreateWindow("DND1", WIDTH, HEIGHT, SDL_WINDOW_OPENGL);

	if (!window) {
		return FALSE;
	}

	/*renderer = SDL_CreateRenderer(window, 0);

	if (!renderer) {
		return FALSE;
	}

	framebuffer = SDL_CreateTexture(
		renderer,
		SDL_PIXELFORMAT_ABGR8888,
		SDL_TEXTUREACCESS_STREAMING,
		WIDTH,
		HEIGHT);*/

		/*if (!framebuffer) {
			return FALSE;
		}*/

		// Set OpenGL version (3.3 core)
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	// Create GL context
	gl_context = SDL_GL_CreateContext(window);

	if (!gl_context) {
		return FALSE;
	}

	if (glewInit() != GLEW_OK) {
		return FALSE;
	}

	SDL_GL_MakeCurrent(window, gl_context);

	renderer_init(&global_renderer);

	return TRUE;
}

boolean window_should_close(void) {
	SDL_Event ev;
	SDL_PollEvent(&ev);

	return ev.type == SDL_EVENT_QUIT;
}

void window_destroy(void) {
	SDL_GL_DestroyContext(gl_context);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void window_swap_buffers(void) {
	// Update window by swapping buffers
	SDL_GL_SwapWindow(window);
}