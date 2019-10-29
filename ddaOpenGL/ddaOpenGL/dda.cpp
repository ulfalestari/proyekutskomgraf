// Algoritma DDA

#include <GL\freeglut.h>
#include <GL\glut.h>
#include <iostream>

using namespace std;

//identifier fungsi
void init();
void display(void);
void dda(void);

//  posisi window di layar
int window_x;
int window_y;

//  ukuran window
int window_width = 480;
int window_height = 480;

//  judul window
char *judul_window = "Algoritma DDA";

void main(int argc, char **argv)
{
	//  inisialisasi GLUT (OpenGL Utility Toolkit)
	glutInit(&argc, argv);
	// set posisi window supaya berada di tengah 
	window_x = (glutGet(GLUT_SCREEN_WIDTH) - window_width) / 2;
	window_y = (glutGet(GLUT_SCREEN_HEIGHT) - window_height) / 2;
	glutInitWindowSize(window_width, window_height); //set ukuran window 
	glutInitWindowPosition(window_x, window_y); //set posisi window

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE); // set display RGB dan double buffer
	glutCreateWindow(judul_window);

	
	init();
	
	glutDisplayFunc(display); // fungsi display
	glutMainLoop(); // loop pemrosesan GLUT
}

void init()
{ 
	glClearColor(0.0, 0.0, 0.0, 0.0); //set warna background 
	glColor3f(0.0, 1.0, 0.0); //set warna titik
	glPointSize(5.0); //set ukuran titik
	glMatrixMode(GL_PROJECTION); //set mode matriks yang digunakan 
	glLoadIdentity(); // load matriks identitas
	gluOrtho2D(0.0, 600.0, 0.0, 600.0); // set ukuran viewing window
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //clear color
	dda(); //panggil fungsi dda 
	glutSwapBuffers(); //swap buffer 
}

void dda(void) {
	int x1, y1, x2, y2;
	float x,y,dx, dy, steps, x_inc, y_inc;
	//tentukan titik awal dan akhir
	x1 = 1;
	y1 = 1;
	x2 = 500;
	y2 = 400;
	x = x1;
	y = y1;

	//hitung dx dan dy
	dx = x2 - x1;
	dy = y2 - y1;

	//hitung steps
	if (dx > dy) {
		steps = dx;
	}
	else steps = dy;

	//hitung perubahan nilai x (x_inc) dan y (y_inc)
	x_inc = dx / steps;
	y_inc = dy / steps;

	//gambar titik awal
	glBegin(GL_POINTS);
	glVertex2i(x, y); // gambar titik awal

	//perulangan untuk menggambar titik-titik 
	do {
		x += x_inc; // x = x + x_inc
		y += y_inc; // y = y + y_inc
		glVertex2i(round(x), round(y)); //gambar titik
	} while (x < x2);

	glEnd();
	glFlush();
}

