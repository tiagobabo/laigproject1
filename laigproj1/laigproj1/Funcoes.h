// G1_Ilum.cpp : Defines the entry point for the console application.
//

#include <GL/glui.h>
#include <math.h>
#include "RGBpixmap.h"
#include <iostream>
#include <string>
#include "Arvores.h"
#include "ChaoEEdificios.h"
#include "Helicoptero.h"
#include "Luzes.h"
#include "Material.h"

// titulo da janela
const char *WINDOWTITLE = { "Projecto 1 - LAIG" };

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
#define ANIMACAO_ID			 204

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
int HangarTorre = 5;

float corFundo[3] = {0.41, 0.76, 0.40};


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


// variaveis para a janela
int main_window;
GLUI  *glui2;

RGBpixmap pixmap;

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
GLUI_Button* animacao;
