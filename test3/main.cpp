//#pragma comment(lib,"libGLEW.a")

#include <GL/glew.h>

#include "textfile.h"

#include <glut/glut.h>
#include <iostream>

// GL includes
#include "Shader.h"

#include <GLFW/glfw3.h>
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define GLEW_STATIC


//GLuint gProgram;
//
//GLuint vShader,fShader;//顶点着色器对象
//// Properties
//GLuint screenWidth = 800, screenHeight = 600;
//
//// Function prototypes
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
//
//
//int main(int argc, char **argv)
//{
//    
////    QSurfaceFormat glFormat;
////    glFormat.setVersion(3, 3);
////    glFormat.setProfile(QSurfaceFormat::CoreProfile);
////    QSurfaceFormat::setDefaultFormat(glFormat);
////    
//
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_3_2_CORE_PROFILE );
////    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
//    
//  
//    
//    glfwInit();
//    GLFWwindow* window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
//    glfwMakeContextCurrent(window);
//    glewInit();
//    //    GLuint initShader();
////    initShader(,);
////    initShader("basic.vert","basic.frag");
//
//    Shader shader("basic.vert", "basic.frag");
//    while (!glfwWindowShouldClose(window))
//    {
//        float ratio;
//        int width, height;
//        glfwGetFramebufferSize(window, &width, &height);
//        ratio = width / (float)height;
//        glViewport(0, 0, width, height);
//        glClear(GL_COLOR_BUFFER_BIT);
//        glMatrixMode(GL_PROJECTION);
//        glLoadIdentity();
//        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
//        glMatrixMode(GL_MODELVIEW);
//        glLoadIdentity();
//        
////        glUseProgram(gProgram);
//        
//        glfwPollEvents();
//        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//        
//        shader.Use();
//        
//        glBegin(GL_TRIANGLES);
//        glVertex3f(-0.6f, -0.4f, 0.f);
//        glVertex3f(0.6f, -0.4f, 0.f);
//        glVertex3f(0.f, 0.6f, 0.f);
//        
//        
//        
//        glEnd();
//        glUseProgram(0);
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//    
//    glfwTerminate();
//    return 0;
//}
//

//----------------
//#include <iostream>
//
//// GLEW
//#define GLEW_STATIC
//#include <GL/glew.h>
//
//// GLFW
//#include <GLFW/glfw3.h>
//

// Function prototypes
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

// Window dimensions
//const GLuint WIDTH = 800, HEIGHT = 600;

// Shaders
//const GLchar* vertexShaderSource = "#version 120\n"
//"layout (location = 0) in vec3 position;\n"
//"void main()\n"
//"{\n"
//"gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
//"}\0";
//const GLchar* fragmentShaderSource = "#version 120\n"
//"out vec4 color;\n"
//"void main()\n"
//"{\n"
//"color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//"}\n\0";


// The MAIN function, from here we start the application and run the game loop
int main(int argc, char **argv)
{
//    glutInit(&argc, argv);
    // Init GLFW
    glfwInit();
    
    glfwWindowHint (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    // Set all the required options for GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    
    // Create a GLFWwindow object that we can use for GLFW's functions
//    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
    GLFWwindow* window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    glfwMakeContextCurrent(window);
    
    // Set the required callback functions
//    glfwSetKeyCallback(window, key_callback);
    
    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
    glewExperimental = GL_TRUE;
    // Initialize GLEW to setup the OpenGL Function pointers
    
//    #ifndef __APPLE__
    glewInit();
//    #endif
    
//    glewInit();
    
    // Define the viewport dimensions
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
    
   Shader shader("basic.vert", "basic.frag");
//     Shader shader(vertexShaderSource, fragmentShaderSource);
//
//    // Build and compile our shader program
//    // Vertex shader
//    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//    glCompileShader(vertexShader);
//    // Check for compile time errors
//    GLint success;
//    GLchar infoLog[512];
//    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//    if (!success)
//    {
//        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//    // Fragment shader
//    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//    glCompileShader(fragmentShader);
//    // Check for compile time errors
//    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//    if (!success)
//    {
//        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//    // Link shaders
//    GLuint shaderProgram = glCreateProgram();
//    glAttachShader(shaderProgram, vertexShader);
//    glAttachShader(shaderProgram, fragmentShader);
//    glLinkProgram(shaderProgram);
//    // Check for linking errors
//    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//    if (!success) {
//        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//    }
//    glDeleteShader(vertexShader);
//    glDeleteShader(fragmentShader);
//    
    
    // Set up vertex data (and buffer(s)) and attribute pointers
    GLfloat vertices[] = {
        -0.5f, -0.5f, 0.0f, // Left
        0.5f, -0.5f, 0.0f, // Right
        0.0f,  0.5f, 0.0f  // Top
    };
    GLuint VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind
    
    glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)
    
    
//     Shader shader("vertexShaderSource", "fragmentShaderSource");
    
    // Game loop
    while (!glfwWindowShouldClose(window))
    {
        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();
        
        // Render
        // Clear the colorbuffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        // Draw our first triangle
//        glUseProgram(shaderProgram);
        shader.Use();
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);
        
        // Swap the screen buffers
        glfwSwapBuffers(window);
    }
    // Properly de-allocate all resources once they've outlived their purpose
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    // Terminate GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();
    return 0;
}

