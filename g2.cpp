#include <iostream>
#include <vector>
#include <sstream>
#include <glm/glm.hpp>
#include <glm/gtx/normal.hpp>
#include "glut.h"

using namespace std;
using namespace glm;

class Wall{
public:
    Wall(){}
    Wall(vec3 P, vec3 u, vec3 v){}
    void draw(){}

    vec3 P,u,v,normal;
};


class Ball{
public:
    Ball(){
        r = 0.02;
        pos = vec3(0,0,0);
        vel = vec3(1,0,0);
    }
    void draw(){
        glColor3f(1,1,1);
        glTranslatef(pos.x,pos.y,pos.y);
        glutWireSphere(r,10,10);
        glTranslatef(-pos.x,-pos.y,-pos.y);
    }

    void move(float deltat = 1){
        pos += deltat*vel;
    }

    vec3 pos,vel;
    float r;
};





class Scene{
public:
    Scene(){}

    void setCamera(){
        glMatrixMode (GL_PROJECTION);
        glLoadIdentity ();
        glFrustum(-1,1,-1,1,1,100);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(0,0,2,0,0,0,0,1,0);
    }
    void draw(){
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        setCamera();
        glEnable(GL_DEPTH_TEST);
        glMatrixMode(GL_MODELVIEW);

        B.draw();
        //W.draw();

        glutSwapBuffers();
    }
    void move(float deltat){
        B.move(deltat);
    }

    Ball B;
    Wall W;
};

Scene scene;


void display(){
    scene.draw();
}

void idle(){
    scene.move(0.01);
    scene.draw();
}

void main() {

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB );
    glutInitWindowSize(600,600);
    glutCreateWindow("Scene");
    glutDisplayFunc(display);
    glutIdleFunc(idle);

    glutMainLoop();
}


