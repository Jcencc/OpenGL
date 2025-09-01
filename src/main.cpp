#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <GLFW/glfw3.h>
#include <iostream>


const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    // 更新投影矩阵
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)width / (float)height, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

// 绘制三角形函数
void drawTriangle() {
    // 开始绘制三角形（使用GL_TRIANGLES图元）
    glBegin(GL_TRIANGLES);

    // 第一个顶点（红色）
    glColor3f(1.0f, 0.0f, 0.0f);   // 设置颜色为红色
    glVertex3f(-1.0f, -1.0f, -5.0f); // 坐标（x, y, z）

    // 第二个顶点（绿色）
    glColor3f(0.0f, 1.0f, 0.0f);   // 设置颜色为绿色
    glVertex3f(1.0f, -1.0f, -5.0f);  // 坐标

    // 第三个顶点（蓝色）
    glColor3f(0.0f, 0.0f, 1.0f);   // 设置颜色为蓝色
    glVertex3f(0.0f, 1.0f, -5.0f);   // 坐标

    glEnd(); // 结束绘制
}

void render() {
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f); // 灰色背景
    glClear(GL_COLOR_BUFFER_BIT);         // 清除颜色缓冲区

    glLoadIdentity();                    // 重置模型视图矩阵
    drawTriangle();                      // 调用绘制三角形函数
}

int main() {
    // 初始化GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW!" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    GLFWwindow* window = glfwCreateWindow(
        SCR_WIDTH, SCR_HEIGHT,
        "OpenGL Triangle Example",
        NULL, NULL
    );
    if (!window) {
        std::cerr << "Failed to create GLFW window!" << std::endl;
        glfwTerminate();
        return -1;
    }

    // 设置当前OpenGL上下文
    glfwMakeContextCurrent(window);
    // 注册窗口大小改变回调
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // 启用平滑着色（使颜色过渡更自然）
    glShadeModel(GL_SMOOTH);

    // 初始化OpenGL固定管线
    glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);

    // 主循环
    while (!glfwWindowShouldClose(window)) {
        render();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
