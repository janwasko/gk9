// GK_lab9.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <stdlib.h>
#include "glut.h"

/*
// tryb wyliczeniowy do pozycji menu
enum
{
	EXIT // wyj�cie
};

// funkcja generuj�ca scen� 3D
void DisplayScene()
{
	// ustawienie kloru t�a
	glClearColor(0.0, 0.0, 0.0, 1.0);
	// czyszczenie bufora koloru
	glClear(GL_COLOR_BUFFER_BIT);
	// bie��cy kolor rysowania glColor3f(GLfloat red, GLfloat green, GLfloat blue);
	glColor3f(1.0, 1.0, 0.0);
	// pocz�tek definicji prymitywu
	glBegin(GL_TRIANGLES);
	// kolejne wierzcho�ki prymitywu
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 1.0, 0.0);
	glVertex3f(1.0, 1.0, 0.0);
	// koniec definicji prymitywu
	glEnd();
	// wykonanie zaleg�ych polece�
	glFlush();
	// zamiana bufor�w koloru
	glutSwapBuffers();
}

// zmiana wielko�ci okna
void Reshape(int width, int height)
{
	// rysowanie sceny 3D
	DisplayScene();
}

// obs�uga menu podr�cznego
void Menu(int value)
{
	switch (value)
	{
		// wyj�cie
		case EXIT:
		exit(0);
	}
}

int main(int argc, char *argv[])
{
	// inicjalizacja biblioteki GLUT
	glutInit(&argc, argv);
	// inicjalizacja bufora ramki
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	// okre�lenie rozmiaru okna programu
	glutInitWindowSize(500, 500);
	// utworzenie g��wnego okna programu
	glutCreateWindow("Pierwszy program");
	// okre�lenie funkcji rysuj�c� scen�
	glutDisplayFunc(DisplayScene);
	// okre�lenie funkcji wywo�ywanej przy zmianie rozmiaru okna
	glutReshapeFunc(Reshape);
	// utworzenie menu podr�cznego
	glutCreateMenu(Menu);
	// dodanie pozycji do menu podr�cznego
	glutAddMenuEntry("Wyj�cie", EXIT);
	// okre�lenie przycisku myszki obs�uguj�cej menu podr�czne
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	// wprowadzenie programu do obs�ugi p�tli komunikat�w
	glutMainLoop();
	return 0;
}
*/

enum
{
	TROJKAT,
	KWADRAT,
	POINTS,
	LINES,
	LINESTRIP,
	LINELOOP,
	TRIANGLESTRIP,
	EXIT
};

int object;

void Display()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glColor3f(1.0, 0.0, 0.0);
	switch (object)
	{
		// trojkat
		case TROJKAT:
		{
			glBegin(GL_TRIANGLES);
			// kolejne wierzcho�ki wielok�ta
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(0.0, 1.0, 0.0);
			glVertex3f(1.0, 1.0, 0.0);
			glEnd();
			break;
		}
		// kwadrat
		case KWADRAT:
		{
			glBegin(GL_POLYGON);
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(0.0, 1.0, 0.0);
			glVertex3f(1.0, 1.0, 0.0);
			glVertex3f(1.0, 0.0, 0.0);
			glEnd();
			break;
		}
		case POINTS:
			glBegin(GL_POINTS);
			glVertex3f(0.5, 0.5, 0.0);
			glEnd();
			break;
		case LINES:
			glBegin(GL_LINES);
			glVertex3f(0.5, 0.5, 0.0);
			glVertex3f(0.0, 0.0, 0.0);
			glEnd();
			break;
		case LINESTRIP:
			glBegin(GL_LINE_STRIP);
			glVertex3f(0.5, 0.5, 0.0);
			glVertex3f(0.3, 0.7, 0.0);
			glVertex3f(0.3, 0.7, 0.0);
			glVertex3f(0.0, 0.0, 0.0);
			glEnd();
			break;
		case LINELOOP:
			glBegin(GL_LINE_LOOP);
			glVertex3f(0.5, 0.5, 0.0);
			glVertex3f(0.3, 0.7, 0.0);
			glVertex3f(0.3, 0.7, 0.0);
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(0.9, 0.8, 0.0);
			glVertex3f(0.9, 0.8, 0.0);
			glVertex3f(0.5, 0.5, 0.0);
			glEnd();
			break;
		case TRIANGLESTRIP:
			glBegin(GL_TRIANGLE_STRIP);
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(0.0, 1.0, 0.0);
			glVertex3f(0.5, -0.75, 0.0);
			glVertex3f(1.0, 1.0, 0.0);
			glEnd();
			break;
	}
	glFlush();
	glutSwapBuffers();
}

void Reshape(int width, int height)
{
	Display();
}

void Menu(int value)
{
	switch (value)
	{
		// TROJKAT
		case TROJKAT:
			object = TROJKAT;
			Display();
			break;
		// KWADRAT
		case KWADRAT:
			object = KWADRAT;
			Display();
			break;
		// POINTS
		case POINTS:
			object = POINTS;
			Display();
			break;
		// LINES
		case LINES:
			object = LINES;
			Display();
			break;
		// LINESTRIP
		case LINESTRIP:
			object = LINESTRIP;
			Display();
			break;
		// LINELOOP
		case LINELOOP:
			object = LINELOOP;
			Display();
			break;
		// TRIANGLESTRIP
		case TRIANGLESTRIP:
			object = TRIANGLESTRIP;
			Display();
			break;
		// wyj�cie
		case EXIT:
			exit(0);
	}
}

int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Pierwszy program");
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutCreateMenu(Menu);
	glutAddMenuEntry("Trojkat", TROJKAT);
	glutAddMenuEntry("Kwadrat", KWADRAT);
	glutAddMenuEntry("Points", POINTS);
	glutAddMenuEntry("Lines", LINES);
	glutAddMenuEntry("LineStrip", LINESTRIP);
	glutAddMenuEntry("LineLoop", LINELOOP);
	glutAddMenuEntry("TriangleStrip", TRIANGLESTRIP);
	glutAddMenuEntry("wyjscie", EXIT);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}