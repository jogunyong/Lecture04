//https://www.glfw.org/
#pragma comment(lib, "Opengl32.lib")
#include <GLFW/glfw3.h>
#include <iostream>
void errorCallback(int error, const char* description)
{
    std::cerr << "GLFW Error: " << description << std::endl;
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    double xPos, yPos;
    glfwGetCursorPos(window, &xPos, &yPos);

    if (button == GLFW_MOUSE_BUTTON_RIGHT)
    {
        if (action == GLFW_PRESS)
            glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // 빨간색
        else if (action == GLFW_RELEASE)
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // 원상복구
    }
    else if (button == GLFW_MOUSE_BUTTON_LEFT)
    {
        if (action == GLFW_PRESS)
            glClearColor(0.0f, 1.0f, 0.0f, 1.0f); // 녹색
        else if (action == GLFW_RELEASE)
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // 원상복구
    }
}

void cursorPositionCallback(GLFWwindow* window, double xPos, double yPos)
{
    int rightButtonState = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT);
    int leftButtonState = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);

    if (rightButtonState == GLFW_PRESS)
    {
        glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // 파란색
    }
    else if (leftButtonState == GLFW_PRESS)
    {
        glClearColor(1.0f, 0.0f, 1.0f, 1.0f); // 마젠타색
    }
    else
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // 원상복구
    }
}

int main(void)
{
    if (!glfwInit())
        return -1;

    GLFWwindow* window;
    window = glfwCreateWindow(1280, 768, "MuSoeunEngine", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetCursorPosCallback(window, cursorPositionCallback);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
