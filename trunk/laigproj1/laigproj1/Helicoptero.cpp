//CPP FILE Helicoptero

#include "MainCode.h"

void desenhaSuporteAterragem(GLUquadric * quad)
{
	//suportes de aterragem 
	//direito
	glBindTexture(GL_TEXTURE_2D, 8);
	glPushMatrix();
	glTranslatef(raioHeliCabine, -(raioHeliCabine+(raioHeliCabine/4)),-(compSuporteAterr/2));
	// discos para cubrir os suportes de aterragem
	glPushMatrix();
	glTranslatef(0.0,0.0,compSuporteAterr);
	gluDisk(quad,0.0,largSuporteAterr, slicesT1, stacksT1); 
	glPopMatrix();
	glPushMatrix();
	glRotatef(180,0.0,1.0,0.0);
	gluDisk(quad,0.0,largSuporteAterr, slicesT1, stacksT1);
	glPopMatrix();
	// suporte
	gluCylinder(quad, largSuporteAterr, largSuporteAterr, compSuporteAterr ,slicesT1, stacksT1);
	glPopMatrix();
	
	//esquerdo
	glPushMatrix();
	glTranslatef(-raioHeliCabine, -(raioHeliCabine+(raioHeliCabine/4)),-(compSuporteAterr/2));
	// discos para cubrir os suportes de aterragem
	glPushMatrix();
	glTranslatef(0.0,0.0,compSuporteAterr);
	gluDisk(quad,0.0,largSuporteAterr, slicesT1, stacksT1);
	glPopMatrix();
	glPushMatrix();
	glRotatef(180,0.0,1.0,0.0);
	gluDisk(quad,0.0,largSuporteAterr, slicesT1, stacksT1);
	glPopMatrix();
	// suporte
	gluCylinder(quad, largSuporteAterr, largSuporteAterr, compSuporteAterr ,slicesT1, stacksT1);
	glPopMatrix();
	
	
	// suporte esquerdo dianteiro
	glPushMatrix();
	glTranslatef(-raioHeliCabine/2, 0.0,-compSuporteAterr/4);
	glRotatef(-25,0.0,0.0,1.0);
	glRotatef(90,1.0,0.0,0.0);
	gluCylinder(quad, largSuporteAterr/2, largSuporteAterr/2, (raioHeliCabine+(raioHeliCabine/4)) ,slicesT1, stacksT1);
	glPopMatrix();
	// suporte esquerdo traseiro
	glPushMatrix();
	glTranslatef(-raioHeliCabine/2, 0.0,compSuporteAterr/4);
	glRotatef(-25,0.0,0.0,1.0);
	glRotatef(90,1.0,0.0,0.0);
	gluCylinder(quad, largSuporteAterr/2, largSuporteAterr/2, (raioHeliCabine+(raioHeliCabine/4)) ,slicesT1, stacksT1);
	glPopMatrix();
	// suporte direito dianteiro
	glPushMatrix();
	glTranslatef(raioHeliCabine/2, 0.0,-compSuporteAterr/4);
	glRotatef(25,0.0,0.0,1.0);
	glRotatef(90,1.0,0.0,0.0);
	gluCylinder(quad, largSuporteAterr/2, largSuporteAterr/2, (raioHeliCabine+(raioHeliCabine/4)) ,slicesT1, stacksT1);
	glPopMatrix();
	// suporte direito traseiro
	glPushMatrix();
	glTranslatef(raioHeliCabine/2, 0.0,compSuporteAterr/4);
	glRotatef(25,0.0,0.0,1.0);
	glRotatef(90,1.0,0.0,0.0);
	gluCylinder(quad, largSuporteAterr/2, largSuporteAterr/2, (raioHeliCabine+(raioHeliCabine/4)) ,slicesT1, stacksT1);
	glPopMatrix();
}

void desenhaEstabilizador()
{
	glEnable(GL_NORMALIZE);
	glBindTexture(GL_TEXTURE_2D, 11);
	glPushMatrix();
	glTranslatef(0.0,0.0,compHeliCauda-(compHeliCauda/4));
	glScalef(30.0,1.0,10.0);
	glutSolidCube(0.1);
	glPopMatrix();
	glDisable(GL_NORMALIZE);
}

void desenhaHeliceMotorT()
{
	
	glDisable(GL_CULL_FACE);
	//helice1
	glPushMatrix();
	glTranslatef(0.0,0.0,compHeliCauda+raioEMotorT);
	glRotatef(-MotorAng,1.0,0.0,0.0); // movimento helice
	glRotatef(90,1.0,0.0,0.0);
	desenhaRecXZ(-largHeliceT,-compHeliceT,largHeliceT,compHeliceT,8);
	glPopMatrix();
	//Helice2
	glPushMatrix();
	glTranslatef(0.0,0.0,compHeliCauda+raioEMotorT);
	glRotatef(-MotorAng,1.0,0.0,0.0); // movimento helice
	desenhaRecXZ(-largHeliceT,-compHeliceT,largHeliceT,compHeliceT,8);
	glPopMatrix();
	//Helice3
	glPushMatrix();
	glTranslatef(0.0,0.0,compHeliCauda+raioEMotorT);
	glRotatef(-MotorAng,1.0,0.0,0.0); // movimento helice
	glRotatef(45,1.0,0.0,0.0);
	desenhaRecXZ(-largHeliceT,-compHeliceT,largHeliceT,compHeliceT,8);
	glPopMatrix();
	//Helice4
	glPushMatrix();
	glTranslatef(0.0,0.0,compHeliCauda+raioEMotorT);
	glRotatef(-MotorAng,1.0,0.0,0.0); // movimento helice
	glRotatef(-45,1.0,0.0,0.0);
	desenhaRecXZ(-largHeliceT,-compHeliceT,largHeliceT,compHeliceT,8);
	glPopMatrix();
	//Suporte ao rotor
	glPushMatrix();
	glTranslatef(largHeliceT,0.0,compHeliCauda);
	glRotatef(90,0.0,0.0,1.0);
	desenhaRecXZ(-largHeliceT,0.0,largHeliceT,2*compHeliceT,8);
	glPopMatrix();
	glEnable(GL_CULL_FACE);
}

void desenhaMotorTraseiro(GLUquadric * quad)
{
	//Estrutura rotor
	glPushMatrix();
	glTranslatef(0.0,0.0,compHeliCauda+raioEMotorT);
	glRotatef(-90,0.0,1.0,0.0);
	glutSolidTorus(0.1, 0.1, stacksT1, slicesT1);
	glutSolidTorus(raioIMotorT, raioEMotorT, stacksT1, slicesT1);
	glPopMatrix();
	//helices
	desenhaHeliceMotorT();
}

void desenhaMotorPrin(GLUquadric * quad)
{
	glDisable(GL_CULL_FACE);
	//helice1
	glPushMatrix();
	glTranslatef(0.0,raioHeliCabine+alturaMotorF+0.1,0.0);
	glRotatef(-MotorAng,0.0,1.0,0.0); // movimento helice
	desenhaRecXZ(-largHeliceF,-compHeliceF,largHeliceF,compHeliceF,8);
	glPopMatrix();
	//helice2
	glPushMatrix();
	glTranslatef(0.0,raioHeliCabine+alturaMotorF,0.0);
	glRotatef(-MotorAng+90.0,0.0,1.0,0.0); // movimento helice
	desenhaRecXZ(-largHeliceF,-compHeliceF,largHeliceF,compHeliceF,8);
	glPopMatrix();
	glEnable(GL_CULL_FACE);

	glPushMatrix();
	glTranslatef(0.0,raioHeliCabine+alturaMotorF,0.0);
	glRotatef(90.0,1.0,0.0,0.0);
	gluCylinder(quad, raioMotorF,raioMotorF,alturaMotorF,slicesT1,stacksT1);
	glPopMatrix();
}

void desenhaCaudaHeli(GLUquadric * quad)
{
	// cauda Helicoptero
	glPushMatrix();
	glRotatef(-angCauda,1.0,0.0,0.0);
	glTranslatef(0.0,0.0, raioHeliCabine+0.5);
	//disco para a cauda do helicoptero
	glPushMatrix();
	glTranslatef(0.0,0.0,compHeliCauda);
	gluDisk(quad, 0.0, raioHeliCaudaS, slicesT1, stacksT1);
	glPopMatrix();
	desenhaEstabilizador();
	desenhaMotorTraseiro(quad);
	glBindTexture(GL_TEXTURE_2D, 14);
	gluCylinder(quad, raioHeliCaudaI, raioHeliCaudaS, compHeliCauda, slicesT1, stacksT1);
	glPopMatrix();
	
}

void desenhaHelicoptero(GLUquadric * quad)
{
	gluQuadricTexture(quad, GL_TRUE);
	double plane0[] = {0.0,-1.0,0.3,0.0}; //estrutura traseira da cabine
	double plane1[] = {0.0,1.0,-0.3,0.0}; //vidro da cabine
	double plane2[] = {0.0,-1.0,-0.3,-0.4}; //estrutura dianteira da cabine
	double plane3[] = {0.0,1.0,0.3,0.4};

	glEnable(GL_COLOR_MATERIAL);

	glPushMatrix();
	glTranslatef((PosChaoCX1+PosChaoCX2)/2 + heliX,alturaHeli/2+heliY,(PosChaoZ2/4)+heliZ);
	glTranslatef(-rotCenX, -rotCenY, -rotCenZ);
	glRotatef(rotAng, rotX, rotY, rotZ);
	glTranslatef(rotCenX, rotCenY, rotCenZ);
	glRotatef(rodaHeliang, 0.0,1.0,0.0);
	glRotatef(heliXang,0.0,0.0,1.0); //rotacao heli, movimento horizontal
	glRotatef(90, 0.0,1.0,0.0);
	
	heli.activate();
	glEnable(GL_TEXTURE_2D);
	desenhaMotorPrin(quad);
	
	glBindTexture(GL_TEXTURE_2D, 18);
	glDisable(GL_CULL_FACE);
	//estrutura traseira
	glPushMatrix();
	glClipPlane(GL_CLIP_PLANE0, plane0);
	glEnable(GL_CLIP_PLANE0);
	//glTranslatef(0.0,-0.1,0.1);
	glEnable(GL_NORMALIZE);	
	glScalef(1.0,1.0,2.0);	
	gluSphere(quad, raioHeliCabine , slicesT1, stacksT1);
	glDisable(GL_NORMALIZE);
	glDisable(GL_CLIP_PLANE0);
	glPopMatrix();

	//estrutura dianteira
	glPushMatrix();
	heli.activate();
	glClipPlane(GL_CLIP_PLANE0, plane2);
	glEnable(GL_CLIP_PLANE0);
	glEnable(GL_NORMALIZE);
	glScalef(1.0,0.7,2.0);
	glTranslatef(0.0, -0.7, -0.7);
	gluSphere(quad, raioHeliCabine , slicesT1, stacksT1);
	glDisable(GL_NORMALIZE);
	glDisable(GL_CLIP_PLANE0);
	glPopMatrix();
	glEnable(GL_CULL_FACE);


	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	//cockpit
	glPushMatrix();
	cockpit.activate();
	glClipPlane(GL_CLIP_PLANE0, plane1);
	glClipPlane(GL_CLIP_PLANE1, plane3);
	glEnable(GL_CLIP_PLANE0);
	glEnable(GL_CLIP_PLANE1);
	glEnable(GL_NORMALIZE);	
	glScalef(1.0,1.0,2.0);
	gluSphere(quad, raioHeliCabine , slicesT1, stacksT1);
	glDisable(GL_NORMALIZE);	
	glDisable(GL_CLIP_PLANE0);
	glDisable(GL_CLIP_PLANE1);
	glPopMatrix();
	glDisable(GL_BLEND);
	
	heli.activate();
	desenhaSuporteAterragem(quad);
	desenhaCaudaHeli(quad);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

	gluQuadricTexture(quad, GL_FALSE);
	
}
