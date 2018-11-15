#include<SDL.h>

bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
void render();
void update() {};
void handleEvents() {};
void clean() {};

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;
bool g_bRunning = false;

int main(int argc, char* argv[])
{
	if (init("Chapter02. BreakHello", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN)) {
		bool g_bRunning = true;
	}
	else { return 1; }
	while (g_bRunning) {
		render();
	}
	clean();

	SDL_Quit();

	return 0;
}

bool init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		g_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (g_pWindow != 0)
		{
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}
	}
	else {
		return false;
	}
	return true;
}
void render()
{
	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

	SDL_RenderClear(g_pRenderer);

	SDL_RenderPresent(g_pRenderer);
}
