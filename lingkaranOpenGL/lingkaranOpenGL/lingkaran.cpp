/*
UTS KOMPUTER GRAFIK-EKSPERIMEN DENGAN ALGORITMA LINGKARAN
NAMA		: ULFA PUJI LESTARI
NIM		: A11.2016.09418
KELOMPOK	: A11.4501-KOMPUTER GRAFIK
DOSEN		: HANNY HARYANTO, M.KOM
*/
//library bahasa C++ serta opengl yg dapat support di programnya
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;

//membuat kelas fungsi

void initial();
void tampil();
void bunder();
void coba();

//menentukan deklarasi variabel dengan ukuran pada layernya
int window_x, window_y;
int window_lebar = 500;
int window_tinggi = 500;

char* title_window = "ALGORITMA LINGKARAN";

void main(int argc, char **argv) {
	glutInit(&__argc, argv);
	window_x = (glutGet(GLUT_SCREEN_WIDTH) - window_lebar)/2;
	window_y = (glutGet(GLUT_SCREEN_HEIGHT) - window_tinggi)/2;
	glutInitWindowSize(window_lebar, window_tinggi);
	glutInitWindowPosition(window_x, window_y);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow(title_window);
	initial();
	glutDisplayFunc(tampil); //seabagai tampilan dengan glut
	glutMainLoop();

}

void tampil() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 1.0);
	bunder();
	glColor3f(1.0, 0.0, 1.0);
	coba();
	glutSwapBuffers(); //ini menukar bagian belakang menjadi buffer layernya
}


void initial(){
	glClearColor(0.0, 0.0, 0.0, 0.0); //menentukan warna garis/ titik
	/*ket warna
		0,0,0 -> hitam
		1,1,1 -> putih
		0,0,1 -> biru
		0,1,1 -> biru kehijauan
		1,1,0 -> kuning
		1,0,0 -> merah
		0,1,0 -> hijau*/
	//glColor3f(0.0, 0.0, 1.0); //menentukan warna dari titik yg akan digambar
	glPointSize(3.0); //menentukan besarn titik
	glMatrixMode(GL_PROJECTION); // ini intial matrix yg dipakai
	glLoadIdentity(); //sebagai mereset project matrix kita buat(pusatnya 0,0)
	gluOrtho2D(0.0, 600.0, 0.0, 600.0); // ini buat kotak objek berbentuk 2dimesni
}
void bunder() {
	//menentukan nilai titik pusast & jari-jarinyaa
	//serta hitung nilai posisi awal dan mengatur nilai awal untuk x & y

	int xc, yc, r;
	r=80;
	xc=120;
	yc=190;
	int x=5; 
	int posisi=1-r;
	int y=r;
	//note: posisi start awal -> (x,r)
	
	glBegin(GL_POINTS); //menentukan gambar titik di titik layer

	for (x = 0; x <= y; x++) {
		if (posisi < 0){
			posisi = posisi + 2 * x + 1;
		}else{
			y--;
		posisi = posisi + 2 * (x - y) + 1;
}
		//mentranlasikan terhadap titik pusat serta cerminkan pada titiknya
		//fungsi primitf glVertex(x,y)
		//glVertex2i(xc+x, yc+y);
		glVertex2i(xc-x, yc+y);
		glVertex2i(xc+x, yc-y);
		glVertex2i(xc-x, yc-y);
		glVertex2i(xc+y, yc+x);
		glVertex2i(xc-y, yc+x);
		glVertex2i(xc+y, yc-x);
		//glVertex2i(xc-y, yc-x);
	}
	glEnd(); //menggambar akhir titik di titik layernya / vertex
	glFlush(); //ini menggambarr ke layernya
}


void coba(){
	//menentukan deklarasi variabel 
	int a,b,jari2,x1,y1, posisi2;

	//rumus srta hitung
	a = 100;
	b = 200;
	jari2 = 50;
	x1 = 10;
	posisi2 = 4 + x1 / jari2;
	y1 = jari2;
	
	glBegin(GL_POINTS);
	

	for (x1 = 0; x1 <= y1; x1++) {
		if (posisi2 >= 0) 
			posisi2 = posisi2 + (x1 - y1) * 4 + 8;
		
		else 
			y1++;
			posisi2 = posisi2 + 4 * jari2 + 1;
		
		glVertex2i(a+x1, b+y1);
		glVertex2i(a+y1, b-x1);
		glVertex2i(a+x1, b-y1);

	}
	glEnd(); //menggambar akhir titik di titik layernya / vertex
	glFlush(); //ini menggambar ke layernyaq
}


