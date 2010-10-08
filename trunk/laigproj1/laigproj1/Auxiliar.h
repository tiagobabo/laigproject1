//HEADER FILE Auxiliar (Variaveis)
#ifndef Auxiliar
#define Auxiliar

#include <GL/glui.h>
#include <math.h>

void disableColors();

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

// slices & stacks
float slicesT1 = 20.0;
float stacksT1 = 20.0;

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

#endif
