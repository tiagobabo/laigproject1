//HEADER FILE Hospital
#ifndef Hospital
#define Hospital

#include "Auxiliar.h"

void desenhaRecXZ2(float x1, float z1, float x2, float z2, int imagem);

void desenhaJanelas();

void desenhaHospital(GLUquadric * quad);


// dimensoes e cor do hospital
float corHospital[3] = {1.0,0.9,0.61};
float corPorta[3] = {0.54,0.27,0.0};
float corLetreiro[3] = {0.0,1.0,0.0};
float hospAlt = 11.5;
float hospLarg = 11.5;
float hospProf = 7.0;
float alturaPorta = 3.0;
float larguraPorta = 2.0;
float alturaJanela = 2.0;
float larguraJanela = 10.0;
float larguraJanelaL = 6.0;
float telhadoLarg = 8.5;
float telhadoComp = 13.0;
float telhadoAresta = 6.5;
float telhadoAlt = 1.0;
float escalaLetr = 0.02;
float tamanhoLetr = 3.0;

#endif
