#include "MainCode.h"
#include "Auxiliar.h"

void disableColors()
{
	glDisable(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat1_shininess);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,  mat1_specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,   mat1_diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,   mat1_ambient);
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
	case 1:
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
	case 2:
		if(rotAng < 90)
		{
			rotCenX = xRaioRota;
			rotCenY = (heliY+alturaHeli/2);
			rotCenZ = 0;
			rotY = 1.0;
			rotAng += stepRota;
			glutTimerFunc(mili_secs, animacaoVermelha, status);
		}
		else
			glutTimerFunc(mili_secs, animacaoVermelha, ++status);
		break;
	case 3:
		if(heliX < xFimRota)
		{
			heliX+=delta_radius;
			if(heliX< -limXendireita2)
				if(heliXang > 0)
					heliXang-=stepAngMovFrente;
			glutTimerFunc(mili_secs, animacaoVermelha, status);
		}
		else
			glutTimerFunc(mili_secs, animacaoVermelha, ++status);
		break;
	case 4:
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
	glCallList(helicoptero);
	glCallList(hangarETorre);
	// swapping the buffers causes the rendering above to be shown
	if(camera == 1)  showCamera("1");
	else if(camera == 2) showCamera("2");
	else if(camera == 3) showCamera("3");

	if(animation == 1 && firstTime == 1)
	{
		firstTime = 0;
		animacaoVerde(0);
	}

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

	glNewList(helicoptero, GL_COMPILE);
	desenhaHelicoptero(glQ);
	glEndList();

	glNewList(hangarETorre, GL_COMPILE);
	desenhaHangar();
	desenhaTorre(glQ);
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
