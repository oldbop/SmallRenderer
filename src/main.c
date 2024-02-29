#ifdef SYS_GL_HEADERS
  #include <GL/gl.h>
  #include <GLFW/glfw3.h>

  void loadGL() {}
#else
  #include <glad/gl.h>
  #include <GLFW/glfw3.h>

  void loadGL() {
    gladLoadGL(glfwGetProcAddress);
  }
#endif

#include <Cute/Vec3f.h>

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char **argv) {

  int32_t width, height;
  uint32_t texture;
  float ratio;

  if(!(glfwInit())) {
    printf("GLFW: failed to initialise.\n");
    return EXIT_FAILURE;
  }

  GLFWwindow *win = glfwCreateWindow(500, 500, "SmallRenderer", NULL, NULL);

  if(!(win)) {
    printf("GLFW: failed to create window.\n");
    glfwTerminate();
    return EXIT_FAILURE;
  }

  glfwMakeContextCurrent(win);
  loadGL();
  glfwSwapInterval(1);

  //glGenTextures(1, &texture);
  //glBindTexture(GL_TEXTURE_2D, texture);

  while(!(glfwWindowShouldClose(win))) {

    glfwGetFramebufferSize(win, &width, &height);
    ratio = width / (float) height;

    glViewport(0, 0, width, height);
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
