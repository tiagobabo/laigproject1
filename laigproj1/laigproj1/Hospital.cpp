//CPP FILE Hospital

#include "Hospital.h"

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