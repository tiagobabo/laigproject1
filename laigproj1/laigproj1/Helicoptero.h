
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

// declarações para animacao
#define RADIUS_SPEED  5.0  // unidades de comprimento por segundo
#define ANGULAR_SPEED 2.0 // rotacoes por segundo
float PI = acos(-1.0);
int animation = 0;
int firstTime = 1;
int statusHelice = 1;
float factori = 0.01;
unsigned int mili_secs = 20;
double  obj_radius, obj_rotate, delta_radius, delta_rotate;
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
