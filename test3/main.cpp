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


GLuint gProgram;

GLuint vShader,fShader;//顶点着色器对象
// Properties
GLuint screenWidth = 800, screenHeight = 600;

// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);


//
//void initShader(const char *VShaderFile,const char *FShaderFile)
//{
//    //1、查看GLSL和OpenGL的版本
//    const GLubyte *renderer = glGetString( GL_RENDERER );
//    const GLubyte *vendor = glGetString( GL_VENDOR );
//    const GLubyte *version = glGetString( GL_VERSION );
//    const GLubyte *glslVersion =
//    glGetString( GL_SHADING_LANGUAGE_VERSION );
//    GLint major, minor;
//    glGetIntegerv(GL_MAJOR_VERSION, &major);
//    glGetIntegerv(GL_MINOR_VERSION, &minor);
//    cout << "GL Vendor    :" << vendor << endl;
//    cout << "GL Renderer  : " << renderer << endl;
//    cout << "GL Version (string)  : " << version << endl;
//    cout << "GL Version (integer) : " << major << "." << minor << endl;
//    cout << "GLSL Version : " << glslVersion << endl;
//    
//    //2、编译着色器
//    //创建着色器对象：顶点着色器
//    vShader = glCreateShader(GL_VERTEX_SHADER);
//    //错误检测
//    if (0 == vShader)
//    {
//        cerr << "ERROR : Create vertex shader failed" << endl;
//        exit(1);
//    }
//    
//    //把着色器源代码和着色器对象相关联
//    const GLchar *vShaderCode = textFileRead(VShaderFile);
//    const GLchar *vCodeArray[1] = {vShaderCode};
//    glShaderSource(vShader,1,vCodeArray,NULL);
//    
//    //编译着色器对象
//    glCompileShader(vShader);
//    
//    
//    //检查编译是否成功
//    GLint compileResult;
//    glGetShaderiv(vShader,GL_COMPILE_STATUS,&compileResult);
//    if (GL_FALSE == compileResult)
//    {
//        GLint logLen;
//        //得到编译日志长度
//        glGetShaderiv(vShader,GL_INFO_LOG_LENGTH,&logLen);
//        if (logLen > 0)
//        {
//            char *log = (char *)malloc(logLen);
//            GLsizei written;
//            //得到日志信息并输出
//            glGetShaderInfoLog(vShader,logLen,&written,log);
//            cerr << "vertex shader compile log : " << endl;
//            cerr << log << endl;
//            free(log);//释放空间
//        }
//    }
//    
//    //创建着色器对象：片断着色器
//    fShader = glCreateShader(GL_FRAGMENT_SHADER);
//    //错误检测
//    if (0 == fShader)
//    {
//        cerr << "ERROR : Create fragment shader failed" << std::endl;
//        exit(1);
//    }
//    
//    //把着色器源代码和着色器对象相关联
//    const GLchar *fShaderCode = textFileRead(FShaderFile);
//    const GLchar *fCodeArray[1] = {fShaderCode};
//    glShaderSource(fShader,1,fCodeArray,NULL);
//    
//    //编译着色器对象
//    glCompileShader(fShader);
//    
//    //检查编译是否成功
//    glGetShaderiv(fShader,GL_COMPILE_STATUS,&compileResult);
//    if (GL_FALSE == compileResult)
//    {
//        GLint logLen;
//        //得到编译日志长度
//        glGetShaderiv(fShader,GL_INFO_LOG_LENGTH,&logLen);
//        if (logLen > 0)
//        {
//            char *log = (char *)malloc(logLen);
//            GLsizei written;
//            //得到日志信息并输出
//            glGetShaderInfoLog(fShader,logLen,&written,log);
//            std::cerr << "fragment shader compile log : " << endl;
//            cerr << log << endl;
//            free(log);//释放空间
//        }
//    }
//    
//    //3、链接着色器对象
//    //创建着色器程序
//    GLuint programHandle = glCreateProgram();
//    if (!programHandle)
//    {
//        cerr << "ERROR : create program failed" << endl;
//        exit(1);
//    }
//    //将着色器程序链接到所创建的程序中
//    glAttachShader(programHandle,vShader);
//    glAttachShader(programHandle,fShader);
//    //将这些对象链接成一个可执行程序
//    glLinkProgram(programHandle);
//    //查询链接的结果
//    GLint linkStatus;
//    glGetProgramiv(programHandle,GL_LINK_STATUS,&linkStatus);
//    if (GL_FALSE == linkStatus)
//    {
//        cerr << "ERROR : link shader program failed" << endl;
//        GLint logLen;
//        glGetProgramiv(programHandle,GL_INFO_LOG_LENGTH,
//                       &logLen);
//        if (logLen > 0)
//        {
//            char *log = (char *)malloc(logLen);
//            GLsizei written;
//            glGetProgramInfoLog(programHandle,logLen,
//                                &written,log);
//            cerr << "Program log : " << endl;
//            cerr << log << endl;
//        }
//    }
//    else//链接成功，在OpenGL管线中使用渲染程序
//    {
//        glUseProgram(programHandle);
//    }
//}


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    glfwMakeContextCurrent(window);
    glewInit();
    //    GLuint initShader();
//    initShader(,);
//    initShader("basic.vert","basic.frag");
//    Shader shader("basic.vert", "basic.frag");
    Shader shader("basic.vert", "basic.frag");
    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        
//        glUseProgram(gProgram);
       shader.Use();
        //    glutSolidTeapot(0.5);
        glBegin(GL_TRIANGLES);
        //        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.6f, -0.4f, 0.f);
        //        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(0.6f, -0.4f, 0.f);
        //        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 0.6f, 0.f);
        glEnd();
        glUseProgram(0);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}
