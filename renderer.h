#ifndef RENDERER_H
#define RENDERER_H
#include<GL/glew.h>
#include <GL/glu.h>
#include <QOpenGLWidget>
class Renderer : public QOpenGLWidget
{
public:
    Renderer(QWidget *parent = 0);
protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
};

#endif // RENDERER_H
