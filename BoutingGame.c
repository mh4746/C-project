#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define pi 3.142857

int c = 0, d = 0, left = 0, right = 0;
int m = 0, j = 1, flag1 = 0, l = 1, flag2 = 0, n = 0, score = 0, count = 1;

// Initialization function

void myInit (void)
{
	glClearColor(0.0, 1.0, 1.0, 1.0);
	// Set picture color to red (in RGB model)
	// as only argument corresponding to R (Red) is 1.0 and rest are 0.0
	glColor3f(1.0f, 0.0f, 0.0f);

	//Set width of point to one unit
	//glPointSize(4.0);
	  glMatrixMode(GL_PROJECTION);
	 // glOrtho(-2,2,-2,2,-2,2);
       glLoadIdentity();

	// Set window size in X- and Y- direction
	gluOrtho2D(-620.0, 620.0, -340.0, 340.0);

}
void timer(int id) {

   glutPostRedisplay();
}
// keyboard function : it gets active when button pressed

void keyboard(unsigned char key, int x, int y)
{

	left = -200 + 200 * (d - c);
	right = 200 + 200 * (d - c);

	// if leftmost index of window is hit
	// then rectangle will not move to left on furthure pressing of b
	// only it will move to right on pressing n
	if (left == -600)
	{
		// '110' -> Ascii value of 'n'
		// so d is incremented when n is pressed
		if (key == 110)
			d++;
	}
	// if rightmost index of window is hit
	// then rectangle will not move to right on furthure pressing of n
	// only it will move to left on pressing b
	else if (right == 600)
	{
		// '98' -> Ascii value of 'b'
		// so c is incremented when b is pressed
		if (key == 98)
			c++;
	}
	// when rectangle is in middle, then it will move into both
	// direction depending upon pressed key
	else
	{
		if (key == 98)
			c++;
		if (key == 110)
			d++;
	}

	   glutPostRedisplay();
	   timer(10);

}

void newDisplay(void){

          glRasterPos2d(1.0,15.0);

      //  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

         char str[]="1.Start press x.";

         for(int i = 0; i<strlen(str); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);


          glRasterPos2d(1.0,-10.0);

      //  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

         char lev[]="2.Level auto increment.";

         for(int i = 0; i<strlen(lev); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,lev[i]);

         glRasterPos2d(1.0,-35.0);

         char st[]="3.Left move press b.";

         for(int i = 0; i<strlen(st); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,st[i]);

       glRasterPos2d(1.0,-65.0);
        char s[]="4.Right move press n.";

         for(int i = 0; i<strlen(s); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[i]);

         glRasterPos2d(1.0,-95.0);
        char ext[]="5.Exit press y.";

         for(int i = 0; i<strlen(ext); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,ext[i]);

		glutSwapBuffers();

}

  void output(void)
  {


        char ch [50],lev[12];
        int level = 1;

         glRasterPos2d(1.0,10.0);
          sprintf (ch, "Your Score: %d", score-1);
          // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

           for(int j = 0; j<strlen(ch); j++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,ch[j]);


             glRasterPos2d(1.0,-30.0);
             if(score>20) level = 2;
             else if(score > 60 ) level = 3;

             else if(score > 80 ) level = 4;

              sprintf (lev, "Your Level: %d", level);

         //  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

           for(int j = 0; j<strlen(lev); j++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,lev[j]);

             //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glutKeyboardFunc(keyboard);
        // glutPostRedisplay();
		glutSwapBuffers();

		//exit(0);
  }


void myDisplay(void)
{

	// x and y keeps point on circumference of circle
	// glRasterPos3f(-0.8,2.5,1);

	int x, y, k;
	// outer 'for loop' is to for making motion in ball


 	for (k = 0; k <= 600; k += 100)
 	{

		  glClear(GL_COLOR_BUFFER_BIT);
		  glBegin(GL_LINE_STRIP);




		// i keeps track of angle
		float i = 0;
		// change in m denotes motion in vertical direction and
		// change in n denotes motion in horizontal direction
		m = m + 6;//6
		n = n + 4;//4
		// drawing of circle centre at (0, 12) iterated up to 2*pi, i.e., 360 degree
		while (i <= 2*pi)
		{
			y = 12 + 20 * cos(i);
			x = 20 * sin(i);
			i = i + 0.1;
			// flag1 is 0 to show motion in upward direction and is 1 for downward direction
			if (m == 288 && flag1 == 0)
			{
				j = -1;
				m = -288;
				flag1 = 1;
				score++;
			}
			if (m == 288 && flag1 == 1)
			{
				j = 1;
				m = -288;
				flag1 = 0;
			}
			// flag2 is 0 to show motion in rightward direction and is 1 for leftward direction
			if (n == 580 && flag2 == 0)
			{
				l = -1;
				n = -580;
				flag2 = 1;
			}
			if (n == 580 && flag2 == 1)
			{
				l = 1;
				n = -580;
				flag2 = 0;
			}
			// equation for desired motion of ball
			 glVertex2i((x - l * n), (y - j * m));

             glutTimerFunc(2500,timer,10);
		}

		glEnd();


		// these four points draws outer rectangle which determines window
		glBegin(GL_LINE_LOOP);
			glVertex2i(-600, -320);
			glVertex2i(-600, 320);
			glVertex2i(600, 320);
			glVertex2i(600, -320);
		glEnd();


		// these four points draws smaller rectangle which is for catching ball
		glBegin(GL_LINE_LOOP);
		left = -200 + 200 * (d - c);
		right = 200 + 200 * (d - c);
			glVertex2i(left, -315);
			glVertex2i(left, -295);
			glVertex2i(right, -295);
			glVertex2i(right, -315);
		glEnd();


		// following condition checks if falling ball is catched on rectangle or not
		if ((j * m) == 276)
		{
			if ((left > ((-1 * l * n) + 20)) || (right < (-1 * l * n) - 20))
			{
				 //  printf("Game Over !!!\nYour Score is :\t%d\n", score);
				   glutDisplayFunc(output);
				   //exit(0);
			}
		}

        glutSwapBuffers();

	 }

}


 void key(unsigned char ky, int x, int y)
  {
       if(ky=='x'){
        glutDisplayFunc(myDisplay);
       }
       else if(ky=='y'){
        exit(0);
       }
       glutKeyboardFunc(keyboard);
        glutPostRedisplay();
  }


// Driver Program
int main (int argc, char** argv)
{
	 glutInit(&argc, argv);

	 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	 glutInitWindowSize(1100, 600);

	 glutInitWindowPosition(0, 0);
	 glutCreateWindow("Game");

	  glutKeyboardFunc(key);

      myInit();

     glutDisplayFunc(newDisplay);

	glutMainLoop();
}