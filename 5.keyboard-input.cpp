// sample program for key board input

#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;

const float step = 0.01;
float xr = 0, yr = 0;

void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  
    glClear(GL_COLOR_BUFFER_BIT);
   
    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(xr-0.05, yr-0.05);
    glVertex2f(xr+0.05, yr-0.05);
    glVertex2f(xr+0.05, yr+0.05);
    glVertex2f(xr-0.05, yr+0.05);
    glEnd();
    glFlush();
}

void specialkey(int key, int x, int y) {
    
    switch(key) {
        case GLUT_KEY_UP:
            yr += step;
            printf("up %f %f\n", xr, yr);
            break;
        case GLUT_KEY_DOWN:
            yr -= step;
            printf("down %f %f\n", xr, yr);
            break;
        case GLUT_KEY_LEFT:
            xr -= step;
            printf("left %f %f\n", xr, yr);
            break;
        case GLUT_KEY_RIGHT:
            xr += step;
            printf("right %f %f\n", xr, yr);
            break;
    }
    //glutPostRedisplay();
    //glFlush();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("moving");
    
    glutDisplayFunc(display); // on screen repaint
    glutIdleFunc(display); // on screen idle
    glutSpecialFunc(specialkey); // on keyboard input

    glutMainLoop();
    return 0;
}
