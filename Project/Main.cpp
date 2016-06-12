#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

using namespace std;

void display();
void specialKeys();
 void specialButtons ();
 void rec();

double rotate_y =  5; 
double rotate_x = -5;

double door_ro = 0;
double wind_ro = 0;
double ro = 0;
int countt = 0;
double rotate_wh = 0;

double rx = 0;
double ry = 0;
double rz = 0;

void  Bicycle(){  

	glColor3f(0.0, 0.0, 0.0);
	glRotatef( ro, 0.0, 1.0, 0.0 );

	glBegin(GL_POLYGON);
		glVertex3f(-0.5 , -0.6 , -0.7);
		glVertex3f(-0.5 , -0.6 , -0.6);
		glVertex3f(-0.51 , -0.61 , -0.6);
		glVertex3f(-0.51 , -0.61 ,- 0.7);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(-0.5 , -0.7 , -0.65);
		glVertex3f(-0.5 , -0.7 , -0.62);
		glVertex3f(-0.51 , -0.71 ,- 0.62);
		glVertex3f(-0.51 , -0.71 ,- 0.65);
	glEnd();

	glBegin(GL_LINES);
		glVertex3f(-0.5 , -0.6 , -0.65);
	    glVertex3f(-0.5 , -0.9 ,- 0.65);
		glVertex3f(-0.51 , -0.61 ,- 0.65);
		glVertex3f(-0.51, -0.91, -0.65);
		glVertex3f(-0.5 , -0.6 , -0.62);
		glVertex3f(-0.5 , -0.9 , -0.62);
		glVertex3f(-0.51 , -0.61 , -.62);
		glVertex3f(-0.51 , -0.91 , -0.62);
	for(float in = 0 ; in <= 360 ; in += (0.01 / 0.050)){
		glVertex3f(-0.5 + (0.050 * sin(in)), -0.9 + (0.050 * cos(in)), -0.65);
		glVertex3f(-0.51 + (0.050 * sin(in)), -0.91 + (0.050 * cos(in)), -0.65);
		glVertex3f(-0.5 + (0.050 * sin(in)), -0.9 + (0.050 * cos(in)), -0.62);
		glVertex3f(-0.51 + (0.050 * sin(in)), -0.91 + (0.050 * cos(in)), -0.62);
		glVertex3f(-0.5 + (0.050 * sin(in)), -0.9 + (0.050 * cos(in)), -0.65);
		glVertex3f(-0.5 + (0.050 * sin(in)), -0.9 + (0.050 * cos(in)), -0.62);
		glVertex3f(-0.51 + (0.050 * sin(in)), -0.91 + (0.050 * cos(in)), -0.65);
		glVertex3f(-0.51 + (0.050 * sin(in)), -0.91 + (0.050 * cos(in)), -0.62);
	}
	glEnd();



	glBegin(GL_LINES);
		glVertex3f(-0.5 , -0.7 , -0.65);
	    glVertex3f(-0.8 , -0.9 , -0.65);
		glVertex3f(-0.51 , -0.71 , -0.65);
		glVertex3f(-0.81, -0.91, -0.65);
		glVertex3f(-0.5 , -0.7 , -0.62);
		glVertex3f(-0.8 , -0.9 , -0.62);
		glVertex3f(-0.51 , -0.71 , -0.62);
		glVertex3f(-0.81 , -0.91 , -0.62);
	for(float in = 0 ; in <= 360 ; in += (0.01 / 0.050)){
		glVertex3f(-0.8 + (0.050 * sin(in)), -0.9 + (0.050 * cos(in)), -0.65);
		glVertex3f(-0.81 + (0.050 * sin(in)), -0.91 + (0.050 * cos(in)), -0.65);
		glVertex3f(-0.8 + (0.050 * sin(in)), -0.9 + (0.050 * cos(in)), -0.62);
		glVertex3f(-0.81 + (0.050 * sin(in)), -0.91 + (0.050 * cos(in)), -0.62);
		glVertex3f(-0.81 + (0.050 * sin(in)), -0.91 + (0.050 * cos(in)), -0.62);
		glVertex3f(-0.81 + (0.050 * sin(in)), -0.91 + (0.050 * cos(in)), -0.65);
		glVertex3f(-0.8 + (0.050 * sin(in)), -0.9 + (0.050 * cos(in)), -0.65);
		glVertex3f(-0.8 + (0.050 * sin(in)), -0.9 + (0.050 * cos(in)), -0.62);
	}
	glEnd();
	
	glRotatef( ro, 0.0, -1.0, 0.0 );
	
}

void Windows(){
	int dx[] = {-1 , 1 , -1 , 1};
	int dy[] = {1 , 1 , -1 , -1};
	// BackGround
	for(int i = 0; i < 4 ; i++){
	glBegin(GL_POLYGON);
  glColor3f( 1.0, 1.0, 1.0 );    
  glVertex3f(  dx[i] * 0.29,  dy[i] * 0.29, -0.502 );     
  glVertex3f(  dx[i] * 0.21,   dy[i] *0.29, -0.502 );      
  glVertex3f( dx[i] * 0.21,  dy[i] * 0.21, -0.502 );     
  glVertex3f( dx[i] * 0.29, dy[i] * 0.21, -0.502 );     
  glEnd();
  

  // rotate open close
	glRotatef( wind_ro , 1.0, 0.0, 0.0 );
	
	// FRONT
  glBegin(GL_POLYGON);
  glColor3f( 0.0, 0.0, 0.2 );   
  glVertex3f(  dx[i] * 0.3,  dy[i] *0.3, -0.54 );     
  glVertex3f(  dx[i] * 0.2,  dy[i] * 0.3, -0.54 );      
  glVertex3f( dx[i] * 0.2,  dy[i] * 0.2, -0.54 );     
  glVertex3f( dx[i] * 0.3, dy[i] * 0.2, -0.54 );     
  glEnd();

  //Back
  glBegin(GL_POLYGON);
  glColor3f( 0.0, 0.0, 0.0 );   
  glVertex3f(  dx[i] * 0.3, dy[i] * 0.3, -0.505 );     
  glVertex3f(  dx[i] * 0.2,  dy[i] * 0.3, -0.505 );      
  glVertex3f( dx[i] * 0.2,  dy[i] * 0.2, -0.505 );     
  glVertex3f( dx[i] * 0.3, dy[i] * 0.2, -0.505 );     
  glEnd();

  // right
    glBegin(GL_POLYGON);
  glColor3f( 0.0, 0.0, 0.0 );     
  glVertex3f(  dx[i] * 0.2,  dy[i] * 0.3, -0.54 );      
  glVertex3f( dx[i] * 0.2,   dy[i] *0.2, -0.54 );      
   glVertex3f( dx[i] * 0.2,  dy[i] * 0.2, -0.505 );  
   glVertex3f(  dx[i] * 0.2,  dy[i] * 0.3, -0.505 );   
  glEnd();

  // Left
   glBegin(GL_POLYGON);
  glColor3f( 0.0, 0.0, 0.0 );   
  glVertex3f(  dx[i] * 0.3,  dy[i] *0.3, -0.54 );     
  glVertex3f(  dx[i] * 0.3, dy[i] * 0.3, -0.505 );     
  glVertex3f( dx[i] * 0.3,  dy[i] *0.2, -0.505 );     
  glVertex3f( dx[i] * 0.3,  dy[i] *0.2, -0.54 );     
  glEnd();

  // Top
  glBegin(GL_POLYGON);
  glColor3f( 0.0, 0.0, 0.0 );   
  glVertex3f(  dx[i] * 0.3, dy[i] * 0.3, -0.54 );     
  glVertex3f(  dx[i] * 0.2,  dy[i] * 0.3, -0.54 );      
 glVertex3f(  dx[i] * 0.2,   dy[i] *0.3, -0.505 );     
  glVertex3f(  dx[i] * 0.3, dy[i] * 0.3, -0.505 );     
  glEnd();

  // Down
  glBegin(GL_POLYGON);
  glColor3f( 0.0, 0.0, 0.0 );   
  glVertex3f( dx[i] * 0.3,  dy[i] *0.2, -0.505 );    
 glVertex3f( dx[i] * 0.2,   dy[i] *0.2, -0.505 );     
  glVertex3f( dx[i] * 0.2,  dy[i] * 0.2, -0.54 );     
  glVertex3f( dx[i] * 0.3,  dy[i] *0.2, -0.54 );     
  glEnd();

  glRotatef( wind_ro , -1.0, 0.0, 0.0 );

  }
}
void Door(){
	

	// BackGround
	glBegin(GL_POLYGON);
  glColor3f( 1.0, 1.0, 1.0 );    
  glVertex3f(  0.047, -0.6, -0.501 );     
  glVertex3f(  0.047,  -0.1, -0.501 );      
  glVertex3f( -0.047,  -0.1, -0.501 );     
  glVertex3f( -0.047, -0.6, -0.501 );     
  glEnd();

  // rotate open close
	glRotatef( door_ro , 0.0, 1.0, 0.0 );
	
	// FRONT
  glBegin(GL_POLYGON);
  glColor3f( 0.0, 0.0, 1.0 );   
  glVertex3f(  0.05, -0.6, -0.52 );     
  glVertex3f(  0.05,  -0.1, -0.52 );      
  glVertex3f( -0.05,  -0.1, -0.52 );     
  glVertex3f( -0.05, -0.6, -0.52 );     
  glEnd();
  
  // Back
  glBegin(GL_POLYGON);
  glColor3f( 0.0, 0.0, 0.0 );   
  glVertex3f(  0.05, -0.6, -0.505 );     
  glVertex3f(  0.05,  -0.1, -0.505 );      
  glVertex3f( -0.05,  -0.1, -0.505 );     
  glVertex3f( -0.05, -0.6, -0.505 );     
  glEnd();

  // right
  glBegin(GL_POLYGON);
  glColor3f( 0.0, 0.0, 0.0 );   
  glVertex3f(  0.05,  -0.1, -0.505 );      
  glVertex3f(  0.05,  -0.1, -0.52 );      
  glVertex3f( -0.05,  -0.1, -0.52 );     
  glVertex3f( -0.05,  -0.1, -0.505 );   
  glEnd();
  // Left
  glBegin(GL_POLYGON);
  glColor3f( 0.0, 0.0, 0.0 );   
  glVertex3f(  0.05, -0.6, -0.52 );     
  glVertex3f(  0.05, -0.6, -0.505 );      
  glVertex3f( -0.05, -0.6, -0.505 );    
  glVertex3f( -0.05, -0.6, -0.52 );     
  glEnd();
   // Top
  glBegin(GL_POLYGON);
  glColor3f( 0.0, 0.0, 0.0 );   
  glVertex3f(  0.05, -0.6, -0.52 );     
  glVertex3f(  0.05,  -0.1, -0.52 );          
  glVertex3f(  0.05,  -0.1, -0.505 );     
  glVertex3f(  0.05, -0.6, -0.505 );
  glEnd();

  glRotatef( door_ro , 0.0 , -1.0, 0.0 );
}

void Buidling(){
	// Rotate when rotate_x and rotate_y changes 
	glRotatef( rotate_x, 1.0, 0.0, 0.0 );
	glRotatef( rotate_y, 0.0, 1.0, 0.0 );


  // FRONT

  glBegin(GL_POLYGON);
  glColor3f( 0.2, 0.0, 0.0 );    
  glVertex3f(  0.5, -0.7, -0.5 );     
  glVertex3f(  0.5,  0.7, -0.5 );      
  glVertex3f( -0.5,  0.7, -0.5 );     
  glVertex3f( -0.5, -0.7, -0.5 );     
 
  glEnd();
 
  // BACK
  glBegin(GL_POLYGON);
  glColor3f( 0.2, 0.0, 0.0 ); 
  glVertex3f(  0.5, -0.7, 0.5 );
  glVertex3f(  0.5,  0.7, 0.5 );
  glVertex3f( -0.5,  0.7, 0.5 );
  glVertex3f( -0.5, -0.7, 0.5 );
  glEnd();
 
  // RIGHT
  glBegin(GL_POLYGON);
  glColor3f(  0.5,  0.0,  0.0 );
  glVertex3f( 0.5, -0.7, -0.5 );
  glVertex3f( 0.5,  0.7, -0.5 );
  glVertex3f( 0.5,  0.7,  0.5 );
  glVertex3f( 0.5, -0.7,  0.5 );
  glEnd();
 
  // LEFT
  glBegin(GL_POLYGON);
  glColor3f(   0.5,  0.0,  0.0 );
  glVertex3f( -0.5, -0.7,  0.5 );
  glVertex3f( -0.5,  0.7,  0.5 );
  glVertex3f( -0.5,  0.7, -0.5 );
  glVertex3f( -0.5, -0.7, -0.5 );
  glEnd();
 
  // TOP
  glBegin(GL_TRIANGLE_FAN);
  glColor3f(   0.0,  0.0,  0.0 );
  glVertex3f(  0.0,  0.9,  0.0 );
  glVertex3f(  0.5,  0.7,  0.5 );
  glVertex3f(  0.5,  0.7, -0.5 );
  glVertex3f( -0.5,  0.7, -0.5 );
  glVertex3f( -0.5,  0.7,  0.5 );
  glVertex3f(  0.5,  0.7,  0.5 );
  glEnd();
 
  // BOTTOM
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  0.0,  0.0 );
  glVertex3f(  0.5, -0.7, -0.5 );
  glVertex3f(  0.5, -0.7,  0.5 );
  glVertex3f( -0.5, -0.7,  0.5 );
  glVertex3f( -0.5, -0.7, -0.5 );
  glEnd();
 
  // Door
  Door();
  Windows();
  // Disable The rotate
 
  glRotatef( rotate_y, 0.0, -1.0, 0.0 );

}


void display(){
 
  //  Clear screen and Z-buffer
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 
  // Reset transformations
  glLoadIdentity();
	glRotatef( rx, 1.0, 0.0, 0.0 );
	glRotatef( ry, 0.0, 1.0, 0.0 );
	glRotatef( rz, 0.0, 0.0, 1.0 );
//	glScalef(1.0 , 1.0 , -.5);
  Buidling();
  Bicycle();
  rec();
  glFlush();
  glutSwapBuffers();
 
}
 
void specialButtons (unsigned char key, int xmouse, int ymouse)
{	
	if (key == 'o' && door_ro == 0)
		door_ro += 11;
 
	else if (key == 'c' && door_ro == 11)
		door_ro = 0;
	if (key == 'O' && wind_ro == 0)
		wind_ro += 7;
 
	else if (key == 'C' && wind_ro == 7)
		wind_ro = 0;
	else if (key == 'b'){
    ro += 5 ;
	countt --;
	if(countt == -18){
		countt = 15;
		ro = -5 * 15;
		rotate_y -= 20 * 5;
	}
	
  }
 
  else if (key == 'f'){
    ro -= 5 ;
	countt ++;
	if(countt == 16){
		countt = 0;
		ro = 0;
		rotate_y += 18 * 5;
	}
	
  }

  else if(key == 'r'){
	  countt = 15;
		ro = -5 * 15;
		rotate_y += 15 * 5;
  }

  else if(key == 'l'){
	  countt = -17;
		ro =  5 * 15;
		rotate_y += 15 * 5;
  }
  else if(key == 'z'){
	  rz += 5;
  }
  else if(key == 'Z'){
	  rz -= 5;
  }
   glutPostRedisplay(); 
}

void specialKeys( int key, int x, int y ) {
 

  if (key == GLUT_KEY_LEFT){
            ry += 5;
		
  }
 
  else if (key == GLUT_KEY_UP){
    rx -= 5;
  }
  else if (key == GLUT_KEY_DOWN){
    rx += 5;
		
  }
 
  else if (key == GLUT_KEY_RIGHT){
    ry -= 5;
  }
  
  //  Request display update
  glutPostRedisplay();
 
}
bool flag = 0;

void mouse(int button, int state, int x, int y)
{
    if( button== GLUT_LEFT_BUTTON  )
    {
		flag = 1;
    } 
    else if( button== GLUT_RIGHT_BUTTON)
    {
		flag = 0;
    }
	glutPostRedisplay();
}

void rec(){
	if(flag){
		ro -= 5 ;
		countt ++;
		if(countt == 16){
			countt = 0;
			ro = 0;
			rotate_y += 18 * 5;
		}
	}
}

void Timer(int iUnused)
{
    glutPostRedisplay();
    glutTimerFunc(30, Timer, 0);
}

int main(int argc, char* argv[]){
 
  //  Initialize GLUT and process user parameters
  glutInit(&argc,argv);
 
  //  Request double buffered true color window with Z-buffer
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
 
  // Create window
  glutCreateWindow("Graphics Project");
 
  //  Enable Z-buffer depth test
  glEnable(GL_DEPTH_TEST);
 
  // Callback functions
  glClearColor(0.0, 0.2, 0.0, 0.0);
  glutDisplayFunc(display);
  glutSpecialFunc(specialKeys);
  glutKeyboardFunc(specialButtons);
  glutMouseFunc(mouse);
  //  Pass control to GLUT for events
  Timer(0);
  glutMainLoop();
 
  return 0;
}