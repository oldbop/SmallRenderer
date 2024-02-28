#include <Cute/Vec3f.h>
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char **argv) {

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

  Cute_Vec3f v1 = Cute_MakeVec3f(5.0f, 4.0f, 3.0f);
  Cute_Vec3f v2 = Cute_MakeVec3f(6.0f, 7.0f, 9.0f);

  Cute_Vec3f cross = Cute_CrossVec3f(&v1, &v2);

  Cute_PrintVec3f(&cross);

  glfwMakeContextCurrent(win);
  gladLoadGL(glfwGetProcAddress);
  glfwSwapInterval(1);

  while(!(glfwWindowShouldClose(win))) {

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, -1.0f);
    glEnd();

    glfwSwapBuffers(win);
    glfwPollEvents();
  }

  glfwDestroyWindow(win);
  glfwTerminate();
  return EXIT_SUCCESS;
}
