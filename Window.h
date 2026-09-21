#pragma once
#include <SDL3/SDL.h>
#include <iostream>



struct SDLWindowDeleter{
    

    void operator()(SDL_Window* ptr) const 
    {
        if (ptr && SDL_WasInit(0))
        {
            SDL_DestroyWindow(ptr);
        }

    }



};


using UniqueSDLWindow = std::unique_ptr<
    SDL_Window, SDLWindowDeleter
>;




class Window {
public:
  Window() {
    
    SDL_Window* winptr = SDL_CreateWindow(
        "Smart ptr window",
        800, 600, SDL_WINDOW_RESIZABLE
    );


    using UniqueSDLWindow = std::unique_ptr<
    SDL_Window, SDLWindowDeleter
    >;

    

    SDLWindow = UniqueSDLWindow(winptr);

    }
  SDL_Window* GetRaw() const {
    return SDLWindow.get();
  }

  void Render() {
    const auto* Fmt = SDL_GetPixelFormatDetails(
      GetSurface()->format
    );

    SDL_FillSurfaceRect(
      GetSurface(),
      nullptr,
      SDL_MapRGB(Fmt, nullptr, 50, 50, 50)
    );
  }

  void Update() {
    SDL_UpdateWindowSurface(GetRaw());
  }

  SDL_Surface* GetSurface() const {
    return SDL_GetWindowSurface(GetRaw());
  }




private:
  UniqueSDLWindow SDLWindow{nullptr};
};