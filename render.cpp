#include <iostream>
#include "draw.h"

void idle()
{
    rotation('x', 0.01);
    rotation('y', 0.01);
    rotation('z', 0.01);
    //scalarization(0.01, 0.01, 0.01);
    OnDisplay();
}

int main(int argc, char **argv)
{
    Display *d;
    Window w;
    XEvent e;
    int s;
    int r, g, b;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(windowW, windowH);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Mu He");

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glShadeModel(GL_FLAT);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    cameraInitialization();

    scalarization(0.6, .6, .6);

    rotation('y', 3* M_PI / 12);
    rotation('x', 3*M_PI  / 12);

    //-- run the program
    glutDisplayFunc(OnDisplay);
    glutKeyboardFunc(OnKeyboard);
    glutIdleFunc(idle);
    glutMainLoop();
    delete_dmatrix(&C);
    return 0;
}
