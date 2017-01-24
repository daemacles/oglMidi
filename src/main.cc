#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main(int argc, char **argv) {
  // DELETE THESE.  Used to suppress unused variable warnings.
  (void)argc;
  (void)argv;

  if (!glfwInit())
  {
      return -1;
  }

  glfwSetErrorCallback(error_callback);

  GLFWwindow* window = glfwCreateWindow(640, 480, "oglMidi", NULL, NULL);
  if (!window)
  {
      // Window or OpenGL context creation failed
  }
  glfwMakeContextCurrent(window);
  gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
  glfwSetKeyCallback(window, key_callback);

  std::cout << "oglMidi running..." << std::endl;

  glfwSwapInterval(1);

  while (!glfwWindowShouldClose(window))
  {
      glfwPollEvents();

      // Keep running
      int width, height;
      glfwGetFramebufferSize(window, &width, &height);
      glViewport(0, 0, width, height);

      glfwSwapBuffers(window);
  }

  glfwTerminate();
  return 0;
}
