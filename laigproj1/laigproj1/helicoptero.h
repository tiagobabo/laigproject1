//HEADER FILE Helicoptero

void desenhaSuporteAterragem(GLUquadric * quad);

void desenhaEstabilizador();

void desenhaHeliceMotorT();

void desenhaMotorTraseiro(GLUquadric * quad);

void desenhaMotorPrin(GLUquadric * quad);

void desenhaCaudaHeli(GLUquadric * quad);

void desenhaHelicoptero(GLUquadric * quad);

// dimensoes do helicoptero
float escalaHeli = 0.6;
float raioHeliCabine = 2.0*escalaHeli;
float raioHeliCaudaS = 0.3*escalaHeli;
float raioHeliCaudaI = 0.6*escalaHeli;
float compHeliCauda = 5.0*escalaHeli;
float raioIMotorT = 0.2*escalaHeli;
float raioEMotorT = 1.2*escalaHeli;
float largHeliceT = 0.2*escalaHeli;
float compHeliceT = 0.9*escalaHeli;
float largHeliceF = 0.3*escalaHeli;
float compHeliceF = 6.0*escalaHeli;
float raioMotorF = 0.5*escalaHeli;
float alturaMotorF = 0.5*escalaHeli;
float MotorAng = 0.0;
float angCauda = 10*escalaHeli;
float largSuporteAterr = 0.3*escalaHeli;
float compSuporteAterr = (2*raioHeliCabine+(2*raioHeliCabine/4))*escalaHeli;
float alturaHeli = (2*(raioHeliCabine+(raioHeliCabine/4)+largSuporteAterr));
float heliY = 0;
float heliX = 0;
float heliZ = 0;
float heliXang = 0;
float heliZang = 0;
float rodaHeliang = 0.0;
float curvHeli = 0.0;
float rotCenX = 0.0;
float rotCenY = 0.0;
float rotCenZ = 0.0;
float rotX = 0.0;
float rotY = 0.0;
float rotZ = 0.0;
float rotAng = 0.0;