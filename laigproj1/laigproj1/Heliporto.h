//HEADER FILE Heliporto

void desenhaHolofotesAux(GLUquadric * quad);

void desenhaHolofotesAux2(GLUquadric * quad);

void desenhaHolofotes(GLUquadric * quad);

void desenhaHeliporto();

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

