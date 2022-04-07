#define _USE_MATH_DEFINES

#include <iostream>
#include <glut.h>
#include <glaux.h>
#include <cmath>



unsigned int texture[7]; //количество текстур
float Ybread = 3.0; //высота, где появляется хлебушек
float Ysnack = 3.0; //высота, где появляется колбаска
float Ycheese = 3.0; //высота, где появляется сыр
float HightBurger; //толщина бутерброда

void Texture()
{
	AUX_RGBImageRec *texture1 = auxDIBImageLoadA("table.bmp"),
		*texture2 = auxDIBImageLoadA("teapot.bmp"),
		*texture3 = auxDIBImageLoadA("donut.bmp"),
		*texture4 = auxDIBImageLoadA("snack.bmp"),
		*texture5 = auxDIBImageLoadA("cheese.bmp"),
		*texture6 = auxDIBImageLoadA("bread.bmp"),
		*texture7 = auxDIBImageLoadA("background.bmp");
	glGenTextures(7, &texture[0]); //создание массива текстур
	glBindTexture(GL_TEXTURE_2D, texture[0]); //привязываемся к текстуре фотографии, т. е. делаем ее активной (двумерное изображение, идентификатор)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //параметр текстуры (двумерное изображение, функция для сжатия текстуры, будут использоваться четыре ближайших элемента текстуры)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //параметр текстуры (двумерное изображение, функция для растяжения текстуры, будут использоваться четыре ближайших элемента текстуры)
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
	glEnable(GL_LIGHT0); //инициализация глубинных парпаметров источника света
	glEnable(GL_LIGHTING); //инициализация глубинных парпаметров источника света
	glEnable(GL_DEPTH_TEST); //инициализация глубинных парпаметров источника света
	GLfloat pos[] = { 0.0, 0.0, 1.0, 0.0 }; //последний аргумент 0 - значит источник света находится бесконечно далеко (у нас по оси z, прямо через нас), если 1 - значит на конкретном удалении
	glLightfv(GL_LIGHT0, GL_POSITION, pos);
}

void Table()
{
	//рисуем стол
	glBindTexture(GL_TEXTURE_2D, texture[0]); //вызываем конктретную текстуру для наложения
	glBegin(GL_QUADS); //рисуем стол; каждая отдельная четверка вершин определяет четырехугольник; если задано не кратное четырем число вершин, то последние вершины игнорируются
	glTexCoord2f(0.0, 0.0); glVertex3d(-2.0, 0, -2.0);
	glTexCoord2f(1.0, 0.0); glVertex3d(-2.0, 0, 5.0);
	glTexCoord2f(1.0, 1.0); glVertex3d(2.0, 0, 5.0);
	glTexCoord2f(0.0, 1.0); glVertex3d(2.0, 0, -2.0);
	glEnd();
}

void Background()
{
	//рисуем фон
	glBindTexture(GL_TEXTURE_2D, texture[6]); //вызываем конктретную текстуру для наложения
	glPushMatrix(); //сохраняем текущие координаты
	glBegin(GL_QUADS); //рисуем фон
	glTexCoord2f(1.0, 0.0); glVertex3d(-6.0, -6.0, -3.0);
	glTexCoord2f(1.0, 1.0); glVertex3d(-6.0, 5.0, -3.0);
	glTexCoord2f(0.0, 1.0); glVertex3d(6.0, 5.0, -3.0);
	glTexCoord2f(0.0, 0.0); glVertex3d(6.0, -6.0, -3.0);
	glEnd();
	glPopMatrix(); //возвращаемся к старым координатам
}

void Teapot()
{
	//рисуем чайник
	glBindTexture(GL_TEXTURE_2D, texture[1]); //вызываем конктретную текстуру для наложения
	glPushMatrix(); //сохраняем текущие координаты
	glTranslated(-0.9, 0.4, 0); //сдвигаемся в точку
	glRotated(20, 0, 1, 0); //поворачиваем систему координат на 20 градусов по оси y
	glutSolidTeapot(0.5); //рисуем чайник
	glPopMatrix(); //возвращаемся к старым координатам
}

void Torus(double r = 0.07, double c = 0.15, int rSeg = 32, int cSeg = 64)
{
	//r - радиус кольца
	//c - радиус трубы

	glPushMatrix(); //сохраняем текущие координаты
	glTranslated(0.9, 0.25, 0.5); //сдвигаемся в точку
	glRotated(270, 1, 0, 0); //поворачиваем систему координат на 270 градусов по оси x

	glBindTexture(GL_TEXTURE_2D, texture[2]); //вызываем конктретную текстуру для наложения
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); //GL_REPLACE - в качестве конечного цвета используется цвет точки на текстуре

	const double TAU = 2 * M_PI;

	for (int i = 0; i < rSeg; i++) {
		glBegin(GL_QUAD_STRIP); //четырехугольник с номером n определяется вершинами с номерами 2n-1, 2n, 2n+2, 2n+1
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

	glPopMatrix(); //возвращаемся к старым координатам
}

void Snack()
{
	//рисуем ломник колбасы
	glBindTexture(GL_TEXTURE_2D, texture[3]); //вызываем конктретную текстуру для наложения
	glPushMatrix(); //сохраняем текущие координаты
	glTranslated(0, Ysnack, 2.5); //сдвигаемся в точку
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
	for (int i = -1; i <= segments; i *= -1) //рисуем дно
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
	for (int i = -1; i <= segments; i *= -1) //рисуем верх
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
	glPopMatrix(); //возвращаемся к старым координатам
}

void Cheese()
{
	//рисуем кусочек сыра
	glBindTexture(GL_TEXTURE_2D, texture[4]); //вызываем конктретную текстуру для наложения
	glPushMatrix(); //сохраняем текущие координаты
	glTranslated(0, Ycheese, 2.5); //сдвигаемся в точку
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
	glPopMatrix(); //возвращаемся к старым координатам
}

void Bread()
{
	//рисуем кусочек хлеба
	glBindTexture(GL_TEXTURE_2D, texture[5]); //вызываем конктретную текстуру для наложения
	glPushMatrix(); //сохраняем текущие координаты
	glTranslated(0.45, Ybread, 2.8); //сдвигаемся в точку
	glRotated(180, 0, 1, 0); //поворачиваем систему координат на 180 градусов по оси y

	//нижняя сторона
	glBegin(GL_POLYGON);
	glTexCoord2f(0.025, 0.575); glVertex3f(0.025, 0.0, 0.575); //1 Н
	glTexCoord2f(0.0, 0.315); glVertex3f(0.0, 0.0, 0.315); //2 Н
	glTexCoord2f(0.025, 0.05); glVertex3f(0.025, 0.0, 0.05); //3 Н
	glTexCoord2f(0.1, 0.0); glVertex3f(0.1, 0.0, 0.0); //4 Н
	glTexCoord2f(0.2, 0.1); glVertex3f(0.2, 0.0, 0.1); //5 Н
	glTexCoord2f(0.25, 0.05); glVertex3f(0.25, 0.0, 0.05); //6 Н
	glTexCoord2f(0.9, 0.05); glVertex3f(0.9, 0.0, 0.05); //7 Н
	glTexCoord2f(0.9, 0.575); glVertex3f(0.9, 0.0, 0.575); //8 Н
	glTexCoord2f(0.25, 0.575); glVertex3f(0.25, 0.0, 0.575); //9 Н
	glTexCoord2f(0.2, 0.525); glVertex3f(0.2, 0.0, 0.525); //10 Н
	glTexCoord2f(0.1, 0.625); glVertex3f(0.1, 0.0, 0.625); //11 Н
	glEnd();

	//верхняя сторона
	glBegin(GL_POLYGON);
	glTexCoord2f(0.025, 0.575); glVertex3f(0.025, 0.12, 0.575); //1 В
	glTexCoord2f(0.0, 0.315); glVertex3f(0.0, 0.12, 0.315); //2 В
	glTexCoord2f(0.025, 0.05); glVertex3f(0.025, 0.12, 0.05); //3 В
	glTexCoord2f(0.1, 0.0); glVertex3f(0.1, 0.12, 0.0); //4 В
	glTexCoord2f(0.2, 0.1); glVertex3f(0.2, 0.12, 0.1); //5 В
	glTexCoord2f(0.25, 0.05); glVertex3f(0.25, 0.12, 0.05); //6 В
	glTexCoord2f(0.9, 0.05); glVertex3f(0.9, 0.12, 0.05); //7 В
	glTexCoord2f(0.9, 0.575); glVertex3f(0.9, 0.12, 0.575); //8 В
	glTexCoord2f(0.25, 0.575); glVertex3f(0.25, 0.12, 0.575); //9 В
	glTexCoord2f(0.2, 0.525); glVertex3f(0.2, 0.12, 0.525); //10 В
	glTexCoord2f(0.1, 0.625); glVertex3f(0.1, 0.12, 0.625); //11 В
	glEnd();

	//торец со слабой прожаркой
	glBegin(GL_QUAD_STRIP);
	glVertex3f(0.2, 0.0, 0.1); //5 Н
	glVertex3f(0.2, 0.12, 0.1); //5 В
	glVertex3f(0.25, 0.0, 0.05); //6 Н
	glVertex3f(0.25, 0.12, 0.05); //6 В
	glVertex3f(0.9, 0.0, 0.05); //7 Н
	glVertex3f(0.9, 0.12, 0.05); //7 В
	glVertex3f(0.9, 0.0, 0.575); //8 Н
	glVertex3f(0.9, 0.12, 0.575); //8 В
	glVertex3f(0.575, 0.0, 0.525); //9 Н
	glVertex3f(0.575, 0.12, 0.525); //9 В
	glVertex3f(0.2, 0.0, 0.525); //10 Н
	glVertex3f(0.2, 0.12, 0.525); //10 В
	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0); //устанавливаем "пустую" текстуру, т. к. нам здесь текстура не нужна
	//торец с подгоревшей корочкой
	glBegin(GL_QUAD_STRIP);
	glVertex3f(0.2, 0.0, 0.525); //10 Н
	glVertex3f(0.2, 0.12, 0.525); //10 В
	glVertex3f(0.1, 0.0, 0.625); //11 Н
	glVertex3f(0.1, 0.12, 0.625); //11 В
	glVertex3f(0.025, 0.0, 0.575); //1 Н
	glVertex3f(0.025, 0.12, 0.575); //1 В
	glVertex3f(0.0, 0.0, 0.315); //2 Н
	glVertex3f(0.0, 0.12, 0.315); //2 В
	glVertex3f(0.025, 0.0, 0.05); //3 Н
	glVertex3f(0.025, 0.12, 0.05); //3 В
	glVertex3f(0.1, 0.0, 0.0); //4 Н
	glVertex3f(0.1, 0.12, 0.0); //4 В
	glVertex3f(0.2, 0.0, 0.1); //5 Н
	glVertex3f(0.2, 0.12, 0.1); //5 В
	glEnd();

	glPopMatrix(); //возвращаемся к старым координатам
}

void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //очистка буфера цвета и глубины
	glMatrixMode(GL_PROJECTION); //использование проекционной матрицы для изображения пространственного объекта на плоскости
	glLoadIdentity(); //сбрасываем текущую матрицу

	glFrustum(-1.0, 1.0, -1.0, 1.0, 2, 20.0); //задаёт систему координат с параллелепипедом видимости, внутри которого расположен объект (камера - это точка, видимый объем - как в кинотеатре)
	gluLookAt(0, 3, 5, 0, 1, 2, 0, 1, 0); //устанавливает направление взгляда от точки A(0,3,5) в центр фигуры O(0,1,2)
	glMatrixMode(GL_MODELVIEW);  //загрузка видовой матрцы
	glEnable(GL_TEXTURE_2D);

	Table(); //отрисовка стола
	Background(); //отрисовка фона
	Teapot(); //отрисовка чайника
	Torus(); //отрисовка пончика
	Snack(); //отрисовка колбаски
	Cheese(); //отрисовка сыра
	Bread(); //отрисовка хлебушка

	glutSwapBuffers(); //управление массивами при анимации
	glFlush(); //прорисовка кадра будет после ближайшего обновления монитора
}

void processSpecialKeys(int key, int x, int y)
{
	switch (key)
	{
		case GLUT_KEY_F1:
			for (; Ybread > 0.003 + HightBurger; Ybread -= 0.002) //анимируем хлебушек
			{
				Draw(); //отрисовываем сцену
			}
			HightBurger += 0.12; //толщина хлебушка
			break;
		case GLUT_KEY_F2:
			for (; Ysnack > 0.003 + HightBurger; Ysnack -= 0.002) //анимируем колбаску
			{
				Draw(); //отрисовываем сцену
			}
			HightBurger += 0.05; //толщина колбаски
			break;
		case GLUT_KEY_F3:
			for (; Ycheese > 0.003 + HightBurger; Ycheese -= 0.002) //анимируем сыр
			{
				Draw(); //отрисовываем сцену
			}
			HightBurger += 0.02; //толщина сыра
			break;
	}
}

void main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); //режим RGB, окно с двойным буфером, окно с буфером глубины
	glutInitWindowSize(700, 700); //размер окна
	glutCreateWindow("КГ. 8 вариант. Бондаренко Артём"); //даёт название окну и выводит его на дисплей
	Light();
	Texture();
	glutIdleFunc(Draw); //будет вызываться каждый раз, когда нет событий от пользователя
	glutDisplayFunc(Draw); //функция рисования для окна приложения, которая вызывается при необходимости создания или восстановления изображения
	glutSpecialFunc(processSpecialKeys); //функция для специальных нажатий клавиш
	glutMainLoop(); //бесконечный цикл, т. е. он никогда не заканчивается
}