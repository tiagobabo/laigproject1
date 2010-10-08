//HEADER FILE Hangar e Torre

void desenhaTorre(GLUquadric * quad);

void desenhaHangar();

GLfloat ctrlpointsHangar[2][4][3] = {  {{ -4.65, 0.0, -7.25},{-4.65, 4.65, -7.25},{4.65, 4.65, -7.25},{4.65, 0.0, -7.25}},
										{{-4.65, 0.0, 7.25},{-4.65, 4.65, 7.25},{4.65, 4.65, 7.25},{4.65, 0.0, 7.25}}
										};

GLfloat nrmlcomponHangar[2][4][3] = {	{{  0.0, 1.0, 0.0},{  0.0, 1.0, 0.0}, {  0.0, 1.0, 0.0},{  0.0, 1.0, 0.0}}, 
								{{  0.0, 1.0, 0.0},{  0.0, 1.0, 0.0}, {  0.0, 1.0, 0.0},{  0.0, 1.0, 0.0}}
};

GLfloat textpoints2[4][2] = {	{ 0.0, 0.0},
								{ 0.0, 1.0}, 
								{ 1.0, 0.0},
								{ 1.0, 1.0} };

// definicoes do hangar
float deslHangarX = 6.0;
float deslHangarY = 10.0;


// dimensoes torre de controlo
float alturaTorre = 9.5;
float raioTorre = 1.25;
float raioTorrePlat = 4.5;
float alturaTorrePlat = 0.7;