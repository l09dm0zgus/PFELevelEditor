#include "renderer.h"
Renderer::Renderer(QWidget *parent)
    :QOpenGLWidget{parent}
{

}

void Renderer::initializeGL()
{
    glewInit();
    glClearColor(0,0,0,1);
    glEnable(GL_DEPTH_TEST);
    glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
}
void Renderer::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
        glColor3f(1.0,0.0,0.0);
        glVertex3f(-0.5,-0.5,0);
        glColor3f(0.0,1.0,0.0);
        glVertex3f(0.5,-0.5,0.0);
        glColor3f(0.0,0.0,1.0);
        glVertex3f(0.0,05,0.0);
    glEnd();
}
void Renderer::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluPerspective(45,(float)w/h,0.01,100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //gluLookAt(0,0,5,0,0,0,0,1,0);

}
