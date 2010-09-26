// G1_Ilum.cpp : Defines the entry point for the console application.
//

#include <GL/glui.h>
#include <math.h>
#include "RGBpixmap.h"

// dimensoes e localizacao da janela
#define DIMX 1000
#define DIMY 800
#define INITIALPOS_X 200
#define INITIALPOS_Y 50

//posicao de visualizacao
float VposX = 20.0;
float VposY = 10.0;
float VangleX = 40.0;
float VangleY = 0.0;
float zoom = 50;

//definicao das listas
int chaoEArvores = 1;
int hospital = 2;
int heliporto = 3;

float corFundo[3] = {0.41, 0.76, 0.98};

// dimensoes do chao
float PosChaoZ1 = 0.0;
float PosChaoZ2 = -30.0;
float PosChaoEX1 = 0.0;
float PosChaoEX2 = 15.0;
float PosChaoCX1 = 15.0;
float PosChaoCX2 = 30.0;
float PosChaoDX1 = 30.0;
float PosChaoDX2 = 45.0;

// posicao dos holofotes
float holo1X = 17.25;
float holo1Z = -3.75;
float holo2X = 27.75;
float holo2Z = -11.25;

//posicao das arvores e alturas desenhadas
float arv1X = 5.0;
float arv1Z = -25.0;
float heightA1 = 7.0;
float arv2X = 10.0;
float arv2Z = -15.0;
float heightA2 = 5.0;
float arv3X = 5.0;
float arv3Z = -10.0;
float heightA3 = 5.5;
float arv4X = 7.5;
float arv4Z = -20.0;
float heightA4 = 6.5;
float normal1AT2[3] = {0.0,0.0,1.0};
float normal2AT2[3] = {1.0,0.0,1.0};

// escala das texturas
float escala = 15.0;
float escalaT = 2.0;

// dimensoes dos holofotes
float raioPoste = 0.15;
float alturaPoste = 4.7;
float raioHolo1 = 0.65;
float raioHolo2 = 0.35;
float alturaHolo = 0.7;

// dimensoes do heliporto
float heliComp = 10.5;
float heliLarg = 7.5;
float heliDiv = 150.0;
GLfloat ctrlpoints[4][3] = {	{  -heliComp/2, 0.0, heliLarg/2},
								{  -heliComp/2, 0.0, -heliLarg/2},
								{  heliComp/2, 0.0, heliLarg/2},
								{  heliComp/2, 0.0, -heliLarg/2}};

GLfloat nrmlcompon[4][3] = {	{  0.0, 1.0, 0.0},
								{  0.0, 1.0, 0.0}, 
								{  0.0, 1.0, 0.0},
								{  0.0, 1.0, 0.0} };

GLfloat textpoints[4][2] = {	{ 0.0, 0.0},
								{ 0.0, 1.0}, 
								{ 1.0, 0.0},
								{ 1.0, 1.0} };
// dimensoes da arvore de tipo 1
float raioTInf = 0.3;
float raioTSup = 0.0;
float slicesT1 = 20.0;
float stacksT1 = 20.0;
float alturaA1 = 2.0;
float escalaTB = 4.0;

// dimensoes da arvore de tipo 2
float tamFolhaX = 1.0;
float tamFolhaY = 4.0;
float razTroncFolha = 1.2;
float rAltuLargA2 = 3.0;


// dimensoes e cor do hospital
float corHospital[3] = {1.0,0.9,0.61};
float corPorta[3] = {0.54,0.27,0.0};
float corLetreiro[3] = {0.0,1.0,0.0};
float hospAlt = 11.5;
float hospLarg = 11.5;
float hospProf = 7.0;
float alturaPorta = 3.0;
float larguraPorta = 2.0;
float telhadoLarg = 8.5;
float telhadoComp = 13.0;
float telhadoAresta = 6.5;
float telhadoAlt = 1.0;
float escalaLetr = 0.02;
float tamanhoLetr = 3.0;

const int TRUE  = 1;
const int FALSE = 0;

float xy_aspect;

// matriz de transf. geometrica utilizada pelo botao esferico
float view_rotate[16] = { 1,0,0,0,
                          0,1,0,0,
                          0,0,1,0,
                          0,0,0,1 };

// vector de posicao utilizado pelo botao de afastamento
float obj_pos[] = { 0.0, 0.0, 0.0 };

// declarações para os tres eixos (cilindros)
float axis_radius_begin =  0.2;
float axis_radius_end   =  0.0;
float axis_lenght       = 16.0;
int axis_nslices = 8;
int axis_nstacks = 1;

// declaracoes para as paredes
float mat1_shininess[] = {128.0}; 
float mat1_specular[] = {0.3, 0.3, 0.3, 1.0};	/* specular reflection. */
float mat1_diffuse[] =  {0.7, 0.7, 0.7, 1.0};	/* diffuse reflection. */
float mat1_ambient[] =  {0.7, 0.7, 0.7, 1.0};	/* ambient reflection. */

// declarações para a fonte de luz LIGHT0;
float light0_position[]  = {0.0, 3.0, 4.0, 1.0}; // nao necessaria...
float light0_ambient[] =   {0.0, 0.0, 0.0, 1.0}; // sem componente ambiente
float light0_diffuse[] =   {6.0, 6.0, 6.0, 1.0};
float light0_specular[] =  {6.0, 6.0, 6.0, 1.0};
float light0_kc = 0.0;
float light0_kl = 1.0;
float light0_kq = 0.0;
float light0x = holo1X+4*raioPoste;
float light0y = alturaPoste-2*raioPoste;
float light0z = holo1Z-4*raioPoste;
float symb_light0_radius = 0.2;
int symb_light0_slices = 8;
int symb_light0_stacks =8;

// declarações para a fonte de luz LIGHT1;
float light1_position[]  = {0.0, 3.0, 4.0, 1.0}; // nao necessaria...
float light1_ambient[] =   {0.0, 0.0, 0.0, 1.0}; // sem componente ambiente
float light1_diffuse[] =   {6.0, 6.0, 6.0, 1.0};
float light1_specular[] =  {6.0, 6.0, 6.0, 1.0};
float light1_kc = 0.0;
float light1_kl = 1.0;
float light1_kq = 0.0;
float light1x = holo2X-4*raioPoste;
float light1y = alturaPoste-2*raioPoste;
float light1z = holo1Z-4*raioPoste;
float symb_light1_radius = 0.2;
int symb_light1_slices = 8;
int symb_light1_stacks =8;

// declarações para a fonte de luz LIGHT2;
float light2_position[]  = {0.0, 3.0, 4.0, 1.0}; // nao necessaria...
float light2_ambient[] =   {0.0, 0.0, 0.0, 1.0}; // sem componente ambiente
float light2_diffuse[] =   {6.0, 6.0, 6.0, 1.0};
float light2_specular[] =  {6.0, 6.0, 6.0, 1.0};
float light2_kc = 0.0;
float light2_kl = 1.0;
float light2_kq = 0.0;
float light2x = holo2X-4*raioPoste;
float light2y = alturaPoste-2*raioPoste;
float light2z = holo2Z+4*raioPoste;
float symb_light2_radius = 0.2;
int symb_light2_slices = 8;
int symb_light2_stacks =8;

// declarações para a fonte de luz LIGHT3;
float light3_position[]  = {0.0, 3.0, 4.0, 1.0}; // nao necessaria...
float light3_ambient[] =   {0.0, 0.0, 0.0, 1.0}; // sem componente ambiente
float light3_diffuse[] =   {6.0, 6.0, 6.0, 1.0};
float light3_specular[] =  {6.0, 6.0, 6.0, 1.0};
float light3_kc = 0.0;
float light3_kl = 1.0;
float light3_kq = 0.0;
float light3x = holo1X+4*raioPoste;
float light3y = alturaPoste-2*raioPoste;
float light3z = holo2Z+4*raioPoste;
float symb_light3_radius = 0.2;
int symb_light3_slices = 8;
int symb_light3_stacks =8;


// fonte (global) de luz ambiente 
float light_ambient[] = {0.6, 0.6, 0.6, 1.0}; /* Set the background ambient lighting. */


// variaveis para a janela
int main_window;
GLUI  *glui2;


RGBpixmap pixmap;

void desenhaRecXZ(float x1, float z1, float x2, float z2, int imagem)
{
	glBindTexture(GL_TEXTURE_2D, imagem);
	glBegin(GL_POLYGON);
		glNormal3d(0.0,1.0,0.0);  // esta normal fica comum aos 4 vertices
		glTexCoord2f(0.0,0.0); glVertex3d( x1, 0.0,  z1);
		glTexCoord2f(escala/2,0.0); glVertex3d(x2, 0.0,  z1);
		glTexCoord2f(escala/2,escala); glVertex3d(x2, 0.0,  z2);
		glTexCoord2f(0.0,escala); glVertex3d(x1, 0.0,  z2);
	glEnd();
}

void desenhaRecXZ2(float x1, float z1, float x2, float z2, int imagem)
{
	glBindTexture(GL_TEXTURE_2D, imagem);
	glBegin(GL_POLYGON);
		glNormal3d(0.0,-1.0,0.0);  // esta normal fica comum aos 4 vertices
		glTexCoord2f(0.0,0.0); glVertex3d( x1, 0.0,  z1);
		glTexCoord2f(0.0,escala); glVertex3d(x1, 0.0,  z2);
		glTexCoord2f(escala/2,escala); glVertex3d(x2, 0.0,  z2);
		glTexCoord2f(escala/2,0.0); glVertex3d(x2, 0.0,  z1);
	glEnd();
}

void desenhaTrianguloXY(float x1, float y1, float x2, float y2, int imagem, float normal[3])
{
	glBindTexture(GL_TEXTURE_2D, imagem);
	glBegin(GL_POLYGON);
		glNormal3d(normal[0],normal[1],normal[2]);  // esta normal fica comum aos 4 vertices
		glTexCoord2f(0.0,0.0); glVertex3d(-x2, y1, 0.0);
		glTexCoord2f(escala/2,escala); glVertex3d(x2,y1,0.0);
		glTexCoord2f(escala/2,0.0); glVertex3d(0.0, y2, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
		glNormal3d(-normal[0],-normal[1],-normal[2]);  // esta normal fica comum aos 4 vertices
		glTexCoord2f(escala/2,escala); glVertex3d(x2,y1,0.0);
		glTexCoord2f(0.0,0.0); glVertex3d(-x2, y1, 0.0);
		glTexCoord2f(escala/2,0.0); glVertex3d(0.0, y2, 0.0);
	glEnd();
}

void desenhaHospital(GLUquadric * quad)
{
	// edificio
	float tamanhoCubo = 1.0;
	
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(corHospital[0], corHospital[1], corHospital[2]);
	glPushMatrix();
	glTranslatef((PosChaoCX1+PosChaoCX2)/2,hospAlt/2,3*(PosChaoZ2/4));
	glScalef(hospLarg,hospAlt,hospProf);
	glutSolidCube(tamanhoCubo);
	glPopMatrix();
	//glDisable(GL_DEPTH_TEST); //desactiva temporariamente o uso do z-buffer
	
	// porta
	glPushMatrix();
	glTranslatef((PosChaoCX1+PosChaoCX2)/2-larguraPorta/2,0.0,(PosChaoZ2/4)*3+(hospProf/2)+0.01);
	glColor3f(corPorta[0], corPorta[1], corPorta[2]);
	glBegin(GL_POLYGON);
		glNormal3d(0.0,0.0,1.0);  // esta normal fica comum aos 4 vertices
		glVertex3d( 0.0, 0.0,  0.0);
		glVertex3d(larguraPorta, 0.0, 0.0);
		glVertex3d(larguraPorta, alturaPorta, 0.0);
		glVertex3d(0.0, alturaPorta, 0.0);
	glEnd();
	glPopMatrix();
	
	//letreiro HJS
	glPushMatrix();
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glEnable(GL_LINE_SMOOTH);
	glLineWidth(tamanhoLetr);
	glTranslatef((PosChaoCX1+PosChaoCX2)/2-104.76*escalaLetr,hospAlt,3*(PosChaoZ2/4)+telhadoLarg/2);
	glScalef(escalaLetr, escalaLetr, escalaLetr);
	glColor3f(corLetreiro[0], corLetreiro[1], corLetreiro[2]);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, 'H');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, 'S');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, 'J');

	glPopMatrix();

	glDisable(GL_COLOR_MATERIAL);
	// Definicao de material a usar daqui em diante (valores declarados acima)
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat1_shininess);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,  mat1_specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,   mat1_diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,   mat1_ambient);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 7);

	//telhado
	glPushMatrix();
	glTranslatef((PosChaoCX1+PosChaoCX2)/2,hospAlt,3*(PosChaoZ2/4));
	desenhaRecXZ2(-telhadoComp/2, telhadoLarg/2, telhadoComp/2, -telhadoLarg/2, 7);
	glPopMatrix();
	
	
	//triangulos
	//calcular o vector normal dos triângulos
	float vTri1[3] = {0.0, 0.0, 1.0};
	float vTri2[3] = {(telhadoComp-telhadoAresta)/2, telhadoAlt, telhadoLarg/2};
	float vTriNor[3] = {vTri1[1]*vTri2[2]-vTri1[2]*vTri2[1], vTri1[2]*vTri2[0]-vTri1[0]*vTri2[2], vTri1[0]*vTri2[1]-vTri1[1]*vTri2[0]}; 
	float normaVec = sqrt(vTriNor[0]*vTriNor[0]+vTriNor[1]*vTriNor[1]+vTriNor[2]*vTriNor[2]);
	int i = 0;
	for(i; i < 3; i++) vTriNor[i] = vTriNor[i]/normaVec;

	glPushMatrix();
	glTranslatef((PosChaoCX1+PosChaoCX2)/2-telhadoComp/2,hospAlt,3*(PosChaoZ2/4));
	glBegin(GL_POLYGON);
		glNormal3d(vTriNor[0],vTriNor[1],vTriNor[2]);  // esta normal fica comum aos 3 vertices
		glTexCoord2f(0.0,0.0);	glVertex3d(0.0, 0.0, -telhadoLarg/2);
		glTexCoord2f(escalaT,0.0);	glVertex3d(0.0,0.0,telhadoLarg/2);
		glTexCoord2f(escalaT/2,escalaT);	glVertex3d((telhadoComp-telhadoAresta)/2, telhadoAlt, 0.0);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef((PosChaoCX1+PosChaoCX2)/2+telhadoComp/2,hospAlt,3*(PosChaoZ2/4));
	glBegin(GL_POLYGON);
		glNormal3d(-vTriNor[0],vTriNor[1],vTriNor[2]);  // esta normal fica comum aos 3 vertices
		glTexCoord2f(0.0,0.0); glVertex3d(0.0, 0.0, -telhadoLarg/2);
		glTexCoord2f(escalaT/2,escalaT); glVertex3d(-(telhadoComp-telhadoAresta)/2, telhadoAlt, 0.0);
		glTexCoord2f(escalaT,0.0); glVertex3d(0.0,0.0,telhadoLarg/2);
	glEnd();
	glPopMatrix();
	

	//quadrilateros
	//calcular o vector normal dos quadrilateros
	float vQuad1[3] = {1.0, 0.0, 0.0};
	float vQuad2[3] = {-(telhadoComp-telhadoAresta)/2-telhadoComp/2, telhadoAlt, -telhadoLarg/2};
	float vQuadNor[3] = {vQuad1[1]*vQuad2[2]-vQuad1[2]*vQuad2[1], vQuad1[2]*vQuad2[0]-vQuad1[0]*vQuad2[2], vQuad1[0]*vQuad2[1]-vQuad1[1]*vQuad2[0]}; 
	float normaVecQuad = sqrt(vQuadNor[0]*vQuadNor[0]+vQuadNor[1]*vQuadNor[1]+vQuadNor[2]*vQuadNor[2]);
	for(i=0; i < 3; i++) vQuadNor[i] = vQuadNor[i]/normaVecQuad;

	glPushMatrix();
	glTranslatef((PosChaoCX1+PosChaoCX2)/2,hospAlt,3*(PosChaoZ2/4)+telhadoLarg/2);
	glBegin(GL_POLYGON);
		glNormal3d(vQuadNor[0],vQuadNor[1],vQuadNor[2]);  // esta normal fica comum aos 4 vertices
		glTexCoord2f(0.0,0.0); glVertex3d(-telhadoComp/2, 0.0, 0.0);
		glTexCoord2f(escalaT,0.0); glVertex3d(telhadoComp/2, 0.0, 0.0);
		glTexCoord2f(3*(escalaT/4),escalaT); glVertex3d((telhadoComp-telhadoAresta)/2,telhadoAlt,-telhadoLarg/2);
		glTexCoord2f(escalaT/4,escalaT); glVertex3d(-(telhadoComp-telhadoAresta)/2,telhadoAlt,-telhadoLarg/2);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef((PosChaoCX1+PosChaoCX2)/2,hospAlt,3*(PosChaoZ2/4)-telhadoLarg/2);
	glBegin(GL_POLYGON);
		glNormal3d(vQuadNor[0],vQuadNor[1],-vQuadNor[2]);  // esta normal fica comum aos 4 vertices
		glTexCoord2f(0.0,0.0); glVertex3d(-telhadoComp/2, 0.0, 0.0);
		glTexCoord2f(escalaT/4,escalaT); glVertex3d(-(telhadoComp-telhadoAresta)/2,telhadoAlt,telhadoLarg/2);
		glTexCoord2f(3*(escalaT/4),escalaT); glVertex3d((telhadoComp-telhadoAresta)/2,telhadoAlt,telhadoLarg/2);
		glTexCoord2f(escalaT,0.0); glVertex3d(telhadoComp/2, 0.0, 0.0);
	glEnd();
	glPopMatrix();
	
	glDisable(GL_TEXTURE_2D);
	//glEnable(GL_DEPTH_TEST);
	
}

void desenhaHolofotes(GLUquadric * quad)
{

	gluQuadricTexture(quad, GL_TRUE);
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 8);
	// postes dos holofotes
	// poste1
	glPushMatrix();
	glTranslatef(holo1X,0.0,holo1Z);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(quad, raioPoste, raioPoste, alturaPoste, slicesT1, stacksT1);
	glTranslatef(0.0,0.0,alturaPoste);
	gluDisk(quad,0.0,raioPoste,slicesT1, stacksT1);
	glPopMatrix();
	// poste2
	glPushMatrix();
	glTranslatef(holo2X,0.0,holo1Z);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(quad, raioPoste, raioPoste, alturaPoste, slicesT1, stacksT1);
	glTranslatef(0.0,0.0,alturaPoste);
	gluDisk(quad,0.0,raioPoste,slicesT1, stacksT1);
	glPopMatrix();
	// poste3
	glPushMatrix();
	glTranslatef(holo2X,0.0,holo2Z);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(quad, raioPoste, raioPoste, alturaPoste, slicesT1, stacksT1);
	glTranslatef(0.0,0.0,alturaPoste);
	gluDisk(quad,0.0,raioPoste,slicesT1, stacksT1);
	glPopMatrix();
	// poste4
	glPushMatrix();
	glTranslatef(holo1X,0.0,holo2Z);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(quad, raioPoste, raioPoste, alturaPoste, slicesT1, stacksT1);
	glTranslatef(0.0,0.0,alturaPoste);
	gluDisk(quad,0.0,raioPoste,slicesT1, stacksT1);
	glPopMatrix();
	
	glDisable(GL_CULL_FACE);
	glDisable(GL_TEXTURE_2D);
	
	// holofotes
	// holofote1
	glPushMatrix();
	glTranslatef(holo1X+4*raioPoste,alturaPoste-2*raioPoste,holo1Z-4*raioPoste);
	glRotatef(-45.0, 0.0, 1.0, 0.0);
	glRotatef(-45.0, 1.0, 0.0, 0.0);
	gluCylinder(quad, raioHolo1, raioHolo2, alturaHolo, slicesT1, stacksT1);
	glTranslatef(0.0,0.0,alturaHolo);
	gluDisk(quad,0.0,raioHolo2,slicesT1, stacksT1);
	glPopMatrix();
	// holofote2
	glPushMatrix();
	glTranslatef(holo2X-4*raioPoste,alturaPoste-2*raioPoste,holo1Z-4*raioPoste);
	glRotatef(45.0, 0.0, 1.0, 0.0);
	glRotatef(-45.0, 1.0, 0.0, 0.0);
	gluCylinder(quad, raioHolo1, raioHolo2, alturaHolo, slicesT1, stacksT1);
	glTranslatef(0.0,0.0,alturaHolo);
	gluDisk(quad,0.0,raioHolo2,slicesT1, stacksT1);
	glPopMatrix();
	// holofote3
	glPushMatrix();
	glTranslatef(holo2X-4*raioPoste,alturaPoste-2*raioPoste,holo2Z+4*raioPoste);
	glRotatef(135.0, 0.0, 1.0, 0.0);
	glRotatef(-45.0, 1.0, 0.0, 0.0);
	gluCylinder(quad, raioHolo1, raioHolo2, alturaHolo, slicesT1, stacksT1);
	glTranslatef(0.0,0.0,alturaHolo);
	gluDisk(quad,0.0,raioHolo2,slicesT1, stacksT1);
	glPopMatrix();
	// holofote4
	glPushMatrix();
	glTranslatef(holo1X+4*raioPoste,alturaPoste-2*raioPoste,holo2Z+4*raioPoste);
	glRotatef(-135.0, 0.0, 1.0, 0.0);
	glRotatef(-45.0, 1.0, 0.0, 0.0);
	gluCylinder(quad, raioHolo1, raioHolo2, alturaHolo, slicesT1, stacksT1);
	glTranslatef(0.0,0.0,alturaHolo);
	gluDisk(quad,0.0,raioHolo2,slicesT1, stacksT1);
	glPopMatrix();
	glEnable(GL_CULL_FACE);
}

void desenhaHeliporto()
{
	glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 2,  0.0, 1.0, 6, 2,  &ctrlpoints[0][0]);
	glMap2f(GL_MAP2_NORMAL,   0.0, 1.0, 3, 2,  0.0, 1.0, 6, 2,  &nrmlcompon[0][0]);
	glMap2f(GL_MAP2_TEXTURE_COORD_2,  0.0, 1.0, 2, 2,  0.0, 1.0, 4, 2,  &textpoints[0][0]);

	// os interpoladores activam-se:
	glEnable(GL_MAP2_VERTEX_3);
	glEnable(GL_MAP2_NORMAL);
	glEnable(GL_MAP2_TEXTURE_COORD_2);

	glMapGrid2f(heliDiv, 0.0,1.0, heliDiv, 0.0,1.0); 

	//glShadeModel(GL_FLAT);					// GL_FLAT, GL_SMOOTH
	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 9);
	glPushMatrix();
	glTranslatef((PosChaoCX1+PosChaoCX2)/2,0.01,(PosChaoZ2/4));
	glEvalMesh2(GL_FILL, 0,heliDiv, 0,heliDiv);		// GL_POINT, GL_LINE, GL_FILL
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void desenhaChao()
{
	glEnable(GL_TEXTURE_2D);
	desenhaRecXZ(PosChaoEX1,PosChaoZ1,PosChaoEX2,PosChaoZ2, 1);
	desenhaRecXZ(PosChaoCX1,PosChaoZ1,PosChaoCX2,PosChaoZ2, 2);
	desenhaRecXZ(PosChaoDX1,PosChaoZ1,PosChaoDX2,PosChaoZ2,3);
	glDisable(GL_TEXTURE_2D);
}

void desenhaArvoreT1(GLUquadric * quad, float posX, float posZ, float height)
{
	gluQuadricTexture(quad, GL_TRUE);
	glEnable(GL_TEXTURE_2D);

	// tronco
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, 4);
	glTranslatef(posX,0.0,posZ);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(quad, raioTInf, raioTSup, height, slicesT1, stacksT1);
	glPopMatrix();

	// folhagem
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, 5);
	glTranslatef(posX,alturaA1,posZ);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(quad, raioTInf*escalaTB, raioTSup, height-alturaA1, slicesT1, stacksT1);
	glPopMatrix();
	
	glDisable(GL_TEXTURE_2D);
	gluQuadricTexture(quad, GL_FALSE);
}

void desenhaArvoreT2(GLUquadric * quad, float posX, float posZ, float height)
{
	gluQuadricTexture(quad, GL_TRUE);
	glEnable(GL_TEXTURE_2D);

	// tronco
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, 4);
	glTranslatef(posX,0.0,posZ);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(quad, raioTInf, raioTSup, height, slicesT1, stacksT1);
	glPopMatrix();
	
	// folhagem 1
	glPushMatrix();
	glTranslatef(posX, height-height/razTroncFolha, posZ);
	desenhaTrianguloXY(0.0,0.0,height/rAltuLargA2,height/razTroncFolha, 6, normal1AT2);
	glPopMatrix();
	
	// folhagem 2
	glPushMatrix();
	glTranslatef(posX, height-height/razTroncFolha, posZ);
	glRotatef(-90.0, 0.0, 1.0, 0.0);
	desenhaTrianguloXY(0.0,0.0,height/rAltuLargA2, height/razTroncFolha, 6, normal1AT2);
	glPopMatrix();
	
	// folhagem 3
	glPushMatrix();
	glTranslatef(posX, height-height/razTroncFolha, posZ);
	glRotatef(45.0, 0.0, 1.0, 0.0);
	desenhaTrianguloXY(0.0,0.0,height/rAltuLargA2,height/razTroncFolha, 6, normal2AT2);
	glPopMatrix();
	
	// folhagem 4
	glPushMatrix();
	glTranslatef(posX, height-height/razTroncFolha, posZ);
	glRotatef(-45.0, 0.0, 1.0, 0.0);
	desenhaTrianguloXY(0.0,0.0,height/rAltuLargA2,height/razTroncFolha, 6, normal2AT2);
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	gluQuadricTexture(quad, GL_FALSE);

}

void display(void)
{

	// ****** declaracoes internas 'a funcao display() ******
	
	//float temp;

	GLUquadric* glQ;	// nec. p/ criar sup. quadraticas (cilindros, esferas...)

	// ****** fim de todas as declaracoes da funcao display() ******

	glQ = gluNewQuadric();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
	// inicializacoes da matriz de visualizacao
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glFrustum( -xy_aspect*.04, xy_aspect*.04, -.04, .04, .1, 500.0 );

	//inicializacoes da matriz de transformacoes geometricas
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	
	// afasta a cena de 25 unidades mais a distância que...
	// ...decorre da utilizacao do botao de afastamento (pseudo-zoom)
    glTranslatef( obj_pos[0]-VposX, obj_pos[1]-VposY, -obj_pos[2]-zoom );
		// tambem se poderia ter feito:
		//glTranslated(0.0,0.0,-25.0);
		//glTranslatef( obj_pos[0], obj_pos[1], -obj_pos[2] );

	// roda a cena para ficar em perspectiva
	glRotated( VangleX, 1.0,0.0,0.0 );		// 20 graus em torno de X
	glRotated( VangleY, 0.0,1.0,0.0 );		//-45 graus em torno de Y

	// roda a cena de acordo com o botao (esfera) de rotacao
	glMultMatrixf( view_rotate );

	// permissao de atribuicao directa de cores
	// para objectos que nao tem material atribuido, como
	// e' o caso dos eixos e da esfera que simboliza a fonte de luz...
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);


	// cilindro representativo do eixo X
	glColor3f(1.0,0.0,0.0);		// vermelho
	glPushMatrix();
	glRotated(90.0, 0.0,1.0,0.0 );
	gluCylinder(glQ, axis_radius_begin, axis_radius_end,
		             axis_lenght, axis_nslices, axis_nstacks);   // nao tem bases
	glPopMatrix();

	// cilindro representativo do eixo Y
	glColor3f(0.0,1.0,0.0);		// verde
	glPushMatrix();
	glRotated(-90.0, 1.0,0.0,0.0 );
	gluCylinder(glQ, axis_radius_begin, axis_radius_end,
		             axis_lenght, axis_nslices, axis_nstacks);   // nao tem bases
	glPopMatrix();
	
	// cilindro representativo do eixo Z
	glColor3f(0.0,0.0,1.0);		// azul
	glPushMatrix();
	// nao necessita rotacao... glRotated(...);
	gluCylinder(glQ, axis_radius_begin, axis_radius_end,
		             axis_lenght, axis_nslices, axis_nstacks);   // nao tem bases
	glPopMatrix();

	// Actualizacao da posicao da fonte de luz...
	light0_position[0] = light0x;	// por razoes de eficiencia, os restantes 
	light0_position[1] = light0y;	// parametros _invariaveis_ da LIGHT0 mantem os valores
	light0_position[2] = light0z;	// definidos na funcao de inicializacao
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);

	// Actualizacao da posicao da fonte de luz2...
	light1_position[0] = light1x;	// por razoes de eficiencia, os restantes 
	light1_position[1] = light1y;	// parametros _invariaveis_ da light1 mantem os valores
	light1_position[2] = light1z;	// definidos na funcao de inicializacao
	glLightfv(GL_LIGHT1, GL_POSITION, light1_position);

	// Actualizacao da posicao da fonte de luz3...
	light2_position[0] = light2x;	// por razoes de eficiencia, os restantes 
	light2_position[1] = light2y;	// parametros _invariaveis_ da light2 mantem os valores
	light2_position[2] = light2z;	// definidos na funcao de inicializacao
	glLightfv(GL_LIGHT2, GL_POSITION, light2_position);

	// Actualizacao da posicao da fonte de luz4...
	light3_position[0] = light3x;	// por razoes de eficiencia, os restantes 
	light3_position[1] = light3y;	// parametros _invariaveis_ da light3 mantem os valores
	light3_position[2] = light3z;	// definidos na funcao de inicializacao
	glLightfv(GL_LIGHT3, GL_POSITION, light3_position);

	// ... e da esfera que a simboliza
	glColor3f(1.0,1.0,0.0);		// cor amarela
	gluQuadricOrientation( glQ, GLU_INSIDE);
	glPushMatrix();
	glTranslated(light0x,light0y,light0z);
	gluSphere(glQ, symb_light0_radius, symb_light0_slices, symb_light0_stacks);
    glPopMatrix();
	gluQuadricOrientation( glQ, GLU_OUTSIDE);

	// ... e da esfera que a simboliza2
	glColor3f(1.0,1.0,0.0);		// cor amarela
	gluQuadricOrientation( glQ, GLU_INSIDE);
	glPushMatrix();
	glTranslated(light1x,light1y,light1z);
	gluSphere(glQ, symb_light1_radius, symb_light1_slices, symb_light1_stacks);
    glPopMatrix();
	gluQuadricOrientation( glQ, GLU_OUTSIDE);

	// ... e da esfera que a simboliza3
	glColor3f(1.0,1.0,0.0);		// cor amarela
	gluQuadricOrientation( glQ, GLU_INSIDE);
	glPushMatrix();
	glTranslated(light2x,light2y,light2z);
	gluSphere(glQ, symb_light2_radius, symb_light2_slices, symb_light2_stacks);
    glPopMatrix();
	gluQuadricOrientation( glQ, GLU_OUTSIDE);

	// ... e da esfera que a simboliza4
	glColor3f(1.0,1.0,0.0);		// cor amarela
	gluQuadricOrientation( glQ, GLU_INSIDE);
	glPushMatrix();
	glTranslated(light3x,light3y,light3z);
	gluSphere(glQ, symb_light3_radius, symb_light3_slices, symb_light3_stacks);
    glPopMatrix();
	gluQuadricOrientation( glQ, GLU_OUTSIDE);
	
	glDisable(GL_COLOR_MATERIAL);
	// Definicao de material a usar daqui em diante (valores declarados acima)
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat1_shininess);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,  mat1_specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,   mat1_diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,   mat1_ambient);
	
	//chamada das funções
	glCallList(chaoEArvores);
	glCallList(hospital);
	glCallList(heliporto);
	
	// swapping the buffers causes the rendering above to be shown
	glutSwapBuffers();
	glFlush();
}

/* Mouse handling */
void processMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{	 
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{	
	}
	
	glutPostRedisplay();
	
}

void processMouseMoved(int x, int y)
{
	
	// pedido de refrescamento da janela
	glutPostRedisplay();				

}

void processPassiveMouseMoved(int x, int y)
{

	// pedido de refrescamento da janela
	glutPostRedisplay();				
}

void reshape(int w, int h)
{
	int tx, ty, tw, th;

	GLUI_Master.get_viewport_area( &tx, &ty, &tw, &th );
	glViewport( tx, ty, tw, th );
	xy_aspect = (float)tw / (float)th;

	glutPostRedisplay();

}


void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 27:		// tecla de escape termina o programa
         exit(0);
         break;
	  case 'd':
		 light0x += 0.1;
		 break;	
	  case 'a':
		 light0x -= 0.1;
		 break;	
	  case 'w':
		 light0z -= 0.1;
		 break;	
	  case 's':
		 light0z += 0.1;
		 break;
	  case 'l':
		 VposX += 1.0;
		 break;	
	  case 'j':
		 VposX -= 1.0;
		 break;	
	  case 'k':
		 zoom += 1.0;
		 break;	
	  case 'i':
		 zoom -= 1.0;
		 break;	
	  case 'y':
		 VposY += 1.0;
		 break;	
	  case 'h':
		 VposY -= 1.0;
		 break;	
	  case '8':
		 VangleX += 1.0;
		 break;	
	  case '2':
		 VangleX -= 1.0;
		 break;	
	  case '6':
		 VangleY += 1.0;
		 break;	
	  case '4':
		 VangleY -= 1.0;
		 break;
	  case '5':
		  {
			VposX = 20.0;
			VposY = 10.0;
			VangleX = 40.0;
			VangleY = 0.0;
			zoom = 50;
			break;
		  }
   }
}


void myGlutIdle( void )
{
  /* According to the GLUT specification, the current window is 
     undefined during an idle callback.  So we need to explicitly change
     it if necessary */
  if ( glutGetWindow() != main_window ) 
    glutSetWindow(main_window);  


  glutPostRedisplay();

}

void inicializacao()
{

	glFrontFace(GL_CCW);		// Front faces defined using a counterclockwise rotation
	glDepthFunc(GL_LEQUAL);		// Por defeito e GL_LESS
	glEnable(GL_DEPTH_TEST);	// Use a depth (z) buffer to draw only visible objects


	// Face Culling para aumentar a velocidade
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);		// GL_FRONT, GL_BACK, GL_FRONT_AND_BACK


	// Define que modelo de iluminacao utilizar; consultar o manual de referencia
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, light_ambient);  // define luz ambiente
	glLightModelf (GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
	glLightModeli (GL_LIGHT_MODEL_LOCAL_VIEWER, 1);
	
	// por defeito a cor de fundo e o preto
	glClearColor(corFundo[0], corFundo[1], corFundo[2], 1.0);    // cor de fundo a branco


	// declaracoes para a fonte luz GL_LIGHT0
	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);
	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION,  light0_kc);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION,    light0_kl);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, light0_kq);

	// declaracoes para a fonte luz GL_LIGHT1
	glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION,  light1_kc);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION,    light1_kl);
	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, light1_kq);

	// declaracoes para a fonte luz GL_LIGHT2
	glLightfv(GL_LIGHT2, GL_AMBIENT, light2_ambient);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, light2_diffuse);
	glLightfv(GL_LIGHT2, GL_SPECULAR, light2_specular);
	glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION,  light2_kc);
	glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION,    light2_kl);
	glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, light2_kq);

	// declaracoes para a fonte luz GL_LIGHT3
	glLightfv(GL_LIGHT3, GL_AMBIENT, light3_ambient);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, light3_diffuse);
	glLightfv(GL_LIGHT3, GL_SPECULAR, light3_specular);
	glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION,  light3_kc);
	glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION,    light3_kl);
	glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, light3_kq);

	// NOTA: a direccao e a posicao de GL_LIGHT0 estao na rotina display(), pelo
	//       que as isntrucoes seguntes nao sao necessarias
	//glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 90.0);
	//glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
	//glLightfv(GL_LIGHT0, GL_POSITION, light0_position);

	// Permitir calculos de iluminacao
	glEnable(GL_LIGHTING);
	// "Acender" a fonte de luz GL_LIGHT0
	glEnable(GL_LIGHT0);
	// "Acender" a fonte de luz GL_LIGHT1
	glEnable(GL_LIGHT1);
	// "Acender" a fonte de luz GL_LIGHT2
	glEnable(GL_LIGHT2);
	// "Acender" a fonte de luz GL_LIGHT3
	glEnable(GL_LIGHT3);


	// Declaracoe para shading
	glShadeModel(GL_SMOOTH);			// GL_FLAT / GL_SMOOTH
	glPolygonMode(GL_FRONT, GL_FILL);	// preence a face da frente dos poligonos
	//glPolygonMode(GL_FRONT, GL_LINE);	// desenha arestas dos poligonos


	// Texturas a utilizar (ver classe RGBpixmap)
	pixmap.readBMPFile("grass.bmp");
	pixmap.setTexture(1);

	pixmap.readBMPFile("floor.bmp");
	pixmap.setTexture(2);

	pixmap.readBMPFile("gravel.bmp");
	pixmap.setTexture(3);

	pixmap.readBMPFile("tree_base.bmp");
	pixmap.setTexture(4);

	pixmap.readBMPFile("leaf.bmp");
	pixmap.setTexture(5);

	pixmap.readBMPFile("leaf2.bmp");
	pixmap.setTexture(6);

	pixmap.readBMPFile("tile.bmp");
	pixmap.setTexture(7);

	pixmap.readBMPFile("metal.bmp");
	pixmap.setTexture(8);
	
	pixmap.readBMPFile("heliport.bmp");
	pixmap.setTexture(9);

	GLUquadric* glQ;	// nec. p/ criar sup. quadraticas (cilindros, esferas...)
	glQ = gluNewQuadric();

	glNewList(chaoEArvores, GL_COMPILE);
	desenhaChao();
	desenhaArvoreT1(glQ, arv1X, arv1Z, heightA1);
	desenhaArvoreT1(glQ, arv2X, arv2Z, heightA2);
	desenhaArvoreT2(glQ, arv3X, arv3Z, heightA3);
	desenhaArvoreT2(glQ, arv4X, arv4Z, heightA4);
	glEndList();

	glNewList(hospital, GL_COMPILE);
	desenhaHospital(glQ);
	glEndList();
	
	
	glNewList(heliporto, GL_COMPILE);
	desenhaHolofotes(glQ);
	desenhaHeliporto();
	glEndList();
}



int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize (DIMX, DIMY);
	glutInitWindowPosition (INITIALPOS_X, INITIALPOS_Y);
	main_window = glutCreateWindow (argv[0]);
 
	glutDisplayFunc(display);
	GLUI_Master.set_glutReshapeFunc(reshape);
	GLUI_Master.set_glutKeyboardFunc (keyboard);
	GLUI_Master.set_glutMouseFunc(processMouse);
	glutMotionFunc(processMouseMoved);
	glutPassiveMotionFunc(processPassiveMouseMoved);
	GLUI_Master.set_glutSpecialFunc( NULL );
   

	/*** Create the bottom subwindow ***/
	glui2 = GLUI_Master.create_glui_subwindow( main_window, GLUI_SUBWINDOW_BOTTOM );
	glui2->set_main_gfx_window( main_window );

	GLUI_Rotation *view_rot = glui2->add_rotation( "Rotacao", view_rotate );
	view_rot->set_spin( 1.0 );
	
	glui2->add_column( false );
	GLUI_Translation *trans_z = glui2->add_translation( "Zoom", GLUI_TRANSLATION_Z, &obj_pos[2] );
	trans_z->set_speed( .02 );


	/* We register the idle callback with GLUI, not with GLUT */
	GLUI_Master.set_glutIdleFunc( myGlutIdle );
   
	inicializacao();
   
	glutMainLoop();

	return 0;
}
