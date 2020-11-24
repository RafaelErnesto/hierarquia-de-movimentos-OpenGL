#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>


GLfloat win = 3.0f;
GLfloat blue_angle = 90,
        orange_angle = -90,
        green_angle = 90,
        black_angle = -90,
        base_position = 0;
const int PI = 3.14159;

void RedimensionaJanela(GLsizei w, GLsizei h)
{
    // Especifica as dimens�es da Viewport
    glViewport(0, 0, w, h);

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D (-win, win, -win, win);
}



void circulo(float raio){
    double val = PI/ 180.0;
    glBegin(GL_TRIANGLE_FAN);
        for(int i = 0; i <= 360; i++){
            glVertex2f(cos(i * val) * raio,sin(i * val) * raio);
        }
    glEnd();
}

void retangulo(){
    glBegin(GL_QUADS);
        glVertex2f(0,-0.15);
        glVertex2f(1,-0.15);
        glVertex2f(1,0.15);
        glVertex2f(0,0.15);
    glEnd();
}

void point(){
    glBegin(GL_POINTS);
        glVertex2d(0,0);
    glEnd();
}

void braco(){
    glColor3f(1,0,0);
    glTranslatef(base_position,0,0);
    retangulo();//vermelho

    glTranslatef(0.5,0.1,0);
    glColor3f(0,0,1);
    glRotatef(blue_angle,0,0,1);
    retangulo();//azul
    glColor3f(1,1,0);
    circulo(0.2);

    glTranslatef(0.9,-0.01,0);
    glRotatef(green_angle,0,0,1);
    glColor3f(0,1,0);
    retangulo();//verde
    glColor3f(1,1,0);
    circulo(0.1);


    glTranslatef(0.95,0.015,0);
    glRotatef(black_angle,0,0,1);
    glColor3f(0,0,0);
    retangulo();//black*/
    glColor3f(1,1,0);
    circulo(0.1);

    glTranslatef(0.95,0.015,0);
    glRotatef(orange_angle,0,0,1);
    glColor3f(1,0.5,0);
    retangulo();//orange*/
    glColor3f(1,1,0);
    circulo(0.1);
}

void info(){
    char info[6][80] = {
        "Teclas de controle: ",
        "A e S movem a base para esquerda ou direita.",
        "Q e W rotacionam o bloco azul.",
        "E e R rotacionam o bloco verde.",
        "T e Y rotacionam o bloco preto.",
        "U e I rotacionam o bloco laranja"
    };

    float linha = -1.3;
    glColor3f(0,0,0);
     for(int j = 0; j < 6; j++ ){
        glRasterPos2f(-2,linha);//posição da linha
        int len;
        len = strlen(info[j]);
        char texto[len];

        strcpy(texto,info[j]);
        for ( int i = 0; i < len; ++i ){
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, texto[i]);
        }
        linha = linha - 0.3;
     }

}

void desenhaBraco(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-win,win,-win,win);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    info();
    braco();
    glFlush();
}

void movimentosTeclado(unsigned char key,int x, int y) {
    switch(key){
        case 'a':
            base_position = base_position - 0.1;
            desenhaBraco();
            break;
        case 's':
            base_position = base_position + 0.1;
            desenhaBraco();
            break;
        case 'q':
           if(blue_angle < 143){
                blue_angle++;
           }
            desenhaBraco();
            break;
        case 'w':
            if(blue_angle > 27){
                blue_angle--;
            }
            desenhaBraco();
            break;
        case 'e':
            green_angle++;
            desenhaBraco();
            break;
        case 'r':
            green_angle--;
            desenhaBraco();
            break;
        case 't':
            black_angle++;
            desenhaBraco();
            break;
        case 'y':
            black_angle--;
            desenhaBraco();
            break;
        case 'u':
            orange_angle++;
            desenhaBraco();
            break;
        case 'i':
            orange_angle--;
            desenhaBraco();
            break;
    }
}



int main(void){
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(300,150);
    glutCreateWindow("Braco mecanico");
    glutDisplayFunc(desenhaBraco);
    glutReshapeFunc(RedimensionaJanela);
    glutKeyboardFunc(movimentosTeclado);
    glClearColor(1,1,1,1);
    glutMainLoop();
    return 0;
}
