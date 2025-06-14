#include <GL/glut.h>
#include <math.h>
#include <cmath>
#include <vector>
#include <fstream>

#define M_PI 3.14159265358979323846

using namespace std;

GLuint textureID;  // ID tekstur OpenGL

const int numSlices = 50;
const int numStacks = 50;

// Struktur untuk menyimpan warna piksel
struct Pixel {
    unsigned char r, g, b, a;
};

// Fungsi untuk membaca gambar BMP sederhana
std::vector<Pixel> readBMP(const char* imagePath, int& width, int& height) {
    std::ifstream file(imagePath, std::ios::binary);
    if (!file.is_open()) {
        fprintf(stderr, "Error loading texture: Unable to open file\n");
        return std::vector<Pixel>();
    }

    // Baca header BMP sederhana
    file.seekg(18);
    file.read(reinterpret_cast<char*>(&width), sizeof(int));
    file.read(reinterpret_cast<char*>(&height), sizeof(int));

    // Baca data piksel
    file.seekg(54); // Lewati header BMP
    std::vector<Pixel> pixels(width * height);
    file.read(reinterpret_cast<char*>(pixels.data()), sizeof(Pixel) * width * height);

    file.close();

    return pixels;
}

void loadTexture(const char* imagePath) {
    int imageWidth, imageHeight;
    std::vector<Pixel> imagePixels = readBMP(imagePath, imageWidth, imageHeight);

    if (imagePixels.empty()) {
        return;
    }

    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    // Terapkan data gambar ke tekstur
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth, imageHeight, 0,
        GL_BGR_EXT, GL_UNSIGNED_BYTE, imagePixels.data());
}



void drawSphere() {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);

    for (int i = 0; i < numStacks; ++i) {
        double lat0 = M_PI * (-0.5 + (double)(i) / numStacks);
        double z0 = sin(lat0);
        double zr0 = cos(lat0);

        double lat1 = M_PI * (-0.5 + (double)(i + 1) / numStacks);
        double z1 = sin(lat1);
        double zr1 = cos(lat1);

        glBegin(GL_QUAD_STRIP);
        for (int j = 0; j <= numSlices; ++j) {
            double lng = 2 * M_PI * (double)j / numSlices;
            double x = cos(lng);
            double y = sin(lng);

            // Sesuaikan koordinat tekstur
            glTexCoord2f((double)j / numSlices, 1.0 - (double)i / numStacks);
            glNormal3f(x * zr0, y * zr0, z0);
            glVertex3f(x * zr0, y * zr0, z0);

            glTexCoord2f((double)j / numSlices, 1.0 - (double)(i + 1) / numStacks);
            glNormal3f(x * zr1, y * zr1, z1);
            glVertex3f(x * zr1, y * zr1, z1);
        }
        glEnd();
    }

    glDisable(GL_TEXTURE_2D);
}


void drawCube() {
    glBegin(GL_QUADS);

    // Front face
    glColor3ub(51, 26, 0);
    glVertex3f(-0.5, -1.7, 0.5);
    glVertex3f(0.5, -1.7, 0.5);
    glVertex3f(0.5, -1.5, 0.5);
    glVertex3f(-0.5, -1.5, 0.5);

    // Back face
    glColor3ub(51, 26, 0);
    glVertex3f(-0.5, -1.7, -0.5);
    glVertex3f(0.5, -1.7, -0.5);
    glVertex3f(0.5, -1.5, -0.5);
    glVertex3f(-0.5, -1.5, -0.5);

    // Right face
    glColor3ub(51, 26, 0);
    glVertex3f(0.5, -1.7, 0.5);
    glVertex3f(0.5, -1.7, -0.5);
    glVertex3f(0.5, -1.5, -0.5);
    glVertex3f(0.5, -1.5, 0.5);

    // Left face
    glColor3ub(51, 26, 0);
    glVertex3f(-0.5, -1.7, 0.5);
    glVertex3f(-0.5, -1.7, -0.5);
    glVertex3f(-0.5, -1.5, -0.5);
    glVertex3f(-0.5, -1.5, 0.5);

    // Top face
    glColor3ub(77, 38, 0);
    glVertex3f(-0.5, -1.5, 0.5);
    glVertex3f(0.5, -1.5, 0.5);
    glVertex3f(0.5, -1.5, -0.5);
    glVertex3f(-0.5, -1.5, -0.5);


    // Bottom face
    glColor3ub(102, 51, 0);
    glVertex3f(-0.5, -1.7, 0.5);
    glVertex3f(0.5, -1.7, 0.5);
    glVertex3f(0.5, -1.7, -0.5);
    glVertex3f(-0.5, -1.7, -0.5);

    glEnd();

}

void drawWoodenStick() {
    glColor3f(0.5, 0.35, 0.05);
    glPushMatrix();
    glTranslatef(0.0, -1.3, 0.0);
    glScalef(0.1, 0.5, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();
}

void drawWoodenStick2() {
    glColor3f(0.5, 0.35, 0.05);
    glPushMatrix();
    glTranslatef(0.0, 1.1, 0.0);
    glScalef(0.1, 0.3, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();
}


void drawTable() {
    glBegin(GL_QUADS);

    // Front face
    glColor3ub(51, 26, 0);
    glVertex3f(-3, -1.9, 1.5);
    glVertex3f(3, -1.9, 1.5);
    glVertex3f(3, -1.7, 1.5);
    glVertex3f(-3, -1.7, 1.5);

    // Back face
    glColor3ub(51, 26, 0);
    glVertex3f(-3, -1.9, -1.5);
    glVertex3f(3, -1.9, -1.5);
    glVertex3f(3, -1.7, -1.5);
    glVertex3f(-3, -1.7, -1.5);

    // Right face
    glColor3ub(51, 26, 0);
    glVertex3f(3, -1.9, 1.5);
    glVertex3f(3, -1.9, -1.5);
    glVertex3f(3, -1.7, -1.5);
    glVertex3f(3, -1.7, 1.5);

    // Left face
    glColor3ub(51, 26, 0);
    glVertex3f(-3, -1.9, 1.5);
    glVertex3f(-3, -1.9, -1.5);
    glVertex3f(-3, -1.7, -1.5);
    glVertex3f(-3, -1.7, 1.5);

    // Top face
    glColor3ub(77, 38, 0);
    glVertex3f(-3, -1.7, 1.5);
    glVertex3f(3, -1.7, 1.5);
    glVertex3f(3, -1.7, -1.5);
    glVertex3f(-3, -1.7, -1.5);


    glEnd();

}

void drawTableLeg(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(0.1, 3.0, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();
}

void drawBook() {

    glColor3ub(105, 105, 255);
    glPushMatrix();
    glTranslatef(-2.0, -1.5, -0.2);
    glScalef(1.5, 0.15, 2.0);
    glutSolidCube(1.0);
    glPopMatrix();

    glColor3ub(153, 0, 0);
    glPushMatrix();
    glTranslatef(-1.9, -1.1, -0.19);
    glScalef(1.3, 0.125, 1.6);
    glutSolidCube(1.0);
    glPopMatrix();

    glColor3ub(192, 192, 192);
    glPushMatrix();
    glTranslatef(-1.9, -1.3, -0.19);
    glScalef(1.4, 0.13, 1.8);
    glutSolidCube(1.0);
    glPopMatrix();

    glPopMatrix();
}

void drawVas() {
    glBegin(GL_QUADS);

    // Front face
    glColor3ub(255, 255, 0);
    glVertex3f(1.5, -1.7, -0.3);
    glVertex3f(2.0, -1.7, -0.3);
    glVertex3f(2.0, -0.9, -0.3);
    glVertex3f(1.5, -0.9, -0.3);

    // Back face
    glColor3ub(255, 240, 0);
    glVertex3f(1.5, -1.7, -0.8);
    glVertex3f(2.0, -1.7, -0.8);
    glVertex3f(2.0, -0.9, -0.8);
    glVertex3f(1.5, -0.9, -0.8);

    // Right face
    glColor3ub(255, 255, 0);
    glVertex3f(2.0, -1.7, -0.3);
    glVertex3f(2.0, -1.7, -0.8);
    glVertex3f(2.0, -0.9, -0.8);
    glVertex3f(2.0, -0.9, -0.3);

    // Left face
    glColor3ub(255, 240, 0);
    glVertex3f(1.5, -1.7, -0.3);
    glVertex3f(1.5, -1.7, -0.8);
    glVertex3f(1.5, -0.9, -0.8);
    glVertex3f(1.5, -0.9, -0.3);

    // Bottom face
    glColor3ub(255, 240, 0);
    glVertex3f(1.5, -1.7, -0.3);
    glVertex3f(2.0, -1.7, -0.3);
    glVertex3f(2.0, -1.7, -0.8);
    glVertex3f(1.5, -1.7, -0.8);

    glEnd();

}

void drawPencil(float x, float y, float z) {
    glPushMatrix();
    glColor3ub(255, 0, 127);
    glTranslatef(x, y, z);
    glScalef(0.05, 1.0, -0.03);
    glutSolidCube(1.0);
    glPopMatrix();
}

void drawPencil2(float x, float y, float z) {
    glPushMatrix();
    glColor3ub(0, 76, 153);
    glTranslatef(x, y, z);
    glScalef(0.05, 1.0, -0.03);
    glutSolidCube(1.0);
    glPopMatrix();
}

void drawPencil3(float x, float y, float z) {
    glPushMatrix();
    glColor3ub(192, 192, 192);
    glTranslatef(x, y, z);
    glScalef(0.05, 1.0, -0.03);
    glutSolidCube(1.0);
    glPopMatrix();
}

float angleX = 0.0;
float angleY = 0.0;
float translateZ = 0.0;


void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 0.1, 100.0);

}

GLfloat cameraX = 2.0;
GLfloat cameraY = 2.0;
GLfloat cameraZ = 5.0;

void specialKeys(int key, int x, int y) {
    const double moveSpeed = 0.1;

    switch (key) {
    case GLUT_KEY_UP:
        cameraZ -= moveSpeed;
        break;
    case GLUT_KEY_DOWN:
        cameraZ += moveSpeed;
        break;
    case GLUT_KEY_LEFT:
        cameraX -= moveSpeed;
        break;
    case GLUT_KEY_RIGHT:
        cameraX += moveSpeed;
        break;
    }

    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        angleY += 5.0;
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        angleY -= 5.0;
    }
    glutPostRedisplay();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glClearColor(255.0 / 255.0, 229.0 / 255.0, 153.0 / 204.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(cameraX, cameraY, cameraZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // Rotate only the sphere
    glPushMatrix();
    glTranslatef(0.0, 0.0, translateZ);
    glRotatef(angleX, 1.0, 0.0, 0.0);
    glRotatef(angleY, 0.0, 1.0, 0.0);
    drawSphere();
    glPopMatrix();

    drawCube();
    drawWoodenStick();
    drawWoodenStick2();
    drawTable();
    drawTableLeg(-2.8, -3.2, 1.4);
    drawTableLeg(2.8, -3.2, 1.4);
    drawTableLeg(-2.8, -3.2, -1.4);
    drawTableLeg(2.8, -3.2, -1.4);
    drawBook();
    drawVas();
    drawPencil(1.8, -1.0, -0.6);
    drawPencil(1.55, -1.0, -0.5);
    drawPencil(1.7, -1.0, -0.6);
    drawPencil(1.65, -1.0, -0.4);
    drawPencil2(1.65, -1.0, -0.4);
    drawPencil2(1.7, -1.0, -0.6);
    drawPencil2(1.85, -1.0, -0.5);
    drawPencil3(1.75, -1.0, -0.55);

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("My Desk");

    glEnable(GL_DEPTH_TEST);

    loadTexture("pictures/terra.bmp");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);
    glutMouseFunc(mouse);

    glutMainLoop();

    return 0;
}