// dimensoes do chao
float PosChaoZ1 = 0.0;
float PosChaoZ2 = -30.0;
float PosChaoEX1 = 0.0;
float PosChaoEX2 = 15.0;
float PosChaoCX1 = 15.0;
float PosChaoCX2 = 30.0;
float PosChaoDX1 = 30.0;
float PosChaoDX2 = 45.0;

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
float helipRatio= heliComp/heliLarg;
GLfloat ctrlpoints[4][3] = {	{  -heliComp/2, 0.0, heliLarg/2},
								{  -heliComp/2, 0.0, -heliLarg/2},
								{  heliComp/2, 0.0, heliLarg/2},
								{  heliComp/2, 0.0, -heliLarg/2}};

GLfloat ctrlpointsHangar[2][4][3] = {  {{ -4.65, 0.0, -7.25},{-4.65, 4.65, -7.25},{4.65, 4.65, -7.25},{4.65, 0.0, -7.25}},
										{{-4.65, 0.0, 7.25},{-4.65, 4.65, 7.25},{4.65, 4.65, 7.25},{4.65, 0.0, 7.25}}
										};


GLfloat nrmlcompon[4][3] = {	{  0.0, 1.0, 0.0},
								{  0.0, 1.0, 0.0}, 
								{  0.0, 1.0, 0.0},
								{  0.0, 1.0, 0.0} };

GLfloat nrmlcomponHangar[2][4][3] = {	{{  0.0, 1.0, 0.0},{  0.0, 1.0, 0.0}, {  0.0, 1.0, 0.0},{  0.0, 1.0, 0.0}}, 
								{{  0.0, 1.0, 0.0},{  0.0, 1.0, 0.0}, {  0.0, 1.0, 0.0},{  0.0, 1.0, 0.0}}
};

GLfloat textpoints[4][2] = {	{ 0.0, 0.0},
								{ 0.0, 1.0}, 
								{ 1.0, 0.0},
								{ 1.0, 1.0} };

GLfloat textpoints2[4][2] = {	{ 0.0, 0.0},
								{ 0.0, 1.0}, 
								{ 1.0, 0.0},
								{ 1.0, 1.0} };

// definicoes do hangar
float deslHangarX = 6.0;
float deslHangarY = 10.0;

// posicao dos holofotes
float holo1X = ((PosChaoCX1+PosChaoCX2)/2)-heliComp/2;
float holo1Z = (PosChaoZ2/4)+heliLarg/2;
float holo2X = ((PosChaoCX1+PosChaoCX2)/2)+heliComp/2;
float holo2Z = (PosChaoZ2/4)-heliLarg/2;;

// vectores direccionais das luzes dos holofotes
float angLuz = 35.0;
float spot0[] = {helipRatio,-2.5,-helipRatio};
float spot1[] = {-helipRatio,-2.5,-helipRatio};
float spot2[] = {-helipRatio,-2.5,helipRatio};
float spot3[] = {helipRatio,-2.5,helipRatio};

// dimensoes torre de controlo
float alturaTorre = 9.5;
float raioTorre = 1.25;
float raioTorrePlat = 4.5;
float alturaTorrePlat = 0.7;

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

//triangulos
//calcular o vector normal dos triângulos
float vTri1[3] = {0.0, 0.0, 1.0};
float vTri2[3] = {(telhadoComp-telhadoAresta)/2, telhadoAlt, telhadoLarg/2};
float vTriNor[3] = {vTri1[1]*vTri2[2]-vTri1[2]*vTri2[1], vTri1[2]*vTri2[0]-vTri1[0]*vTri2[2], vTri1[0]*vTri2[1]-vTri1[1]*vTri2[0]}; 
float normaVec = sqrt(vTriNor[0]*vTriNor[0]+vTriNor[1]*vTriNor[1]+vTriNor[2]*vTriNor[2]);
int i = 0;

//quadrilateros
//calcular o vector normal dos quadrilateros
float vQuad1[3] = {1.0, 0.0, 0.0};
float vQuad2[3] = {-(telhadoComp-telhadoAresta)/2-telhadoComp/2, telhadoAlt, -telhadoLarg/2};
float vQuadNor[3] = {vQuad1[1]*vQuad2[2]-vQuad1[2]*vQuad2[1], vQuad1[2]*vQuad2[0]-vQuad1[0]*vQuad2[2], vQuad1[0]*vQuad2[1]-vQuad1[1]*vQuad2[0]}; 
float normaVecQuad = sqrt(vQuadNor[0]*vQuadNor[0]+vQuadNor[1]*vQuadNor[1]+vQuadNor[2]*vQuadNor[2]);

const int TRUE  = 1;
const int FALSE = 0;