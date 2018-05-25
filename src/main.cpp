/**
 * Compile: g++ -o main.deb src/main.cpp -lGL -lGLEW -lglfw
 */

#include <iostream>      // std::cout, std::endl, std::cerr
#include <fstream>       // std::ifstream
#include <sstream>       // std::stringstream
#include <streambuf>     // std::istreambuf_iterator
#include <sys/timeb.h>   // ftime (to implement timestamp())
#include <algorithm>     // std::min
#include <GL/glew.h>     // GLEW
#include <GLFW/glfw3.h>  // Use GLFW to create a window
#include <GL/freeglut.h> // OpenGL
#include "v6/v6.h"       // v6.js implementation
#include "v6/Ticker.h"
#include "v6/Shader.h"
#include "v6/Program.h"
#include "v6/RendererGL.h"

float r = 0.0f,
      g = 0.0f,
      b = 0.0f;

class Ticker : public v6::Ticker {
 public:
  void update ( float );
  void render ( float );
};

class Minecraft {
 public:
  Minecraft ()
  {
    renderer = new v6::RendererGL( 640, 480, "Minecraft" );

    v6::Shader v( GL_VERTEX_SHADER ),
               f( GL_FRAGMENT_SHADER );

    v.load( "shaders/v.glsl" );
    f.load( "shaders/f.glsl" );

    renderer->shaders( v, f );

    ticker = new Ticker();

    ticker->tick();
  }

  v6::RendererGL* renderer;
  Ticker* ticker;
};

Minecraft* minecraft;

void Ticker::update ( float dt )
{

}

void Ticker::render ( float dt )
{
  glClearColor( r, g, b, 1.0f );
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glfwSwapBuffers( minecraft->renderer->window );
}

int main ( int argc, char** argv )
{

  minecraft = new Minecraft();

  return 0;

}
