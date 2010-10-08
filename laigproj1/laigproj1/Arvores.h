//HEADER FILE Chao e Arvores

void desenhaTrianguloXY(float x1, float y1, float x2, float y2, int imagem, float normal[3]);

void desenhaArvoreT1(GLUquadric * quad, float posX, float posZ, float height);

void desenhaArvoreT2(GLUquadric * quad, float posX, float posZ, float height);

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