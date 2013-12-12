#include <iostream>

#include <cbtde.hpp>

const GLfloat RED[3] = {1.0f, 0, 0};
const GLfloat BLUE[3] = {0, 0, 1.0f};

int main(void)
{
    GameApp *app = &GameApp::getInstance();
    GameObject go;
    app->setRootGO(&go);
    Circle circleComp(.1f, (GLfloat*)RED);
    Circle circleComp2(.09f, (GLfloat*)BLUE);

    go.addCompontent(&circleComp);
    go.addCompontent(&circleComp2);
    go.addCompontent([&] () {
      glBegin(GL_QUADS);
        glVertex2d(0,0);
        glVertex2d(1,0);
        glVertex2d(1,1);
        glVertex2d(0,1);
      glEnd();
    });

    app->run();
}
