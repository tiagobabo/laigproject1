//CPP FILE Heliporto

#include "Heliporto.h"

void desenhaHolofotesAux(GLUquadric * quad)
{
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(quad, raioPoste, raioPoste, alturaPoste, slicesT1, stacksT1);
	glTranslatef(0.0,0.0,alturaPoste);
	gluDisk(quad,0.0,raioPoste,slicesT1, stacksT1);
}

void desenhaHolofotesAux2(GLUquadric * quad)
{
	gluCylinder(quad, raioHolo1, raioHolo2, alturaHolo, slicesT1, stacksT1);
	glTranslatef(0.0,0.0,alturaHolo);
	gluDisk(quad,0.0,raioHolo2,slicesT1, stacksT1);
}

void desenhaHolofotes(GLUquadric * quad)
{

	gluQuadricTexture(quad, GL_TRUE);
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 8);
	// postes dos holofotes
	// poste1
	glPushMatrix();
	glTranslatef(holo1X,0.0,holo1Z);
	desenhaHolofotesAux(quad);
	glPopMatrix();
	// poste2
	glPushMatrix();
	glTranslatef(holo2X,0.0,holo1Z);
	desenhaHolofotesAux(quad);
	glPopMatrix();
	// poste3
	glPushMatrix();
	glTranslatef(holo2X,0.0,holo2Z);
	desenhaHolofotesAux(quad);
	glPopMatrix();
	// poste4
	glPushMatrix();
	glTranslatef(holo1X,0.0,holo2Z);
	desenhaHolofotesAux(quad);
	glPopMatrix();
	
	glDisable(GL_CULL_FACE);
	
	// holofotes
	// holofote1
	glPushMatrix();
	glTranslatef(holo1X+4*raioPoste,alturaPoste-2*raioPoste,holo1Z-4*raioPoste);
	glRotatef(-45.0, 0.0, 1.0, 0.0);
	glRotatef(-45.0, 1.0, 0.0, 0.0);
	desenhaHolofotesAux2(quad);
	glPopMatrix();
	// holofote2
	glPushMatrix();
	glTranslatef(holo2X-4*raioPoste,alturaPoste-2*raioPoste,holo1Z-4*raioPoste);
	glRotatef(45.0, 0.0, 1.0, 0.0);
	glRotatef(-45.0, 1.0, 0.0, 0.0);
	desenhaHolofotesAux2(quad);
	glPopMatrix();
	// holofote3
	glPushMatrix();
	glTranslatef(holo2X-4*raioPoste,alturaPoste-2*raioPoste,holo2Z+4*raioPoste);
	glRotatef(135.0, 0.0, 1.0, 0.0);
	glRotatef(-45.0, 1.0, 0.0, 0.0);
	desenhaHolofotesAux2(quad);
	glPopMatrix();
	// holofote4
	glPushMatrix();
	glTranslatef(holo1X+4*raioPoste,alturaPoste-2*raioPoste,holo2Z+4*raioPoste);
	glRotatef(-135.0, 0.0, 1.0, 0.0);
	glRotatef(-45.0, 1.0, 0.0, 0.0);
	desenhaHolofotesAux2(quad);
	glPopMatrix();
	glEnable(GL_CULL_FACE);
	glDisable(GL_TEXTURE_2D);
}

void desenhaHeliporto()
{
	glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 2,  0.0, 1.0, 6, 2,  &ctrlpoints[0][0]);
	glMap2f(GL_MAP2_NORMAL,   0.0, 1.0, 3, 2,  0.0, 1.0, 6, 2,  &nrmlcompon[0][0]);
	glMap2f(GL_MAP2_TEXTURE_COORD_2,  0.0, 1.0, 2, 2,  0.0, 1.0, 4, 2,  &textpoints[0][0]);

	// os interpoladores activam-se:
	glEnable(GL_MAP2_VERTEX_3);
	glEnable(GL_MAP2_NORMAL);
	glEnable(GL_MAP2_TEXTURE_COORD_2);

	glMapGrid2f(heliDiv, 0.0,1.0, heliDiv, 0.0,1.0); 

	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 9);
	glPushMatrix();
	glTranslatef((PosChaoCX1+PosChaoCX2)/2,0.01,(PosChaoZ2/4));
	glEvalMesh2(GL_FILL, 0,heliDiv, 0,heliDiv);		// GL_POINT, GL_LINE, GL_FILL
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}