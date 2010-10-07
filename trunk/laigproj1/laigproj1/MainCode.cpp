#include "MainCode.h"

void disableColors()
{
	glDisable(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat1_shininess);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,  mat1_specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,   mat1_diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,   mat1_ambient);
}

void desenhaRecXZ(float x1, float z1, float x2, float z2, int imagem)
{
	glBindTexture(GL_TEXTURE_2D, imagem);
	glBegin(GL_POLYGON);
		glNormal3d(0.0,1.0,0.0);  // esta normal fica comum aos 4 vertices
		glTexCoord2f(0.0,0.0); glVertex3d( x1, 0.0,  z1);
		glTexCoord2f(escala/2,0.0); glVertex3d(x2, 0.0,  z1);
		glTexCoord2f(escala/2,escala); glVertex3d(x2, 0.0,  z2);
		glTexCoord2f(0.0,escala); glVertex3d(x1, 0.0,  z2);
	glEnd();
}

void desenhaRecXZ2(float x1, float z1, float x2, float z2, int imagem)
{
	glBindTexture(GL_TEXTURE_2D, imagem);
	glBegin(GL_POLYGON);
		glNormal3d(0.0,-1.0,0.0);  // esta normal fica comum aos 4 vertices
		glTexCoord2f(0.0,0.0); glVertex3d( x1, 0.0,  z1);
		glTexCoord2f(0.0,escala); glVertex3d(x1, 0.0,  z2);
		glTexCoord2f(escala/2,escala); glVertex3d(x2, 0.0,  z2);
		glTexCoord2f(escala/2,0.0); glVertex3d(x2, 0.0,  z1);
	glEnd();
}

void desenhaTrianguloXY(float x1, float y1, float x2, float y2, int imagem, float normal[3])
{
	arvore.activate();
	glBindTexture(GL_TEXTURE_2D, imagem);
	glBegin(GL_POLYGON);
		glNormal3d(normal[0],normal[1],normal[2]);  // esta normal fica comum aos 3 vertices
		glTexCoord2f(0.0,0.0); glVertex3d(-x2, y1, 0.0);
		glTexCoord2f(escala/2,escala); glVertex3d(x2,y1,0.0);
		glTexCoord2f(escala/2,0.0); glVertex3d(0.0, y2, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
		glNormal3d(-normal[0],-normal[1],-normal[2]);  // esta normal fica comum aos 3 vertices
		glTexCoord2f(escala/2,escala); glVertex3d(x2,y1,0.0);
		glTexCoord2f(0.0,0.0); glVertex3d(-x2, y1, 0.0);
		glTexCoord2f(escala/2,0.0); glVertex3d(0.0, y2, 0.0);
	glEnd();
}

void desenhaJanelas()
{
	float distJanelas = 0.7;
	// janelas frontais
	for(int i = 0; i < 3; i++)
	{
			glPushMatrix();
			glTranslatef((PosChaoCX1+PosChaoCX2)/2+(hospLarg-larguraJanela)/2-hospLarg/2,alturaPorta+(alturaJanela+distJanelas)*i+distJanelas,(PosChaoZ2/4)*3+(hospProf/2)+0.01);
			glBegin(GL_POLYGON);
				glNormal3d(0.0,0.0,1.0);  // esta normal fica comum aos 4 vertices
				glTexCoord2f(0.0,0.0); glVertex3d( 0.0, 0.0,  0.0);
				glTexCoord2f(5.0,0.0); glVertex3d(larguraJanela, 0.0, 0.0);
				glTexCoord2f(5.0,1.0); glVertex3d(larguraJanela, alturaJanela, 0.0);
				glTexCoord2f(0.0,1.0); glVertex3d(0.0, alturaJanela, 0.0);
			glEnd();
			glPopMatrix();
	}
	//janelas laterais
	for(int i = 0; i < 4; i++)
	{
			glPushMatrix();
			glTranslatef((PosChaoCX1+PosChaoCX2)/2+hospLarg/2+0.01,alturaPorta-alturaJanela+(alturaJanela+distJanelas)*i,(PosChaoZ2/4)*3+(hospProf/2)-(hospProf-larguraJanelaL)/2);
			glRotatef(90.0,0.0,1.0,0.0);
			glBegin(GL_POLYGON);
				glNormal3d(1.0,0.0,0.0);  // esta normal fica comum aos 4 vertices
				glTexCoord2f(0.0,0.0); glVertex3d( 0.0, 0.0,  0.0);
				glTexCoord2f(3.0,0.0); glVertex3d(larguraJanelaL, 0.0, 0.0);
				glTexCoord2f(3.0,1.0); glVertex3d(larguraJanelaL, alturaJanela, 0.0);
				glTexCoord2f(0.0,1.0); glVertex3d(0.0, alturaJanela, 0.0);
			glEnd();
			glPopMatrix();

			glPushMatrix();
			glTranslatef((PosChaoCX1+PosChaoCX2)/2-hospLarg/2-0.01,alturaPorta-alturaJanela+(alturaJanela+distJanelas)*i,(PosChaoZ2/4)*3-(hospProf/2)+(hospProf-larguraJanelaL)/2);
			glRotatef(-90.0,0.0,1.0,0.0);
			glBegin(GL_POLYGON);
				glNormal3d(-1.0,0.0,0.0);  // esta normal fica comum aos 4 vertices
				glTexCoord2f(0.0,0.0); glVertex3d( 0.0, 0.0,  0.0);
				glTexCoord2f(3.0,0.0); glVertex3d(larguraJanelaL, 0.0, 0.0);
				glTexCoord2f(3.0,1.0); glVertex3d(larguraJanelaL, alturaJanela, 0.0);
				glTexCoord2f(0.0,1.0); glVertex3d(0.0, alturaJanela, 0.0);
			glEnd();
			glPopMatrix();
	}

}

void desenhaHospital(GLUquadric * quad)
{
	// edificio
	float tamanhoCubo = 1.0;
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(corHospital[0], corHospital[1], corHospital[2]);
	glPushMatrix();
	glTranslatef((PosChaoCX1+PosChaoCX2)/2,hospAlt/2,3*(PosChaoZ2/4));
	glScalef(hospLarg,hospAlt,hospProf);
	glutSolidCube(tamanhoCubo);
	glPopMatrix();
	
	//letreiro HJS
	glPushMatrix();
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glEnable(GL_LINE_SMOOTH);
	glLineWidth(tamanhoLetr);
	glTranslatef((PosChaoCX1+PosChaoCX2)/2-104.76*escalaLetr,hospAlt,3*(PosChaoZ2/4)+telhadoLarg/2);
	glScalef(escalaLetr, escalaLetr, escalaLetr);
	glColor3f(corLetreiro[0], corLetreiro[1], corLetreiro[2]);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, 'H');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, 'S');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, 'J');
	glDisable(GL_BLEND);
	glDisable(GL_LINE_SMOOTH);
	glPopMatrix();
	glDisable(GL_NORMALIZE);
	disableColors();

	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 13);
	
	// porta
	glPushMatrix();
	glTranslatef((PosChaoCX1+PosChaoCX2)/2-larguraPorta/2,0.0,(PosChaoZ2/4)*3+(hospProf/2)+0.01);
	glColor3f(corPorta[0], corPorta[1], corPorta[2]);
	glBegin(GL_POLYGON);
		glNormal3d(0.0,0.0,1.0);  // esta normal fica comum aos 4 vertices
		glTexCoord2f(0.0,0.0); glVertex3d( 0.0, 0.0,  0.0);
		glTexCoord2f(1.0,0.0); glVertex3d(larguraPorta, 0.0, 0.0);
		glTexCoord2f(1.0,1.0); glVertex3d(larguraPorta, alturaPorta, 0.0);
		glTexCoord2f(0.0,1.0); glVertex3d(0.0, alturaPorta, 0.0);
	glEnd();
	glPopMatrix();


	glBindTexture(GL_TEXTURE_2D, 12);

	desenhaJanelas();

	glBindTexture(GL_TEXTURE_2D, 7);

	//telhado
	glPushMatrix();
	glTranslatef((PosChaoCX1+PosChaoCX2)/2,hospAlt,3*(PosChaoZ2/4));
	desenhaRecXZ2(-telhadoComp/2, telhadoLarg/2, telhadoComp/2, -telhadoLarg/2, 7);
	glPopMatrix();
	
	
	//triangulos
	//calcular o vector normal dos triângulos
	float vTri1[3] = {0.0, 0.0, 1.0};
	float vTri2[3] = {(telhadoComp-telhadoAresta)/2, telhadoAlt, telhadoLarg/2};
	float vTriNor[3] = {vTri1[1]*vTri2[2]-vTri1[2]*vTri2[1], vTri1[2]*vTri2[0]-vTri1[0]*vTri2[2], vTri1[0]*vTri2[1]-vTri1[1]*vTri2[0]}; 
	float normaVec = sqrt(vTriNor[0]*vTriNor[0]+vTriNor[1]*vTriNor[1]+vTriNor[2]*vTriNor[2]);
	int i = 0;
	for(i; i < 3; i++) vTriNor[i] = vTriNor[i]/normaVec;

	glPushMatrix();
	glTranslatef((PosChaoCX1+PosChaoCX2)/2-telhadoComp/2,hospAlt,3*(PosChaoZ2/4));
	glBegin(GL_POLYGON);
		glNormal3d(vTriNor[0],vTriNor[1],vTriNor[2]);  // esta normal fica comum aos 3 vertices
		glTexCoord2f(0.0,0.0);	glVertex3d(0.0, 0.0, -telhadoLarg/2);
		glTexCoord2f(escalaT,0.0);	glVertex3d(0.0,0.0,telhadoLarg/2);
		glTexCoord2f(escalaT/2,escalaT);	glVertex3d((telhadoComp-telhadoAresta)/2, telhadoAlt, 0.0);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef((PosChaoCX1+PosChaoCX2)/2+telhadoComp/2,hospAlt,3*(PosChaoZ2/4));
	glBegin(GL_POLYGON);
		glNormal3d(-vTriNor[0],vTriNor[1],vTriNor[2]);  // esta normal fica comum aos 3 vertices
		glTexCoord2f(0.0,0.0); glVertex3d(0.0, 0.0, -telhadoLarg/2);
		glTexCoord2f(escalaT/2,escalaT); glVertex3d(-(telhadoComp-telhadoAresta)/2, telhadoAlt, 0.0);
		glTexCoord2f(escalaT,0.0); glVertex3d(0.0,0.0,telhadoLarg/2);
	glEnd();
	glPopMatrix();
	

	//quadrilateros
	//calcular o vector normal dos quadrilateros
	float vQuad1[3] = {1.0, 0.0, 0.0};
	float vQuad2[3] = {-(telhadoComp-telhadoAresta)/2-telhadoComp/2, telhadoAlt, -telhadoLarg/2};
	float vQuadNor[3] = {vQuad1[1]*vQuad2[2]-vQuad1[2]*vQuad2[1], vQuad1[2]*vQuad2[0]-vQuad1[0]*vQuad2[2], vQuad1[0]*vQuad2[1]-vQuad1[1]*vQuad2[0]}; 
	float normaVecQuad = sqrt(vQuadNor[0]*vQuadNor[0]+vQuadNor[1]*vQuadNor[1]+vQuadNor[2]*vQuadNor[2]);
	for(i=0; i < 3; i++) vQuadNor[i] = vQuadNor[i]/normaVecQuad;

	glPushMatrix();
	glTranslatef((PosChaoCX1+PosChaoCX2)/2,hospAlt,3*(PosChaoZ2/4)+telhadoLarg/2);
	glBegin(GL_POLYGON);
		glNormal3d(vQuadNor[0],vQuadNor[1],vQuadNor[2]);  // esta normal fica comum aos 4 vertices
		glTexCoord2f(0.0,0.0); glVertex3d(-telhadoComp/2, 0.0, 0.0);
		glTexCoord2f(escalaT,0.0); glVertex3d(telhadoComp/2, 0.0, 0.0);
		glTexCoord2f(3*(escalaT/4),escalaT); glVertex3d((telhadoComp-telhadoAresta)/2,telhadoAlt,-telhadoLarg/2);
		glTexCoord2f(escalaT/4,escalaT); glVertex3d(-(telhadoComp-telhadoAresta)/2,telhadoAlt,-telhadoLarg/2);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef((PosChaoCX1+PosChaoCX2)/2,hospAlt,3*(PosChaoZ2/4)-telhadoLarg/2);
	glBegin(GL_POLYGON);
		glNormal3d(vQuadNor[0],vQuadNor[1],-vQuadNor[2]);  // esta normal fica comum aos 4 vertices
		glTexCoord2f(0.0,0.0); glVertex3d(-telhadoComp/2, 0.0, 0.0);
		glTexCoord2f(escalaT/4,escalaT); glVertex3d(-(telhadoComp-telhadoAresta)/2,telhadoAlt,telhadoLarg/2);
		glTexCoord2f(3*(escalaT/4),escalaT); glVertex3d((telhadoComp-telhadoAresta)/2,telhadoAlt,telhadoLarg/2);
		glTexCoord2f(escalaT,0.0); glVertex3d(telhadoComp/2, 0.0, 0.0);
	glEnd();
	glPopMatrix();
	
	glDisable(GL_TEXTURE_2D);
	//glEnable(GL_DEPTH_TEST);
	
}

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

void desenhaChao()
{
	glEnable(GL_TEXTURE_2D);
	desenhaRecXZ(PosChaoEX1,PosChaoZ1,PosChaoEX2,PosChaoZ2, 1);
	desenhaRecXZ(PosChaoCX1,PosChaoZ1,PosChaoCX2,PosChaoZ2, 2);
	desenhaRecXZ(PosChaoDX1,PosChaoZ1,PosChaoDX2,PosChaoZ2,3);
	glDisable(GL_TEXTURE_2D);
}

void desenhaArvoreT1(GLUquadric * quad, float posX, float posZ, float height)
{
	gluQuadricTexture(quad, GL_TRUE);
	glEnable(GL_TEXTURE_2D);

	// tronco
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, 4);
	glTranslatef(posX,0.0,posZ);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(quad, raioTInf, raioTSup, height, slicesT1, stacksT1);
	glPopMatrix();
	
	arvore.activate();
	// folhagem
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, 5);
	glTranslatef(posX,alturaA1,posZ);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(quad, raioTInf*escalaTB, raioTSup, height-alturaA1, slicesT1, stacksT1);
	glPopMatrix();
	
	glDisable(GL_TEXTURE_2D);
	gluQuadricTexture(quad, GL_FALSE);
}

void desenhaArvoreT2(GLUquadric * quad, float posX, float posZ, float height)
{
	glEnable(GL_TEXTURE_2D);

	// tronco
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, 4);
	glTranslatef(posX,0.0,posZ);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(quad, raioTInf, raioTSup, height, slicesT1, stacksT1);
	glPopMatrix();
	
	// folhagem 1
	glPushMatrix();
	glTranslatef(posX, height-height/razTroncFolha, posZ);
	desenhaTrianguloXY(0.0,0.0,height/rAltuLargA2,height/razTroncFolha, 6, normal1AT2);
	glPopMatrix();
	
	// folhagem 2
	glPushMatrix();
	glTranslatef(posX, height-height/razTroncFolha, posZ);
	glRotatef(-90.0, 0.0, 1.0, 0.0);
	desenhaTrianguloXY(0.0,0.0,height/rAltuLargA2, height/razTroncFolha, 6, normal1AT2);
	glPopMatrix();
	
	// folhagem 3
	glPushMatrix();
	glTranslatef(posX, height-height/razTroncFolha, posZ);
	glRotatef(45.0, 0.0, 1.0, 0.0);
	desenhaTrianguloXY(0.0,0.0,height/rAltuLargA2,height/razTroncFolha, 6, normal2AT2);
	glPopMatrix();
	
	// folhagem 4
	glPushMatrix();
	glTranslatef(posX, height-height/razTroncFolha, posZ);
	glRotatef(-45.0, 0.0, 1.0, 0.0);
	desenhaTrianguloXY(0.0,0.0,height/rAltuLargA2,height/razTroncFolha, 6, normal2AT2);
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}

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

void myInitTransforms()
{
	delta_rotate = (double) mili_secs/1000.0 * ANGULAR_SPEED *360.0;
	delta_radius = (double) mili_secs/1000.0 * RADIUS_SPEED;
}
float factori = 0.01;
void animacaoHelice(int dummy)
{
	if(MotorAng == 360)
		MotorAng = 0;
	else
	{
		if(factori < 1.0)
		{
			MotorAng += delta_rotate*factori;
			factori += 0.01;
		}
		else
		{
			MotorAng += delta_rotate*factori;
			if(animation == 0) animation = 1;
		}
	}	
	glutTimerFunc(mili_secs, animacaoHelice, 0);
}


void animacaoVermelha(int status)
{

	switch(status)
	{
	case 0:
		{
			if(heliY<alturaMAXanim)
			{
				if(rodaHeliang<90)
					rodaHeliang+=speedTurn;
				heliY+=delta_radius;
				glutTimerFunc(mili_secs, animacaoVermelha, status);
			}
			else
				glutTimerFunc(mili_secs, animacaoVermelha, ++status);
			break;
		}
	case 1:
		{
			if(heliZ < zIniRota)
			{
				if(heliXang < angMovFrente)
					heliXang+=stepAngMovFrente;
				heliZ+=delta_radius;
				glutTimerFunc(mili_secs, animacaoVermelha, status);
			}
			else
				glutTimerFunc(mili_secs, animacaoVermelha, ++status);
			break;
		}
	case 2:
		{
			if(heliX < xFimRota)
			{
				if(rotAng <90)
				{
					rotCenX = xRaioRota;
					rotCenY = (heliY+alturaHeli/2);
					rotCenZ = 0;
					rotY = 1.0;
					rotAng += stepRota;
				}
				else
				{
					heliX+=delta_radius;
					if(heliX< -limXendireita2)
						if(heliXang > 0)
							heliXang-=stepAngMovFrente;
				}
				glutTimerFunc(mili_secs, animacaoVermelha, status);
			}
			else
				glutTimerFunc(mili_secs, animacaoVermelha, ++status);
			break;
		}
	case 3:
		{
			if(heliY>0)
			{
				if(rodaHeliang > -90)
					rodaHeliang-=speedTurn;
				heliY-=delta_radius;
				glutTimerFunc(mili_secs, animacaoVermelha, status);
			}
			else
				glutTimerFunc(mili_secs, animacaoVermelha, ++status);
			break;
		}
	default:
		break;
	}
}

void resetAni()
{
	rodaHeliang = 0;
	rotAng = 0.0;
	rotCenX = 0;
	rotCenY = 0;
	rotCenZ = 0;
	rotY = 1;
	heliX = 0;
	heliY = 0;
	heliZ = 0;
}

void animacaoVerde(int status)
{
	switch(status)
	{
	case 0:
		{
			resetAni();
			glutTimerFunc(mili_secs, animacaoVerde, ++status);
			break;
		}
	case 1:
		{
			if(heliY< alturaMAXanim)
			{
				if(rodaHeliang > rotacaoVerdeIni && heliY > alturaIniRota)
				{
					rodaHeliang-=speedTurn;
				}
				if(heliY>alturaIniAnda)
				{
					heliX -= delta_radius;
					heliZ -= delta_radius*razaoZXAnda;
					if(heliXang < angMovFrente)
						heliXang+=stepAngMovFrente;
				}
				heliY+=delta_radius;
				glutTimerFunc(mili_secs, animacaoVerde, status);
			}
			else
				glutTimerFunc(mili_secs, animacaoVerde, ++status);
			break;
		}
	case 2:
		{
			if(heliX > limXesq && heliZ > limZtras)
			{
				if(heliXang < angMovFrente && heliX> limXendireita)
					heliXang+=stepAngMovFrente;
				else if(heliXang > 0 && heliX < limXendireita)
				{
					heliXang -=stepAngMovFrente;
				}
				heliX -= delta_radius;
				heliZ -= delta_radius/2;
				glutTimerFunc(mili_secs, animacaoVerde, status);
			}
			else
				glutTimerFunc(mili_secs, animacaoVerde, ++status);
			break;
		}
	case 3:
		{
			if(heliY > alturaMINanim)
			{
				if(rodaHeliang<90)
					rodaHeliang+=speedTurn;
				heliY-=delta_radius;
				glutTimerFunc(mili_secs, animacaoVerde, status);
			}
			else
				glutTimerFunc(mili_secs, animacaoVerde, ++status);
			break;
		}
	case 4:
		glutTimerFunc(mili_secs, animacaoVermelha, 0);
		break;
	default:
		break;
	}
}

void camera3()
{
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glFrustum( -xy_aspect*.04, xy_aspect*.04, -.04, .04, .1, 500.0 );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	gluLookAt( eyex3, eyey3, eyez3, centerx3, centery3, centerz3, upx3, upy3, upz3 ); 
}

void showCamera(char* camera)
{
	glDisable( GL_LIGHTING );  /* Disable lighting while we render text */
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluOrtho2D( 0.0, 100.0, 0.0, 100.0  );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	glColor3ub( 1, 1, 1 );
	glRasterPos2i( 1, 96);
	int len = strlen(camera);
	for (int i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, camera[i]);
	}
	glEnable( GL_LIGHTING );
}

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


void display(void)
{
	
	// ****** declaracoes internas 'a funcao display() ******
	
	//float temp;

	GLUquadric* glQ;	// nec. p/ criar sup. quadraticas (cilindros, esferas...)

	// ****** fim de todas as declaracoes da funcao display() ******

	glQ = gluNewQuadric();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
	
	if(camera == 1)
	{
		// inicializacoes da matriz de visualizacao
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glFrustum( -xy_aspect*.04, xy_aspect*.04, -.04, .04, .1, 500.0 );

		//inicializacoes da matriz de transformacoes geometricas
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	// afasta a cena de 25 unidades mais a distância que...
	// ...decorre da utilizacao do botao de afastamento (pseudo-zoom)
    glTranslatef( obj_pos[0]-VposX, obj_pos[1]-VposY, -obj_pos[2]-zoom );
		// tambem se poderia ter feito:
		//glTranslated(0.0,0.0,-25.0);
		//glTranslatef( obj_pos[0], obj_pos[1], -obj_pos[2] );

	// roda a cena para ficar em perspectiva
	glRotated( VangleX, 1.0,0.0,0.0 );		// 20 graus em torno de X
	glRotated( VangleY, 0.0,1.0,0.0 );		//-45 graus em torno de Y
	// roda a cena de acordo com o botao (esfera) de rotacao
	glMultMatrixf( view_rotate );
	view_rot->enable();
	trans_z->enable();
	}
	else if(camera == 2)
	{
		glMatrixMode( GL_PROJECTION );
		glLoadIdentity();
		glFrustum( -xy_aspect*.04, xy_aspect*.04, -.04, .04, .1, 500.0 );
		glMatrixMode( GL_MODELVIEW );
		glLoadIdentity();
		gluLookAt( 22.5, 50.0, -15.0, 22.5, 0.0, -15.0, 0.0, 0.0, -1.0 ); 
		view_rot->disable();
		trans_z->disable();
	}
	else if(camera == 3)
	{
		camera3();
		view_rot->disable();
		trans_z->disable();
	}
	
	
	// permissao de atribuicao directa de cores
	// para objectos que nao tem material atribuido, como
	// e' o caso dos eixos e da esfera que simboliza a fonte de luz...
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
	
	// cilindro representativo do eixo X
	glColor3f(1.0,0.0,0.0);		// vermelho
	glPushMatrix();
	glRotated(90.0, 0.0,1.0,0.0 );
	gluCylinder(glQ, axis_radius_begin, axis_radius_end,
		             axis_lenght, axis_nslices, axis_nstacks);   // nao tem bases
	glPopMatrix();

	// cilindro representativo do eixo Y
	glColor3f(0.0,1.0,0.0);		// verde
	glPushMatrix();
	glRotated(-90.0, 1.0,0.0,0.0 );
	gluCylinder(glQ, axis_radius_begin, axis_radius_end,
		             axis_lenght, axis_nslices, axis_nstacks);   // nao tem bases
	glPopMatrix();
	
	// cilindro representativo do eixo Z
	glColor3f(0.0,0.0,1.0);		// azul
	glPushMatrix();
	// nao necessita rotacao... glRotated(...);
	gluCylinder(glQ, axis_radius_begin, axis_radius_end,
		             axis_lenght, axis_nslices, axis_nstacks);   // nao tem bases
	glPopMatrix();

	
	for(int i = 0; i < nlights; i++)
	{
			lights_position[i][0] = lightsx[i];
			lights_position[i][1] = lightsy[i];
			lights_position[i][2] = lightsz[i];
			glLightfv(GL_LIGHT0+i, GL_POSITION, lights_position[i]);
	}
	
	 
	for(int i = 0; i < nlights; i++)
	{
		// ... e da esfera que a simboliza
		glColor3f(1.0,1.0,0.0);		// cor amarela
		gluQuadricOrientation( glQ, GLU_INSIDE);
		glPushMatrix();
		glTranslated(lightsx[i],lightsy[i],lightsz[i]);
		gluSphere(glQ, symb_lights_radius[i], symb_lights_slices[i], symb_lights_stacks[i]);
		glPopMatrix();
		gluQuadricOrientation( glQ, GLU_OUTSIDE);
	}

	// direccao da luz0
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, angLuz);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot0);
	// direccao da luz1
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, angLuz);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot1);
	// direccao da luz2
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, angLuz);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot2);
	// direccao da luz3
	glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, angLuz);
	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, spot3);
	
	disableColors();
	
	//chamada das funções
	glCallList(chaoEArvores);
	glCallList(hospital);
	glCallList(heliporto);
	desenhaHelicoptero(glQ);
	desenhaTorre(glQ);
	desenhaHangar();
	// swapping the buffers causes the rendering above to be shown
	if(camera == 1)  showCamera("1");
	else if(camera == 2) showCamera("2");
	else if(camera == 3) showCamera("3");

	if(animation == 1)
		animacaoVerde(0);

	glutSwapBuffers();
	glFlush();
}

/* Mouse handling */
void processMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{	 
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{	
	}
	
	glutPostRedisplay();
	
}

void processMouseMoved(int x, int y)
{
	
	// pedido de refrescamento da janela
	glutPostRedisplay();				

}

void processPassiveMouseMoved(int x, int y)
{

	// pedido de refrescamento da janela
	glutPostRedisplay();				
}

void reshape(int w, int h)
{
	int tx, ty, tw, th;

	GLUI_Master.get_viewport_area( &tx, &ty, &tw, &th );
	glViewport( tx, ty, tw, th );
	xy_aspect = (float)tw / (float)th;

	glutPostRedisplay();

}


void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 27:		// tecla de escape termina o programa
         exit(0);
         break;
	  case 'l':
		 {
			if(camera == 3)
			{
				eyex3 +=1.0;
				camera3();
			}
		  }
		 break;	
	  case 'j':
		  {
			if(camera == 3)
			{
				eyex3 -=1.0;
				camera3();
			}
		  }
		 break;	
	  case 'k':
		 {
			 if(camera == 3)
			 {
				eyey3 +=1.0;
				camera3();
			 }
		  }
		 break;	
	  case 'i':
		 {
			 if(camera == 3)
			 {
				eyey3 -=1.0;
				camera3();
			 }
		  }
		 break;	
	  case 'q':
		 {
			 if(camera == 3)
			 {
				eyez3 -=1.0;
				camera3();
			 }
		  }
		 break;	
	  case 'a':
		 {
			 if(camera == 3)
			 {
				eyez3 +=1.0;
				camera3();
			 }
		  }
		 break;	
	  case '1':
		 camera = 1;
		 break;
	  case '2':
		  {
			camera = 2;
		 break;	
		  }
	  case '3':
		  {
			camera = 3;
			break;	
		  }
	   case '+':
		 heliY += 1.0;
		 break;	
	  case '-':
		  {
			  if(heliY>0)
				heliY -= 1.0;
			  else
			  {
				  heliXang = 0;
				  heliZang = 0;
			  }
		  }
		 break;
	  case 'p':
		  {
			  animation=1;
		  }
	  default: break;
   }
}


void myGlutIdle( void )
{
  /* According to the GLUT specification, the current window is 
     undefined during an idle callback.  So we need to explicitly change
     it if necessary */
  if ( glutGetWindow() != main_window ) 
    glutSetWindow(main_window);  


  glutPostRedisplay();

}

void inicializacao()
{
	glFrontFace(GL_CCW);		// Front faces defined using a counterclockwise rotation
	glDepthFunc(GL_LEQUAL);		// Por defeito e GL_LESS
	glEnable(GL_DEPTH_TEST);	// Use a depth (z) buffer to draw only visible objects


	// Face Culling para aumentar a velocidade
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);		// GL_FRONT, GL_BACK, GL_FRONT_AND_BACK


	// Define que modelo de iluminacao utilizar; consultar o manual de referencia
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, light_ambient);  // define luz ambiente
	glLightModelf (GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
	glLightModeli (GL_LIGHT_MODEL_LOCAL_VIEWER, 1);
	
	// por defeito a cor de fundo e o preto
	glClearColor(corFundo[0], corFundo[1], corFundo[2], 1.0);    // cor de fundo a branco

	for(int i = 0; i < nlights; i++)
	{
		glLightfv(GL_LIGHT0+i, GL_AMBIENT, lights_ambient[i]);
		glLightfv(GL_LIGHT0+i, GL_DIFFUSE, lights_diffuse[i]);
		glLightfv(GL_LIGHT0+i, GL_SPECULAR, lights_specular[i]);
		glLightf(GL_LIGHT0+i, GL_CONSTANT_ATTENUATION,  lights_kc[i]);
		glLightf(GL_LIGHT0+i, GL_LINEAR_ATTENUATION,    lights_kl[i]);
		glLightf(GL_LIGHT0+i, GL_QUADRATIC_ATTENUATION, lights_kq[i]);
	}
	
	// Permitir calculos de iluminacao
	glEnable(GL_LIGHTING);
	
	for(int i = 0; i < nlights; i++)
	{
		glEnable(GL_LIGHT0+i);
	}

	// Declaracoe para shading
	glShadeModel(GL_SMOOTH);			// GL_FLAT / GL_SMOOTH
	glPolygonMode(GL_FRONT, GL_FILL);	// preence a face da frente dos poligonos
	//glPolygonMode(GL_FRONT, GL_LINE);	// desenha arestas dos poligonos


	// Texturas a utilizar (ver classe RGBpixmap)
	pixmap.readBMPFile("grass.bmp");
	pixmap.setTexture(1);

	pixmap.readBMPFile("floor.bmp");
	pixmap.setTexture(2);

	pixmap.readBMPFile("gravel.bmp");
	pixmap.setTexture(3);

	pixmap.readBMPFile("tree_base.bmp");
	pixmap.setTexture(4);

	pixmap.readBMPFile("leaf.bmp");
	pixmap.setTexture(5);

	pixmap.readBMPFile("leaf2.bmp");
	pixmap.setTexture(6);

	pixmap.readBMPFile("tile.bmp");
	pixmap.setTexture(7);

	pixmap.readBMPFile("metal.bmp");
	pixmap.setTexture(8);
	
	pixmap.readBMPFile("heliport.bmp");
	pixmap.setTexture(9);

	pixmap.readBMPFile("yellow_INEM.bmp");
	pixmap.setTexture(10);

	pixmap.readBMPFile("blue_INEM.bmp");
	pixmap.setTexture(11);

	pixmap.readBMPFile("windows.bmp");
	pixmap.setTexture(12);

	pixmap.readBMPFile("door.bmp");
	pixmap.setTexture(13);

	pixmap.readBMPFile("red_cross2.bmp");
	pixmap.setTexture(14);

	pixmap.readBMPFile("hangar.bmp");
	pixmap.setTexture(15);

	pixmap.readBMPFile("torre.bmp");
	pixmap.setTexture(16);

	pixmap.readBMPFile("chaoplat.bmp");
	pixmap.setTexture(17);

	pixmap.readBMPFile("chopper.bmp");
	pixmap.setTexture(18);

	GLUquadric* glQ;	// nec. p/ criar sup. quadraticas (cilindros, esferas...)
	glQ = gluNewQuadric();

	glNewList(chaoEArvores, GL_COMPILE);
	desenhaChao();
	desenhaArvoreT1(glQ, arv1X, arv1Z, heightA1);
	desenhaArvoreT1(glQ, arv2X, arv2Z, heightA2);
	desenhaArvoreT2(glQ, arv3X, arv3Z, heightA3);
	desenhaArvoreT2(glQ, arv4X, arv4Z, heightA4);
	glEndList();

	glNewList(hospital, GL_COMPILE);
	desenhaHospital(glQ);
	glEndList();
	
	
	glNewList(heliporto, GL_COMPILE);
	desenhaHolofotes(glQ);
	desenhaHeliporto();
	glEndList();
	myInitTransforms();
	glutTimerFunc(0, animacaoHelice, 0);

}

int   light0_enabled = 1;
int   light1_enabled = 1;
int   light2_enabled = 1;
int   light3_enabled = 1;

void control_cb( int control )
{
  if ( control == LIGHT0_ENABLED_ID ) {
    if ( light0_enabled ) {
      glEnable( GL_LIGHT0 );
    }
    else {
      glDisable( GL_LIGHT0 ); 
    }
  }
  else if ( control == LIGHT1_ENABLED_ID ) {
    if ( light1_enabled ) {
      glEnable( GL_LIGHT1 );
    }
    else {
      glDisable( GL_LIGHT1 ); 
    }
  }
  else if ( control == LIGHT2_ENABLED_ID ) {
    if ( light2_enabled ) {
      glEnable( GL_LIGHT2 );
    }
    else {
      glDisable( GL_LIGHT2 ); 
    }
  }
  else if( control == LIGHT3_ENABLED_ID ) {
    if ( light3_enabled ) {
      glEnable( GL_LIGHT3 );
    }
    else {
      glDisable( GL_LIGHT3 ); 
    }
  }
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize (DIMX, DIMY);
	glutInitWindowPosition (INITIALPOS_X, INITIALPOS_Y);
	main_window = glutCreateWindow (argv[0]);
 
	glutDisplayFunc(display);
	GLUI_Master.set_glutReshapeFunc(reshape);
	GLUI_Master.set_glutKeyboardFunc (keyboard);
	GLUI_Master.set_glutMouseFunc(processMouse);
	glutMotionFunc(processMouseMoved);
	glutPassiveMotionFunc(processPassiveMouseMoved);
	GLUI_Master.set_glutSpecialFunc( NULL );

	/*** Create the bottom subwindow ***/
	glui2 = GLUI_Master.create_glui_subwindow( main_window, GLUI_SUBWINDOW_BOTTOM );
	glui2->set_main_gfx_window( main_window );

	view_rot = glui2->add_rotation( "Rotacao", view_rotate );
	view_rot->set_spin( 1.0 );
	
	glui2->add_column( false );
	trans_z = glui2->add_translation( "Zoom", GLUI_TRANSLATION_Z, &obj_pos[2] );
	trans_z->set_speed( .02 );
	
	/******** Add some controls for lights ********/
	glui2->add_column( false );

	glui2->add_checkbox("Luz 1", &light0_enabled,
				LIGHT0_ENABLED_ID, control_cb );
	glui2->add_checkbox("Luz 2", &light1_enabled,
				LIGHT1_ENABLED_ID, control_cb );
	glui2->add_checkbox("Luz 3", &light2_enabled,
				LIGHT2_ENABLED_ID, control_cb );
	glui2->add_checkbox("Luz 4", &light3_enabled,
				LIGHT3_ENABLED_ID, control_cb );

	/* We register the idle callback with GLUI, not with GLUT */
	GLUI_Master.set_glutIdleFunc( myGlutIdle );
   
	inicializacao();
	glutMainLoop();

	return 0;
}
