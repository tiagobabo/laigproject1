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

