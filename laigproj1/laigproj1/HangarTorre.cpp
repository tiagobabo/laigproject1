//CPP FILE Hangar e Torre

#include "MainCode.h"

void desenhaTorre(GLUquadric * quad)
{
	parede.activate();
	double plane0[] = {0.0,0.0,1.0,0.0};
	gluQuadricTexture(quad, GL_TRUE);
	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 16);
	
	// posicionamento da torre
	glPushMatrix();
	glTranslatef(PosChaoDX2-raioTorrePlat/2,0.0,PosChaoZ2+raioTorrePlat);
	glRotatef(-90.0,1.0,0.0,0.0);
	
	glPushMatrix();
	glTranslatef(0.0,0.0,alturaTorre);
	// disco superior da plataforma
	glBindTexture(GL_TEXTURE_2D, 17);
	glPushMatrix();
	glTranslatef(0.0,0.0,alturaTorrePlat);
	gluDisk(quad, 0.0, raioTorrePlat, slicesT1, stacksT1);
	glPopMatrix();

	// disco inferior da plataforma
	glPushMatrix();
	glRotatef(180.0,1.0,0.0,0.0);
	gluDisk(quad, 0.0, raioTorrePlat, slicesT1, stacksT1);
	glPopMatrix();
	// plataforma
	gluCylinder(quad, raioTorrePlat, raioTorrePlat, alturaTorrePlat, slicesT1, stacksT1);
	glPopMatrix();
	
	// base cilindrica
	gluCylinder(quad, raioTorre,raioTorre ,alturaTorre, slicesT1,stacksT1);
	glPushMatrix();
	glTranslatef(0.0,0.0,alturaTorre);
	gluDisk(quad, 0.0,raioTorre,slicesT1,stacksT1);
	glPopMatrix();
	
	glDisable(GL_TEXTURE_2D);	
	gluQuadricTexture(quad, GL_FALSE);
	
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	// cupula da torre
	glPushMatrix();
	cockpit.activate();
	glTranslatef(0.0,0.0,alturaTorre+alturaTorrePlat);
	glClipPlane(GL_CLIP_PLANE0, plane0);
	glEnable(GL_CLIP_PLANE0);
	gluSphere(quad,raioTorrePlat,slicesT1,stacksT1);
	glDisable(GL_CLIP_PLANE0);
	disableColors();
	glPopMatrix();
	glDisable(GL_BLEND);
	glPopMatrix();
}

void desenhaHangar()
{
	glDisable(GL_CULL_FACE);
	glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4,  0.0, 1.0, 12, 2,  &ctrlpointsHangar[0][0][0]);
	glMap2f(GL_MAP2_NORMAL,   0.0, 1.0, 3, 4,  0.0, 1.0, 12, 2,  &nrmlcomponHangar[0][0][0]);
	glMap2f(GL_MAP2_TEXTURE_COORD_2,  0.0, 1.0, 2, 2,  0.0, 1.0, 4, 2,  &textpoints2[0][0]);

	// os interpoladores activam-se:
	glEnable(GL_MAP2_VERTEX_3);
	glEnable(GL_MAP2_NORMAL);
	glEnable(GL_MAP2_TEXTURE_COORD_2);
	hangar.activate();
	glPushMatrix();
	glTranslatef(PosChaoCX2+deslHangarX,0.0,PosChaoZ2+deslHangarY);
	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 15);
	glMapGrid2f(heliDiv, 0.0,1.0, heliDiv, 0.0,1.0); 
	glEvalMesh2(GL_FILL, 0,heliDiv, 0,heliDiv);		// GL_POINT, GL_LINE, GL_FILL
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glEnable(GL_CULL_FACE);

}

