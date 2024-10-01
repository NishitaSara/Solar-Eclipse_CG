#include <GL/glut.h>
#include <math.h>
#include <stdbool.h> 

enum MenuOptions {
    MENU_SPEED_SLOWER,
    MENU_SPEED_FASTER,
    MENU_EXIT
};

const float sunspeed=0.5;
void init() {
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100.0, 100.0, -100.0, 100.0); 
    glMatrixMode(GL_MODELVIEW);
}
void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments; i++) {
        float angle = 2.0f * 3.14159f * i / num_segments;
        float x = r * cos(angle);
        float y = r * sin(angle);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}
void drawBuildings() {
    glColor3f(0.3f, 0.3f, 0.3f); 
    glBegin(GL_QUADS);
    glVertex2f(-90.0f, -100.0f); glVertex2f(-70.0f, -100.0f); glVertex2f(-70.0f, 0.0f); glVertex2f(-90.0f, 0.0f);
    glVertex2f(-60.0f, -100.0f); glVertex2f(-40.0f, -100.0f); glVertex2f(-40.0f, -20.0f); glVertex2f(-60.0f, -20.0f);
    glVertex2f(-30.0f, -100.0f); glVertex2f(-10.0f, -100.0f); glVertex2f(-10.0f, 10.0f); glVertex2f(-30.0f, 10.0f);
    glVertex2f(0.0f, -100.0f); glVertex2f(20.0f, -100.0f); glVertex2f(20.0f, -10.0f); glVertex2f(0.0f, -10.0f);
    glVertex2f(30.0f, -100.0f); glVertex2f(50.0f, -100.0f); glVertex2f(50.0f, 30.0f); glVertex2f(30.0f, 30.0f);
    glVertex2f(60.0f, -100.0f); glVertex2f(80.0f, -100.0f); glVertex2f(80.0f, -30.0f); glVertex2f(60.0f, -30.0f);
    glEnd();
}
void drawBird(float x, float y) {
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(x, y);
    glVertex2f(x + 5.0f, y - 2.0f);
    glVertex2f(x + 5.0f, y - 2.0f);
    glVertex2f(x + 10.0f, y);
    glEnd();
}

void drawCloud(float x, float y, bool isFirstCloud) {
    // Draw the cloud
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(x, y);
    glVertex2f(x + 5.0f, y + 5.0f);
    glVertex2f(x + 5.0f, y + 5.0f);
    glVertex2f(x + 10.0f, y);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(x, y, 10.0f, 100);
    drawCircle(x + 10.0f, y, 10.0f, 100);
    drawCircle(x + 5.0f, y + 5.0f, 10.0f, 100);

    // Move the cloud based on whether it's the first or second cloud
    if (isFirstCloud) {
        cloudX += cloudSpeed; // Move the first cloud
        if (cloudX > 100.0f) {
            cloudX = -100.0f; // Reset position
        }
    } else {
        cloud2X += cloud2Speed; // Move the second cloud in the opposite direction
        if (cloud2X < -100.0f) {
            cloud2X = 100.0f; // Reset position
        }
    }

    // Update bird positions
    birdX1 += birdSpeed1; // Move bird 1 to the right
    if (birdX1 > 100.0f) {
        birdX1 = -100.0f; // Reset position
    }
    drawBird(birdX1, birdY1);

    birdX2 += birdSpeed2; // Move bird 2 to the right
    if (birdX2 > 100.0f) {
        birdX2 = -100.0f; // Reset position
    }
    drawBird(birdX2, birdY2);

    // Move bird 3 in the opposite direction (to the left)
    birdX3 -= birdSpeed3; // Move bird 3 to the left
    if (birdX3 < -100.0f) {
        birdX3 = 100.0f; // Reset position
    }
    drawBird(birdX3, birdY3);
}


void moon()
{

glColor3f(0.2f, 0.2f, 0.2f);
    glTranslatef(moonX, 0.0f, 0.0f);
    drawCircle(0.0f, 0.0f, 20.0f, 100);
    //drawCircle(0.0f, 0.0f, 10.0f, 100);
    
    moonX += moonSpeed;
    if (moonX > 100.0f) {
        moonX = -100.0f; 
    }

    if (moonX > -20.0f && moonX < 20.0f) {
        isDaytime = false; 
    } else {
        isDaytime = true; 
    }

    if (isDaytime) {
        glClearColor(0.5f, 0.8f, 1.0f, 1.0f); 
    } else {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    }
}
void sun()
{
 
glColor3f(1.0f, 1.0f, 0.0f);
    drawCircle(0.0f, 0.0f, 10.0f, 100);
    //drawCircle(0.0f, 0.0f, 20.0f, 100);
    }
void draw_window()
{
glColor3f(1.0f,1.0f,0.0f);
glRecti(-88,-10,-83,-20);
glRecti(-88,-40,-83,-50);
glRecti(-88,-70,-83,-80);
glRecti(-78,-10,-73,-20);
glRecti(-78,-40,-73,-50);
glRecti(-78,-70,-73,-80);
glRecti(-58, -40, -53, -50);
glRecti(-58,-70,-53,-80);
glRecti(-48,-40,-43,-50);
glRecti(-48,-70,-43,-80);
glRecti(-28,-10,-23,-20);
glRecti(-28,-40,-23,-50);
glRecti(-28,-70,-23,-80);
glRecti(-18,-10,-13,-20);
glRecti(-18,-40,-13,-50);
glRecti(-18,-70,-13,-80);
glRecti(2,-15,7,-25);
glRecti(2,-40,7,-50);
glRecti(2,-70,7,-80);
glRecti(13,-15,18,-25);
glRecti(13,-40,18,-50);
glRecti(13,-70,18,-80); 
glRecti(32,10,37,20);  
glRecti(32,-10,37,-20);
glRecti(32,-40,37,-50);
glRecti(32,-70,37,-80);
glRecti(43,10,48,20);
glRecti(43,-10,48,-20);
glRecti(43,-40,48,-50);
glRecti(43,-70,48,-80);
glRecti(62,-40,67,-50);
glRecti(62,-70,67,-80);
glRecti(73,-40,78,-50);
glRecti(73,-70,78,-80);			
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    sun();
    moon();
    glLoadIdentity();

    // Draw the first cloud
    drawCloud(cloudX, 60.0f, true);
    drawCloud(cloudX + 100.0f, 70.0f, true);
    drawCloud(cloudX + 200.0f, 60.0f, true);

    // Draw the second cloud moving in the opposite direction
    drawCloud(cloud2X, 80.0f, false); // New cloud
    drawCloud(cloud2X + 100.0f, 90.0f, false); // New cloud
    drawCloud(cloud2X + 200.0f, 80.0f, false); // New cloud
  
    drawBuildings();
    glLoadIdentity();
    draw_window();
    glFlush();

    glutSwapBuffers();
}
void timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'q':
        case 'Q':
        case 27: 
            exit(0);
            break;
    }
}
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        
        moonSpeed = -moonSpeed; 
    }
}
void menu(int option) {
    switch (option) {
        case MENU_SPEED_SLOWER:
            moonSpeed *= 0.5f; 
            break;
        case MENU_SPEED_FASTER:
            moonSpeed *= 2.0f; 
            break;
        case MENU_EXIT:
            exit(0);
            break;
    }
}
void createMenu() {
    glutCreateMenu(menu);
    glutAddMenuEntry("Slower Moon", MENU_SPEED_SLOWER);
    glutAddMenuEntry("Faster Moon", MENU_SPEED_FASTER);
    glutAddMenuEntry("Exit", MENU_EXIT);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
