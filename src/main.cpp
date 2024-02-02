#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>
#include <cstddef>

int main(int argc, const char **argv) {

  if(!(glfwInit())) {
    std::cout << "GLFW: failed to initialise.\n" << std::flush;
    return EXIT_FAILURE;
  }

  GLFWwindow *win = glfwCreateWindow(500, 500, "SmallRenderer", NULL, NULL);

  if(!(win)) {
    std::cout << "GLFW: failed to create window.\n" << std::flush;
    glfwTerminate();
    return EXIT_FAILURE;
  }

  glfwMakeContextCurrent(win);
  gladLoadGL(glfwGetProcAddress);
  glfwSwapInterval(1);

  while(!(glfwWindowShouldClose(win))) {

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(-0.5f, 0.5f);
    glVertex2f(0.5f, -0.5f);
    glEnd();

    glfwSwapBuffers(win);
    glfwPollEvents();
  }

  glfwDestroyWindow(win);
  glfwTerminate();
  return EXIT_SUCCESS;
}
