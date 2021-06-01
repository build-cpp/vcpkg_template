#include <SDL.h>

#ifdef __cplusplus
extern "C"
#endif
int main(int argc, char* argv[])
{
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
		"Hello World",
		"You have successfully compiled and linked an SDL2 program, congratulations.",
		nullptr
	);

	return EXIT_SUCCESS;
}