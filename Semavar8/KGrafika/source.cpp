#define _USE_MATH_DEFINES

#include <iostream>
#include <glut.h>
#include <glaux.h>
#include <cmath>



unsigned int texture[7]; //���������� �������
float Ybread = 3.0; //������, ��� ���������� ��������
float Ysnack = 3.0; //������, ��� ���������� ��������
float Ycheese = 3.0; //������, ��� ���������� ���
float HightBurger; //������� ����������

void Texture()
{
	AUX_RGBImageRec *texture1 = auxDIBImageLoadA("table.bmp"),
		*texture2 = auxDIBImageLoadA("teapot.bmp"),
		*texture3 = auxDIBImageLoadA("donut.bmp"),
		*texture4 = auxDIBImageLoadA("snack.bmp"),
		*texture5 = auxDIBImageLoadA("cheese.bmp"),
		*texture6 = auxDIBImageLoadA("bread.bmp"),
		*texture7 = auxDIBImageLoadA("background.bmp");
	glGenTextures(7, &texture[0]); //�������� ������� �������
	glBindTexture(GL_TEXTURE_2D, texture[0]); //������������� � �������� ����������, �. �. ������ �� �������� (��������� �����������, �������������)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //�������� �������� (��������� �����������, ������� ��� ������ ��������, ����� �������������� ������ ��������� �������� ��������)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //�������� �������� (��������� �����������, ������� ��� ���������� ��������, ����� �������������� ������ ��������� �������� ��������)
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture1->sizeX, texture1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture1->data);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture2->sizeX, texture2->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture2->data);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture3->sizeX, texture3->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture3->data);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture4->sizeX, texture4->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture4->data);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture5->sizeX, texture5->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture5->data);
	glBindTexture(GL_TEXTURE_2D, texture[5]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture6->sizeX, texture6->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture6->data);
	glBindTexture(GL_TEXTURE_2D, texture[6]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture7->sizeX, texture7->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture7->data);
}

void Light()
{
	glEnable(GL_LIGHT0); //������������� ��������� ����������� ��������� �����
	glEnable(GL_LIGHTING); //������������� ��������� ����������� ��������� �����
	glEnable(GL_DEPTH_TEST); //������������� ��������� ����������� ��������� �����
	GLfloat pos[] = { 0.0, 0.0, 1.0, 0.0 }; //��������� �������� 0 - ������ �������� ����� ��������� ���������� ������ (� ��� �� ��� z, ����� ����� ���), ���� 1 - ������ �� ���������� ��������
	glLightfv(GL_LIGHT0, GL_POSITION, pos);
}

void Table()
{
	//������ ����
	glBindTexture(GL_TEXTURE_2D, texture[0]); //�������� ����������� �������� ��� ���������
	glBegin(GL_QUADS); //������ ����; ������ ��������� �������� ������ ���������� ���������������; ���� ������ �� ������� ������� ����� ������, �� ��������� ������� ������������
	glTexCoord2f(0.0, 0.0); glVertex3d(-2.0, 0, -2.0);
	glTexCoord2f(1.0, 0.0); glVertex3d(-2.0, 0, 5.0);
	glTexCoord2f(1.0, 1.0); glVertex3d(2.0, 0, 5.0);
	glTexCoord2f(0.0, 1.0); glVertex3d(2.0, 0, -2.0);
	glEnd();
}

void Background()
{
	//������ ���
	glBindTexture(GL_TEXTURE_2D, texture[6]); //�������� ����������� �������� ��� ���������
	glPushMatrix(); //��������� ������� ����������
	glBegin(GL_QUADS); //������ ���
	glTexCoord2f(1.0, 0.0); glVertex3d(-6.0, -6.0, -3.0);
	glTexCoord2f(1.0, 1.0); glVertex3d(-6.0, 5.0, -3.0);
	glTexCoord2f(0.0, 1.0); glVertex3d(6.0, 5.0, -3.0);
	glTexCoord2f(0.0, 0.0); glVertex3d(6.0, -6.0, -3.0);
	glEnd();
	glPopMatrix(); //������������ � ������ �����������
}

void Teapot()
{
	//������ ������
	glBindTexture(GL_TEXTURE_2D, texture[1]); //�������� ����������� �������� ��� ���������
	glPushMatrix(); //��������� ������� ����������
	glTranslated(-0.9, 0.4, 0); //���������� � �����
	glRotated(20, 0, 1, 0); //������������ ������� ��������� �� 20 �������� �� ��� y
	glutSolidTeapot(0.5); //������ ������
	glPopMatrix(); //������������ � ������ �����������
}

void Torus(double r = 0.07, double c = 0.15, int rSeg = 32, int cSeg = 64)
{
	//r - ������ ������
	//c - ������ �����

	glPushMatrix(); //��������� ������� ����������
	glTranslated(0.9, 0.25, 0.5); //���������� � �����
	glRotated(270, 1, 0, 0); //������������ ������� ��������� �� 270 �������� �� ��� x

	glBindTexture(GL_TEXTURE_2D, texture[2]); //�������� ����������� �������� ��� ���������
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); //GL_REPLACE - � �������� ��������� ����� ������������ ���� ����� �� ��������

	const double TAU = 2 * M_PI;

	for (int i = 0; i < rSeg; i++) {
		glBegin(GL_QUAD_STRIP); //��������������� � ������� n ������������ ��������� � �������� 2n-1, 2n, 2n+2, 2n+1
		for (int j = 0; j <= cSeg; j++) {
			for (int k = 0; k <= 1; k++) {
				double s = (i + k) % rSeg + 0.5;
				double t = j % (cSeg + 1);

				double x = (c + r * cos(s * TAU / rSeg)) * cos(t * TAU / cSeg);
				double y = (c + r * cos(s * TAU / rSeg)) * sin(t * TAU / cSeg);
				double z = r * sin(s * TAU / rSeg);

				double u = (i + k) / (float)rSeg;
				double v = t / (float)cSeg;

				glTexCoord2d(u, v);
				glNormal3f(2 * x, 2 * y, 2 * z);
				glVertex3d(2 * x, 2 * y, 2 * z);
			}
		}
		glEnd();
	}

	glPopMatrix(); //������������ � ������ �����������
}

void Snack()
{
	//������ ������ �������
	glBindTexture(GL_TEXTURE_2D, texture[3]); //�������� ����������� �������� ��� ���������
	glPushMatrix(); //��������� ������� ����������
	glTranslated(0, Ysnack, 2.5); //���������� � �����
	float width = 0.4;
	float heightSnack = 0.05;
	float depth = 0.4;
	int segments = 20;

	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i <= segments; i += 1)
	{
		float theta = 2.0f * (float)M_PI * i / (segments);

		glVertex3f(width / 2 * (float)cos(theta),
			0,
			depth / 2 * (float)sin(theta));
		glTexCoord2f((float)cos(theta), (float)sin(theta));
		glVertex3f(width / 2 * (float)cos(theta),
			heightSnack,
			depth / 2 * (float)sin(theta));
		glTexCoord2f((float)cos(theta) * 2,
			(float)sin(theta) * 2);
	}
	for (int i = -1; i <= segments; i *= -1) //������ ���
	{
		float theta = 2.0f * (float)M_PI * i / (segments);

		glVertex3f(width / 2 * (float)cos(theta),
			0,
			depth / 2 * (float)sin(theta));
		glTexCoord2f((float)cos(theta),
			(float)sin(theta));
		if (i < 0)
			i -= 2;
	}
	for (int i = -1; i <= segments; i *= -1) //������ ����
	{
		float theta = 2.0f * (float)M_PI * i / (segments);

		glVertex3f(width / 2 * (float)cos(theta),
			heightSnack,
			depth / 2 * (float)sin(theta));
		glTexCoord2f((float)cos(theta),
			(float)sin(theta));
		if (i < 0)
			i -= 2;
	}
	glEnd();
	glPopMatrix(); //������������ � ������ �����������
}

void Cheese()
{
	//������ ������� ����
	glBindTexture(GL_TEXTURE_2D, texture[4]); //�������� ����������� �������� ��� ���������
	glPushMatrix(); //��������� ������� ����������
	glTranslated(0, Ycheese, 2.5); //���������� � �����
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-0.2, 0.0, 0.2);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.2, 0.0, 0.2);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.2, 0.02, 0.2);
	glTexCoord2f(0.0, 1.0); glVertex3f(-0.2, 0.02, 0.2);

	glTexCoord2f(1.0, 0.0); glVertex3f(-0.2, 0.0, -0.2);
	glTexCoord2f(1.0, 1.0); glVertex3f(-0.2, 0.02, -0.2);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.2, 0.02, -0.2);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.2, 0.0, -0.2);

	glTexCoord2f(0.0, 1.0); glVertex3f(-0.2, 0.02, -0.2);
	glTexCoord2f(0.0, 0.0); glVertex3f(-0.2, 0.02, 0.2);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.2, 0.02, 0.2);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.2, 0.02, -0.2);

	glTexCoord2f(1.0, 1.0); glVertex3f(-0.2, 0.0, -0.2);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.2, 0.0, -0.2);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.2, 0.0, 0.2);
	glTexCoord2f(1.0, 0.0); glVertex3f(-0.2, 0.0, 0.2);

	glTexCoord2f(1.0, 0.0); glVertex3f(0.2, 0.0, -0.2);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.2, 0.02, -0.2);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.2, 0.02, 0.2);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.2, 0.0, 0.2);

	glTexCoord2f(0.0, 0.0); glVertex3f(-0.2, 0.0, -0.2);
	glTexCoord2f(1.0, 0.0); glVertex3f(-0.2, 0.0, 0.2);
	glTexCoord2f(1.0, 1.0); glVertex3f(-0.2, 0.02, 0.2);
	glTexCoord2f(0.0, 1.0); glVertex3f(-0.2, 0.02, -0.2);
	glEnd();
	glPopMatrix(); //������������ � ������ �����������
}

void Bread()
{
	//������ ������� �����
	glBindTexture(GL_TEXTURE_2D, texture[5]); //�������� ����������� �������� ��� ���������
	glPushMatrix(); //��������� ������� ����������
	glTranslated(0.45, Ybread, 2.8); //���������� � �����
	glRotated(180, 0, 1, 0); //������������ ������� ��������� �� 180 �������� �� ��� y

	//������ �������
	glBegin(GL_POLYGON);
	glTexCoord2f(0.025, 0.575); glVertex3f(0.025, 0.0, 0.575); //1 �
	glTexCoord2f(0.0, 0.315); glVertex3f(0.0, 0.0, 0.315); //2 �
	glTexCoord2f(0.025, 0.05); glVertex3f(0.025, 0.0, 0.05); //3 �
	glTexCoord2f(0.1, 0.0); glVertex3f(0.1, 0.0, 0.0); //4 �
	glTexCoord2f(0.2, 0.1); glVertex3f(0.2, 0.0, 0.1); //5 �
	glTexCoord2f(0.25, 0.05); glVertex3f(0.25, 0.0, 0.05); //6 �
	glTexCoord2f(0.9, 0.05); glVertex3f(0.9, 0.0, 0.05); //7 �
	glTexCoord2f(0.9, 0.575); glVertex3f(0.9, 0.0, 0.575); //8 �
	glTexCoord2f(0.25, 0.575); glVertex3f(0.25, 0.0, 0.575); //9 �
	glTexCoord2f(0.2, 0.525); glVertex3f(0.2, 0.0, 0.525); //10 �
	glTexCoord2f(0.1, 0.625); glVertex3f(0.1, 0.0, 0.625); //11 �
	glEnd();

	//������� �������
	glBegin(GL_POLYGON);
	glTexCoord2f(0.025, 0.575); glVertex3f(0.025, 0.12, 0.575); //1 �
	glTexCoord2f(0.0, 0.315); glVertex3f(0.0, 0.12, 0.315); //2 �
	glTexCoord2f(0.025, 0.05); glVertex3f(0.025, 0.12, 0.05); //3 �
	glTexCoord2f(0.1, 0.0); glVertex3f(0.1, 0.12, 0.0); //4 �
	glTexCoord2f(0.2, 0.1); glVertex3f(0.2, 0.12, 0.1); //5 �
	glTexCoord2f(0.25, 0.05); glVertex3f(0.25, 0.12, 0.05); //6 �
	glTexCoord2f(0.9, 0.05); glVertex3f(0.9, 0.12, 0.05); //7 �
	glTexCoord2f(0.9, 0.575); glVertex3f(0.9, 0.12, 0.575); //8 �
	glTexCoord2f(0.25, 0.575); glVertex3f(0.25, 0.12, 0.575); //9 �
	glTexCoord2f(0.2, 0.525); glVertex3f(0.2, 0.12, 0.525); //10 �
	glTexCoord2f(0.1, 0.625); glVertex3f(0.1, 0.12, 0.625); //11 �
	glEnd();

	//����� �� ������ ���������
	glBegin(GL_QUAD_STRIP);
	glVertex3f(0.2, 0.0, 0.1); //5 �
	glVertex3f(0.2, 0.12, 0.1); //5 �
	glVertex3f(0.25, 0.0, 0.05); //6 �
	glVertex3f(0.25, 0.12, 0.05); //6 �
	glVertex3f(0.9, 0.0, 0.05); //7 �
	glVertex3f(0.9, 0.12, 0.05); //7 �
	glVertex3f(0.9, 0.0, 0.575); //8 �
	glVertex3f(0.9, 0.12, 0.575); //8 �
	glVertex3f(0.575, 0.0, 0.525); //9 �
	glVertex3f(0.575, 0.12, 0.525); //9 �
	glVertex3f(0.2, 0.0, 0.525); //10 �
	glVertex3f(0.2, 0.12, 0.525); //10 �
	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0); //������������� "������" ��������, �. �. ��� ����� �������� �� �����
	//����� � ����������� ��������
	glBegin(GL_QUAD_STRIP);
	glVertex3f(0.2, 0.0, 0.525); //10 �
	glVertex3f(0.2, 0.12, 0.525); //10 �
	glVertex3f(0.1, 0.0, 0.625); //11 �
	glVertex3f(0.1, 0.12, 0.625); //11 �
	glVertex3f(0.025, 0.0, 0.575); //1 �
	glVertex3f(0.025, 0.12, 0.575); //1 �
	glVertex3f(0.0, 0.0, 0.315); //2 �
	glVertex3f(0.0, 0.12, 0.315); //2 �
	glVertex3f(0.025, 0.0, 0.05); //3 �
	glVertex3f(0.025, 0.12, 0.05); //3 �
	glVertex3f(0.1, 0.0, 0.0); //4 �
	glVertex3f(0.1, 0.12, 0.0); //4 �
	glVertex3f(0.2, 0.0, 0.1); //5 �
	glVertex3f(0.2, 0.12, 0.1); //5 �
	glEnd();

	glPopMatrix(); //������������ � ������ �����������
}

void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //������� ������ ����� � �������
	glMatrixMode(GL_PROJECTION); //������������� ������������ ������� ��� ����������� ����������������� ������� �� ���������
	glLoadIdentity(); //���������� ������� �������

	glFrustum(-1.0, 1.0, -1.0, 1.0, 2, 20.0); //����� ������� ��������� � ���������������� ���������, ������ �������� ���������� ������ (������ - ��� �����, ������� ����� - ��� � ����������)
	gluLookAt(0, 3, 5, 0, 1, 2, 0, 1, 0); //������������� ����������� ������� �� ����� A(0,3,5) � ����� ������ O(0,1,2)
	glMatrixMode(GL_MODELVIEW);  //�������� ������� ������
	glEnable(GL_TEXTURE_2D);

	Table(); //��������� �����
	Background(); //��������� ����
	Teapot(); //��������� �������
	Torus(); //��������� �������
	Snack(); //��������� ��������
	Cheese(); //��������� ����
	Bread(); //��������� ��������

	glutSwapBuffers(); //���������� ��������� ��� ��������
	glFlush(); //���������� ����� ����� ����� ���������� ���������� ��������
}

void processSpecialKeys(int key, int x, int y)
{
	switch (key)
	{
		case GLUT_KEY_F1:
			for (; Ybread > 0.003 + HightBurger; Ybread -= 0.002) //��������� ��������
			{
				Draw(); //������������ �����
			}
			HightBurger += 0.12; //������� ��������
			break;
		case GLUT_KEY_F2:
			for (; Ysnack > 0.003 + HightBurger; Ysnack -= 0.002) //��������� ��������
			{
				Draw(); //������������ �����
			}
			HightBurger += 0.05; //������� ��������
			break;
		case GLUT_KEY_F3:
			for (; Ycheese > 0.003 + HightBurger; Ycheese -= 0.002) //��������� ���
			{
				Draw(); //������������ �����
			}
			HightBurger += 0.02; //������� ����
			break;
	}
}

void main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); //����� RGB, ���� � ������� �������, ���� � ������� �������
	glutInitWindowSize(700, 700); //������ ����
	glutCreateWindow("��. 8 �������. ���������� ����"); //��� �������� ���� � ������� ��� �� �������
	Light();
	Texture();
	glutIdleFunc(Draw); //����� ���������� ������ ���, ����� ��� ������� �� ������������
	glutDisplayFunc(Draw); //������� ��������� ��� ���� ����������, ������� ���������� ��� ������������� �������� ��� �������������� �����������
	glutSpecialFunc(processSpecialKeys); //������� ��� ����������� ������� ������
	glutMainLoop(); //����������� ����, �. �. �� ������� �� �������������
}