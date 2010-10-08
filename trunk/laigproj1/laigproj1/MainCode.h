// G1_Ilum.cpp : Defines the entry point for the console application.
//

#include <GL/glui.h>
#include <math.h>
#include "RGBpixmap.h"
#include <iostream>
#include <string>
#include "Helicoptero.h"
#include "Arvores.h"
#include "Chao.h"
#include "Hospital.h"
#include "Heliporto.h"
#include "HangarTorre.h"

void disableColors();

// dimensoes e localizacao da janela
#define DIMX 800
#define DIMY 600
#define INITIALPOS_X 200
#define INITIALPOS_Y 50

/********** User IDs for callbacks ********/
#define LIGHT0_ENABLED_ID    200
#define LIGHT1_ENABLED_ID    201
#define LIGHT2_ENABLED_ID    202
#define LIGHT3_ENABLED_ID    203

//posicao de visualizacao
float VposX = 20.0;
float VposY = 10.0;
float VangleX = 40.0;
float VangleY = 0.0;
float zoom = 50;
int camera = 1;
float eyex3 = 22.5;
float eyey3 = 20.0;
float eyez3 = 7.5;
float centerx3 = 22.5;
float centery3 = 0.0;
float centerz3 = -7.5;
float upx3 = 0.0;
float upy3 = 1.0;
float upz3 = -1.0;

//definicao das listas
int chaoEArvores = 1;
int hospital = 2;
int heliporto = 3;
int helicoptero = 4;
int hangarETorre = 5;

float corFundo[3] = {0.41, 0.76, 0.40};

// escala das texturas
float escala = 15.0;
float escalaT = 2.0;





GLfloat nrmlcompon[4][3] = {	{  0.0, 1.0, 0.0},
								{  0.0, 1.0, 0.0}, 
								{  0.0, 1.0, 0.0},
								{  0.0, 1.0, 0.0} };



GLfloat textpoints[4][2] = {	{ 0.0, 0.0},
								{ 0.0, 1.0}, 
								{ 1.0, 0.0},
								{ 1.0, 1.0} };



// declarações para animacao
#define RADIUS_SPEED  5.0  // unidades de comprimento por segundo
#define ANGULAR_SPEED 2.0 // rotacoes por segundo
float PI = acos(-1.0);
unsigned int mili_secs = 20;
double  obj_radius, obj_rotate, delta_radius, delta_rotate;
int animation = 0;
int firstTime = 1;
int step = 1;
int step2 = 1;
float speedTurn = 2.0;
float alturaMAXanim = 12.0;
float alturaMINanim = 9.0;
float rotacaoVerdeIni = -26.0;
float alturaIniRota = 5.0;
float alturaIniAnda = 7.0;
float angMovFrente = 10.0;
float stepAngMovFrente = 0.25;
float limXesq = -15.0;
float limXendireita = -10.0;
float limXendireita2 = -2.0;
float limZtras = -7.5;
float zIniRota = -5.0;
float xFimRota = -5.0;
float xRaioRota = -5.0;
float stepRota = RADIUS_SPEED*(mili_secs/10)/(abs(xRaioRota)*PI/2);
float rotacaoTeta = -atan(limZtras/limXesq);
float razaoZXAnda = limZtras/limXesq;



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

// declarações para a fonte de luz light4;
float light4_position[]  = {0.0, 3.0, 4.0, 1.0}; // nao necessaria...
float light4_ambient[] =   {0.0, 0.0, 0.0, 1.0}; // sem componente ambiente
float light4_diffuse[] =   {10.0, 10.0, 10.0, 1.0};
float light4_specular[] =  {10.0, 10.0, 10.0, 1.0};
float light4_kc = 0.0;
float light4_kl = 1.0;
float light4_kq = 0.0;
float light4x = 30.0;
float light4y = 20.0;
float light4z = -10.0;
float symb_light4_radius = 0.6;
int symb_light4_slices = 8;
int symb_light4_stacks =8;

float* lights_position[] = {light0_position, light1_position, light2_position, light3_position, light4_position};
float* lights_ambient[] = {light0_ambient, light1_ambient, light2_ambient, light3_ambient, light4_ambient};
float* lights_diffuse[] = {light0_diffuse, light1_diffuse, light2_diffuse, light3_diffuse, light4_diffuse};
float* lights_specular[] = {light0_specular, light1_specular, light2_specular, light3_specular, light4_specular};
float lights_kc[] = {light0_kc, light1_kc, light2_kc, light3_kc, light4_kc};
float lights_kl[] = {light0_kl, light1_kl, light2_kl, light3_kl, light4_kl};
float lights_kq[] = {light0_kq, light1_kq, light2_kq, light3_kq, light4_kq};
float lightsx[] = {light0x, light1x, light2x, light3x, light4x};
float lightsy[]= {light0y, light1y, light2y, light3y, light4y};
float lightsz[]= {light0z, light1z, light2z, light3z, light4z};
float symb_lights_radius[] = {symb_light0_radius, symb_light1_radius, symb_light2_radius, symb_light3_radius, symb_light4_radius};
int symb_lights_slices[] = {symb_light0_slices, symb_light1_slices, symb_light2_slices, symb_light3_slices, symb_light4_slices};
int symb_lights_stacks[] = {symb_light0_stacks, symb_light1_stacks, symb_light2_stacks, symb_light3_stacks, symb_light4_stacks};
int nlights = 5;

float luz1 = 1;
float luz2 = 1;
float luz3 = 1;
float luz4 = 1;

// fonte (global) de luz ambiente 
float light_ambient[] = {0.6, 0.6, 0.6, 1.0}; /* Set the background ambient lighting. */


// variaveis para a janela
int main_window;
GLUI  *glui2;


RGBpixmap pixmap;

 class Material 
   {
   private:
		float* shininess; 
		float* specular;	/* specular reflection. */
		float* diffuse;	/* diffuse reflection. */
		float* ambient;	/* ambient reflection. */   
   public:
	    Material(float* shininess, float* specular,
						float* diffuse, float* ambient);
		 void activate();
   };

Material::Material(float* shininess, float* specular, float* diffuse, float* ambient)
{
	this->shininess = shininess;
	this->specular = specular;
	this->diffuse = diffuse;
	this->ambient = ambient;
}
 void Material::activate()
{
	glDisable(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,  specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,   diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,   ambient);
}

// declaracoes para as paredes e chao
float mat1_shininess[] = {128.0}; 
float mat1_specular[] = {0.3, 0.3, 0.3, 1.0};	/* specular reflection. */
float mat1_diffuse[] =  {0.7, 0.7, 0.7, 1.0};	/* diffuse reflection. */
float mat1_ambient[] =  {0.7, 0.7, 0.7, 1.0};	/* ambient reflection. */

Material parede(mat1_shininess, mat1_specular, mat1_diffuse, mat1_ambient);
Material chao(mat1_shininess, mat1_specular, mat1_diffuse, mat1_ambient);

// declaracoes para o cockpit
float cockpit_shininess[] = {128.0}; 
float cockpit_specular[] = {0.0, 0.0, 0.3, 0.4};	/* specular reflection. */
float cockpit_diffuse[] =  {0.0, 0.0, 1.0, 0.4};	/* diffuse reflection. */
float cockpit_ambient[] =  {0.0, 0.0, 1.0, 0.4};	/* ambient reflection. */

Material cockpit(cockpit_shininess, cockpit_specular, cockpit_diffuse, cockpit_ambient);

// declaracoes para as folhas das árvores
float arv_shininess[] = {128.0}; 
float arv_specular[] = {0.4, 0.4, 0.4, 1.0};	/* specular reflection. */
float arv_diffuse[] =  {0.8, 0.8, 0.8, 1.0};	/* diffuse reflection. */
float arv_ambient[] =  {0.8, 0.8, 0.8, 1.0};	/* ambient reflection. */

Material arvore(arv_shininess, arv_specular, arv_diffuse, arv_ambient);

// declaracoes para o material do helicoptero
float heli_shininess[] = {128.0}; 
float heli_specular[] = {0.2, 0.2, 0.2, 1.0};	/* specular reflection. */
float heli_diffuse[] =  {0.4, 0.4, 0.4, 1.0};	/* diffuse reflection. */
float heli_ambient[] =  {0.8, 0.8, 0.8, 1.0};	/* ambient reflection. */

Material heli(heli_shininess, heli_specular, heli_diffuse, heli_ambient);

// declaracoes para o material do hangar
float hangar_shininess[] = {128.0}; 
float hangar_specular[] = {0.4, 0.4, 0.4, 1.0};	/* specular reflection. */
float hangar_diffuse[] =  {0.8, 0.8, 0.8, 1.0};	/* diffuse reflection. */
float hangar_ambient[] =  {0.8, 0.8, 0.8, 1.0};	/* ambient reflection. */

Material hangar(hangar_shininess, hangar_specular, hangar_diffuse, hangar_ambient);

GLUI_Rotation *view_rot;
GLUI_Translation *trans_z;
