#include <windows.h>
#include <GL/glut.h>

float i = 0.0f;
float minutes = 0.0f;
float hour=0.0f;
void initGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.9f,- 0.5f);
    glVertex2f(0.9f,- 0.5f);
    glVertex2f(0.9f, 0.5f);
    glVertex2f(-0.9f, 0.5f);

    glEnd();

  //  glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-0.01f,0.4f);
    glVertex2f(-0.01f,0.5f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-0.9f,0.0f);
    glVertex2f(-0.7f,0.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.9f,0.0f);
    glVertex2f(0.7f,0.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-0.0f,-0.5f);
    glVertex2f(-0.0f,-0.4f);
    glEnd();





    glLoadIdentity();//Reset the current matrix

    glPushMatrix(); //glPushMatrix copies the top matrix and pushes it onto the stack, while glPopMatrix pops the top matrix off the stack
    glRotatef(-i,0.0,0.0,0.1);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.01f, 0.3f);
    glVertex2f(-0.01f, 0.3f);
    glEnd();
    glPopMatrix();


    glLoadIdentity();

    glPushMatrix();
    glRotatef(-minutes,0.0,0.0,0.1);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.01f, 0.4f);
    glVertex2f(-0.01f, 0.4f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-hour,0.0,0.0,0.1);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.01f, 0.45f);
    glVertex2f(-0.01f, 0.45f);
    glEnd();
    glPopMatrix();


        glFlush();








}
void update(int value) {
    i += 6.0f;
    if (i >=360.0) {
        i=0.0;
        minutes+=6.0;
        if(minutes>=360.0)
        {
            minutes=0.0;
            hour+=30.0;
        }

    }

    glutPostRedisplay(); //Tell GLUT that the scene has changed

    //Tell GLUT to call update again in 25 milliseconds
    glutTimerFunc(1000, update, 0);
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);          // Initialize GLUT
    glutInitWindowSize(320, 320);
    glutCreateWindow("clock");
    glutDisplayFunc(display);//
    initGL();
    glutIdleFunc(Idle);//glutIdleFunc sets the global idle callback to be func so a GLUT program can perform background processing tasks or continuous animation when window system events are not being received.
    glutTimerFunc(1000, update, 0);
    glutMainLoop();
    return 0;}
