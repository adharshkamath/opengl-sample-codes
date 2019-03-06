// sample program for simple animation of rotating square

#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <math.h> 

const float step = 0.01;
float angle = 0;

/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    angle = fmod(angle+step, 360.0f); //angle of rotation
    glRotatef(angle, 0.0f, 0.0f, 1.0f); //rotates the coordinate system perpendicular to the given vector
    // Draw a Red 1x1 Square centered at origin
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
      glColor3f(1.0f, 0.0f, 0.0f); // Red
      glVertex2f(-0.5f, -0.5f);    // x, y
      glVertex2f( 0.5f, -0.5f);
      glVertex2f( 0.5f,  0.5f);
      glVertex2f(-0.5f,  0.5f);
    glEnd();
 
   glutSwapBuffers(); //to precompute the next frame
   //glFlush();  // Render now
}
 
/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
   glutInit(&argc, argv);                 // Initialize GLUT
   glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
   glutInitDisplayMode(GLUT_DOUBLE);
   glutInitWindowSize(320, 320);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutDisplayFunc(display); // Register display callback handler for window re-paint
   glutIdleFunc(display); // Register display callback handler when window is idle
   glutMainLoop();           // Enter the event-processing loop
   return 0;
}
