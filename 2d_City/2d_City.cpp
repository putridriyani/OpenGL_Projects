#include <iostream>
#include "glut.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <math.h>

int busX = 100; // Posisi awal bus

void drawBus() {
    // Badan Bus
    glColor3ub(56, 51, 196);
    glBegin(GL_QUADS);
    glVertex2f(busX, 273);
    glVertex2f(busX + 140, 273);
    glVertex2f(busX + 140, 315);
    glVertex2f(busX, 315);
    glEnd();

    glColor3ub(56, 51, 196);
    glBegin(GL_QUADS);
    glVertex2f(busX, 273);
    glVertex2f(busX + 143, 273);
    glVertex2f(busX + 143, 294);
    glVertex2f(busX, 294);
    glEnd();

    // Ban Kiri
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    int num_segments = 100;
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x_offset = 10.0 * cosf(theta);
        float y_offset = 10.0 * sinf(theta);
        glVertex2f(busX + 30 + x_offset, 273 + y_offset);
    }
    glEnd();

    // Ban Kanan
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x_offset = 10.0 * cosf(theta);
        float y_offset = 10.0 * sinf(theta);
        glVertex2f(busX + 113 + x_offset, 273 + y_offset);
    }
    glEnd();

    // Jari-jari Ban Kiri
    glColor3ub(230, 230, 230);
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x_offset = 6.0 * cosf(theta);
        float y_offset = 6.0 * sinf(theta);
        glVertex2f(busX + 30 + x_offset, 273 + y_offset);
    }
    glEnd();

    // Jari-jari Ban Kanan
    glColor3ub(230, 230, 230);
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x_offset = 6.0 * cosf(theta);
        float y_offset = 6.0 * sinf(theta);
        glVertex2f(busX + 113 + x_offset, 273 + y_offset);
    }
    glEnd();

    // Kaca depan Bus
    glColor3ub(204, 255, 209);
    glBegin(GL_QUADS);
    glVertex2f(busX + 136, 294);
    glVertex2f(busX + 140, 294);
    glVertex2f(busX + 140, 311);
    glVertex2f(busX + 136, 311);
    glEnd();

    // Jendela Bus1
    glColor3ub(204, 255, 209);
    glBegin(GL_QUADS);
    glVertex2f(busX + 100, 294);
    glVertex2f(busX + 115, 294);
    glVertex2f(busX + 115, 311);
    glVertex2f(busX + 100, 311);
    glEnd();

    // Jendela Bus2
    glColor3ub(204, 255, 209);
    glBegin(GL_QUADS);
    glVertex2f(busX + 117, 294);
    glVertex2f(busX + 132, 294);
    glVertex2f(busX + 132, 311);
    glVertex2f(busX + 117, 311);
    glEnd();

    // Pintu Bus
    glColor3ub(204, 255, 209);
    glBegin(GL_QUADS);
    glVertex2f(busX + 83, 273);
    glVertex2f(busX + 98, 273);
    glVertex2f(busX + 98, 311);
    glVertex2f(busX + 83, 311); 
    glEnd();


    // Jendela Bus3
    glColor3ub(204, 255, 209);
    glBegin(GL_QUADS);
    glVertex2f(busX + 66, 294);
    glVertex2f(busX + 81, 294);
    glVertex2f(busX + 81, 311);
    glVertex2f(busX + 66, 311);
    glEnd();

    // Jendela Bus4
    glColor3ub(204, 255, 209);
    glBegin(GL_QUADS);
    glVertex2f(busX + 49, 294);
    glVertex2f(busX + 64, 294);
    glVertex2f(busX + 64, 311);
    glVertex2f(busX + 49, 311);
    glEnd();

    // Jendela Bus4
    glColor3ub(204, 255, 209);
    glBegin(GL_QUADS);
    glVertex2f(busX + 32, 294);
    glVertex2f(busX + 47, 294);
    glVertex2f(busX + 47, 311);
    glVertex2f(busX + 32, 311);
    glEnd();

    // Jendela Bus5
    glColor3ub(204, 255, 209);
    glBegin(GL_QUADS);
    glVertex2f(busX + 15, 294);
    glVertex2f(busX + 30, 294);
    glVertex2f(busX + 30, 311);
    glVertex2f(busX + 15, 311);
    glEnd();

    // Jendela Bus6
    glColor3ub(204, 255, 209);
    glBegin(GL_QUADS);
    glVertex2f(busX + 2, 294);
    glVertex2f(busX + 13, 294);
    glVertex2f(busX + 13, 311);
    glVertex2f(busX + 2, 311);
    glEnd();
}

float shipX = 100.0;
float shipY = 30.0;

void drawShip() {
    // Badan kapal1
    glColor3ub(250, 250, 250);
    glBegin(GL_QUADS);
    glVertex2f(shipX + 85, shipY + 15);
    glVertex2f(shipX + 225, shipY + 15);
    glVertex2f(shipX + 230, shipY + 40);
    glVertex2f(shipX + 65, shipY + 40);
    glEnd();

    // Badan kapal2
    glColor3ub(204, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(shipX + 100, shipY);
    glVertex2f(shipX + 220, shipY);
    glVertex2f(shipX + 225, shipY + 15);
    glVertex2f(shipX + 85, shipY + 15);
    glEnd();

    // Badan kapal3
    glColor3ub(204, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(shipX + 140, shipY + 40);
    glVertex2f(shipX + 220, shipY + 40);
    glVertex2f(shipX + 210, shipY + 65);
    glVertex2f(shipX + 140, shipY + 65);
    glEnd();

    // Badan kapal4
    glColor3ub(250, 250, 250);
    glBegin(GL_QUADS);
    glVertex2f(shipX + 170, shipY + 65);
    glVertex2f(shipX + 208, shipY + 65);
    glVertex2f(shipX + 208, shipY + 85);
    glVertex2f(shipX + 170, shipY + 85);
    glEnd();

    // Tiang
    glColor3ub(20, 20, 20);
    glBegin(GL_QUADS);
    glVertex2f(shipX + 188, shipY + 85);
    glVertex2f(shipX + 190, shipY + 85);
    glVertex2f(shipX + 190, shipY + 115);
    glVertex2f(shipX + 188, shipY + 115);
    glEnd();

    // Bendera
    glColor3ub(204, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(shipX + 150, shipY + 95);
    glVertex2f(shipX + 188, shipY + 95);
    glVertex2f(shipX + 188, shipY + 115);
    glEnd();

}

float planeX = 570.0;
float planeY = 520.0;

void drawPlane() {
    // Ekor Pesawat1
    glColor3ub(130, 130, 130);
    glBegin(GL_QUADS);
    glVertex2f(planeX + 140, planeY);
    glVertex2f(planeX + 155, planeY);
    glVertex2f(planeX + 140, planeY + 20);
    glVertex2f(planeX + 120, planeY + 20);
    glEnd();

    // Badan Pesawat1
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(planeX, planeY);
    glVertex2f(planeX + 130, planeY);
    glVertex2f(planeX + 145, planeY + 20);
    glVertex2f(planeX + 25, planeY + 20);
    glEnd();

    // Badan Pesawat2
    glColor3ub(153, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(planeX + 5, planeY - 15);
    glVertex2f(planeX + 115, planeY - 15);
    glVertex2f(planeX + 130, planeY);
    glVertex2f(planeX, planeY);
    glEnd();

    // Ekor Pesawat2
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(planeX + 120, planeY + 20);
    glVertex2f(planeX + 145, planeY + 20);
    glVertex2f(planeX + 155, planeY + 40);
    glVertex2f(planeX + 140, planeY + 40);
    glEnd();

    // Sayap Pesawat
    glColor3ub(120, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(planeX + 90, planeY - 25);
    glVertex2f(planeX + 110, planeY - 25);
    glVertex2f(planeX + 80, planeY);
    glVertex2f(planeX + 40, planeY);
    glEnd();

    // Jendela Pesawat
    glColor3ub(100, 100, 100);
    glBegin(GL_QUADS);
    glVertex2f(planeX + 3, planeY + 5);
    glVertex2f(planeX + 43, planeY + 5);
    glVertex2f(planeX + 45, planeY + 18);
    glVertex2f(planeX + 24.2, planeY + 18);
    glEnd();

    // Jendela Pesawat1
    glColor3ub(100, 100, 100);
    glBegin(GL_QUADS);
    glVertex2f(planeX + 50, planeY + 5);
    glVertex2f(planeX + 60, planeY + 5);
    glVertex2f(planeX + 60, planeY + 18);
    glVertex2f(planeX + 50, planeY + 18);
    glEnd();

    // Jendela Pesawat2
    glColor3ub(100, 100, 100);
    glBegin(GL_QUADS);
    glVertex2f(planeX + 65, planeY + 5);
    glVertex2f(planeX + 75, planeY + 5);
    glVertex2f(planeX + 75, planeY + 18);
    glVertex2f(planeX + 65, planeY + 18);
    glEnd();

    // Jendela Pesawat3
    glColor3ub(100, 100, 100);
    glBegin(GL_QUADS);
    glVertex2f(planeX + 80, planeY + 5);
    glVertex2f(planeX + 90, planeY + 5);
    glVertex2f(planeX + 90, planeY + 18);
    glVertex2f(planeX + 80, planeY + 18);
    glEnd();

    // Jendela Pesawat4
    glColor3ub(100, 100, 100);
    glBegin(GL_QUADS);
    glVertex2f(planeX + 95, planeY + 5);
    glVertex2f(planeX + 105, planeY + 5);
    glVertex2f(planeX + 105, planeY + 18);
    glVertex2f(planeX + 95, planeY + 18);
    glEnd();

}

void drawCloud(float x, float y) {
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    float radius = 20.0;
    int num_segments = 100;
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x_offset = 20.0 * cosf(theta);
        float y_offset = 10.0 * sinf(theta);
        glVertex2f(x + x_offset, y + y_offset);
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    radius = 30.0;
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x_offset = 30.0 * cosf(theta);
        float y_offset = 15.0 * sinf(theta);
        glVertex2f(x + 40.0 + x_offset, y + y_offset);
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    radius = 20.0;
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x_offset = 20.0 * cosf(theta);
        float y_offset = 10.0 * sinf(theta);
        glVertex2f(x + 80.0 + x_offset, y + y_offset);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Langit 
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 147);
    glVertex2f(0, 300);
    glVertex2f(800, 300);
    glColor3ub(102, 204, 255);
    glVertex2f(800, 600);
    glVertex2f(0, 600);
    glEnd();

    // Matahari
    glBegin(GL_POLYGON);
    glColor3ub(253, 183, 77);
    float radius = 30.0;
    int num_segments = 100;
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(x + 600, y + 550);
    }
    glEnd();

    drawCloud(100, 550);
    drawCloud(400, 550);

    drawPlane();

    // Rumput1
    glBegin(GL_QUADS);
    glColor3ub(90, 147, 48);
    glVertex2f(0, 300);
    glVertex2f(800, 300);
    glColor3ub(100, 190, 70);
    glVertex2f(800, 340);
    glVertex2f(0, 340);
    glEnd();

    // Rumput2
    glBegin(GL_QUADS);
    glColor3ub(90, 147, 48);
    glVertex2f(0, 130);
    glVertex2f(800, 130);
    glColor3ub(100, 190, 70);
    glVertex2f(800, 199);
    glVertex2f(0, 199);
    glEnd();

    // Rumput3
    glBegin(GL_QUADS);
    glColor3ub(70, 139, 34);
    glVertex2f(0, 130);
    glVertex2f(800, 130);
    glVertex2f(800, 145);
    glVertex2f(0, 145);
    glEnd();


    // Bangunan2
    glBegin(GL_QUADS);
    glColor3ub(90, 90, 90);
    glVertex2f(445, 325);
    glVertex2f(540, 325);
    glVertex2f(540, 510);
    glVertex2f(445, 510);
    glEnd();

    // Atap Bangunan2
    glBegin(GL_QUADS);
    glColor3ub(100, 100, 100);
    glVertex2f(442, 510);
    glVertex2f(543, 510);
    glVertex2f(543, 520);
    glVertex2f(442, 520);
    glEnd();

    // Jendela bangunan2 1
    glBegin(GL_QUADS);
    glColor3ub(135, 206, 250);
    glVertex2f(455, 335);
    glVertex2f(470, 335);
    glVertex2f(470, 395);
    glVertex2f(455, 395);
    glEnd();

    // Jendela bangunan2 2
    glBegin(GL_QUADS);
    glColor3ub(135, 206, 250);
    glVertex2f(475, 335);
    glVertex2f(490, 335);
    glVertex2f(490, 395);
    glVertex2f(475, 395);
    glEnd();

    // Jendela bangunan2 3
    glBegin(GL_QUADS);
    glColor3ub(135, 206, 250);
    glVertex2f(495, 335);
    glVertex2f(510, 335);
    glVertex2f(510, 395);
    glVertex2f(495, 395);
    glEnd();

    // Jendela bangunan2 4
    glBegin(GL_QUADS);
    glColor3ub(135, 206, 250);
    glVertex2f(515, 335);
    glVertex2f(530, 335);
    glVertex2f(530, 395);
    glVertex2f(515, 395);
    glEnd();

    // Jendela bangunan2 5
    glBegin(GL_QUADS);
    glColor3ub(135, 206, 250);
    glVertex2f(515, 400);
    glVertex2f(530, 400);
    glVertex2f(530, 460);
    glVertex2f(515, 460);
    glEnd();

    // Jendela bangunan2 6
    glBegin(GL_QUADS);
    glColor3ub(135, 206, 250);
    glVertex2f(495, 400);
    glVertex2f(510, 400);
    glVertex2f(510, 460);
    glVertex2f(495, 460);
    glEnd();

    // Jendela bangunan2 7
    glBegin(GL_QUADS);
    glColor3ub(135, 206, 250);
    glVertex2f(475, 400);
    glVertex2f(490, 400);
    glVertex2f(490, 460);
    glVertex2f(475, 460);
    glEnd();

    // Jendela bangunan2 8
    glBegin(GL_QUADS);
    glColor3ub(135, 206, 250);
    glVertex2f(455, 400);
    glVertex2f(470, 400);
    glVertex2f(470, 460);
    glVertex2f(455, 460);
    glEnd();

    // Jendela bangunan2 9
    glBegin(GL_QUADS);
    glColor3ub(135, 206, 250);
    glVertex2f(455, 465);
    glVertex2f(530, 465);
    glVertex2f(530, 498);
    glVertex2f(455, 498);
    glEnd();

    // Bangunan3
    glBegin(GL_QUADS);
    glColor3ub(255, 195, 28);
    glVertex2f(150, 325);
    glVertex2f(250, 325);
    glVertex2f(250, 510);
    glVertex2f(150, 510);
    glEnd();

    // Atap bangunan3
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(147, 510);
    glVertex2f(253, 510);
    glVertex2f(253, 520);
    glVertex2f(147, 520);
    glEnd();

    // Pintu bangunan3
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(180, 325);
    glVertex2f(220, 325);
    glVertex2f(220, 375);
    glVertex2f(180, 375);
    glEnd();

    // Garis bangunan3 1
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(150, 380);
    glVertex2f(250, 380);
    glVertex2f(250, 385);
    glVertex2f(150, 385);
    glEnd();

    // Garis bangunan3 2
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(150, 430);
    glVertex2f(250, 430);
    glVertex2f(250, 435);
    glVertex2f(150, 435);
    glEnd();

    // Garis bangunan3 3
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(150, 480);
    glVertex2f(250, 480);
    glVertex2f(250, 485);
    glVertex2f(150, 485);
    glEnd();


    // Bangunan6
    glBegin(GL_QUADS);
    glColor3ub(45, 45, 120);
    glVertex2f(730, 325);
    glVertex2f(800, 325);
    glVertex2f(800, 550);
    glVertex2f(730, 550);
    glEnd();

    // Atap bangunan6
    glBegin(GL_QUADS);
    glColor3ub(45, 45, 120);
    glVertex2f(727, 550);
    glVertex2f(800, 550);
    glVertex2f(800, 560);
    glVertex2f(727, 560);
    glEnd();

    // Jendela bangunan6 1
    glBegin(GL_QUADS);
    glColor3ub(153, 204, 255);
    glVertex2f(755, 335);
    glVertex2f(800, 335);
    glVertex2f(800, 355);
    glVertex2f(755, 355);
    glEnd();

    // Jendela bangunan6 2
    glBegin(GL_QUADS);
    glColor3ub(153, 204, 255);
    glVertex2f(755, 365);
    glVertex2f(800, 365);
    glVertex2f(800, 385);
    glVertex2f(755, 385);
    glEnd();

    // Jendela bangunan6 3
    glBegin(GL_QUADS);
    glColor3ub(153, 204, 255);
    glVertex2f(755, 395);
    glVertex2f(800, 395);
    glVertex2f(800, 415);
    glVertex2f(755, 415);
    glEnd();

    // Jendela bangunan6 4
    glBegin(GL_QUADS);
    glColor3ub(153, 204, 255);
    glVertex2f(755, 425);
    glVertex2f(800, 425);
    glVertex2f(800, 445);
    glVertex2f(755, 445);
    glEnd();

    // Jendela bangunan6 5
    glBegin(GL_QUADS);
    glColor3ub(153, 204, 255);
    glVertex2f(755, 455);
    glVertex2f(800, 455);
    glVertex2f(800, 475);
    glVertex2f(755, 475);
    glEnd();

    // Jendela bangunan6 6
    glBegin(GL_QUADS);
    glColor3ub(153, 204, 255);
    glVertex2f(755, 485);
    glVertex2f(800, 485);
    glVertex2f(800, 505);
    glVertex2f(755, 505);
    glEnd();

    // Jendela bangunan6 7
    glBegin(GL_QUADS);
    glColor3ub(153, 204, 255);
    glVertex2f(755, 515);
    glVertex2f(800, 515);
    glVertex2f(800, 535);
    glVertex2f(755, 535);
    glEnd();

    // Jangunan4
    glBegin(GL_QUADS);
    glColor3ub(139, 40, 0);
    glVertex2f(560, 320);
    glVertex2f(740, 320);
    glVertex2f(740, 450);
    glVertex2f(560, 450);
    glEnd();

    // Atap bangunan4
    glBegin(GL_QUADS);
    glColor3ub(139, 40, 0);
    glVertex2f(557, 450);
    glVertex2f(743, 450);
    glVertex2f(743, 465);
    glVertex2f(557, 465);
    glEnd();

    // Jendela bangunan4 1
    glBegin(GL_QUADS);
    glColor3ub(255, 195, 28);
    glVertex2f(590, 330);
    glVertex2f(730, 330);
    glVertex2f(730, 350);
    glVertex2f(590, 350);
    glEnd();

    // Jendela bangunan4 2
    glBegin(GL_QUADS);
    glColor3ub(255, 195, 28);
    glVertex2f(590, 360);
    glVertex2f(730, 360);
    glVertex2f(730, 380);
    glVertex2f(590, 380);
    glEnd();

    // Jendela bangunan4 3
    glBegin(GL_QUADS);
    glColor3ub(255, 195, 28);
    glVertex2f(590, 390);
    glVertex2f(730, 390);
    glVertex2f(730, 410);
    glVertex2f(590, 410);
    glEnd();

    // Jendela bangunan4 4
    glBegin(GL_QUADS);
    glColor3ub(255, 195, 28);
    glVertex2f(590, 420);
    glVertex2f(730, 420);
    glVertex2f(730, 440);
    glVertex2f(590, 440);
    glEnd();

    // Bangunan1
    glBegin(GL_QUADS);
    glColor3ub(103, 102, 128);
    glVertex2f(230, 320);
    glVertex2f(450, 320);
    glVertex2f(450, 425);
    glVertex2f(230, 425);
    glEnd();

    // Atap bangunan1
    glBegin(GL_QUADS);
    glColor3ub(50, 50, 50);
    glVertex2f(230, 425);
    glVertex2f(450, 425);
    glVertex2f(440, 475);
    glVertex2f(240, 475);
    glEnd();

    // Bangunan1 tengah
    glBegin(GL_QUADS);
    glColor3ub(192, 192, 192);
    glVertex2f(300, 320);
    glVertex2f(380, 320);
    glVertex2f(380, 425);
    glVertex2f(300, 425);
    glEnd();

    // Atap bangunan1 tengah 
    glBegin(GL_TRIANGLES);
    glColor3ub(100, 100, 100);
    glVertex2f(300, 425);
    glVertex2f(340, 480);
    glVertex2f(380, 425);
    glEnd();

    // Pintu bangunan1 tengah
    glBegin(GL_QUADS);
    glColor3ub(51, 25, 0);
    glVertex2f(310, 320);
    glVertex2f(370, 320);
    glVertex2f(370, 365);
    glVertex2f(310, 365);
    glEnd();

    // Jendela bangunan1 1
    glBegin(GL_QUADS);
    glColor3ub(220, 220, 255);
    glVertex2f(310, 375);
    glVertex2f(335, 375);
    glVertex2f(335, 415);
    glVertex2f(310, 415);
    glEnd();

    // Jendela bangunan1 2
    glBegin(GL_QUADS);
    glColor3ub(220, 220, 255);
    glVertex2f(345, 375);
    glVertex2f(370, 375);
    glVertex2f(370, 415);
    glVertex2f(345, 415);
    glEnd();

    // Jendela bangunan1 3
    glBegin(GL_QUADS);
    glColor3ub(220, 220, 255);
    glVertex2f(240, 375);
    glVertex2f(260, 375);
    glVertex2f(260, 415);
    glVertex2f(240, 415);
    glEnd();

    // GJendela bangunan1 4
    glBegin(GL_QUADS);
    glColor3ub(220, 220, 255);
    glVertex2f(270, 375);
    glVertex2f(290, 375);
    glVertex2f(290, 415);
    glVertex2f(270, 415);
    glEnd();

    // Jendela bangunan1 5
    glBegin(GL_QUADS);
    glColor3ub(220, 220, 255);
    glVertex2f(240, 325);
    glVertex2f(260, 325);
    glVertex2f(260, 365);
    glVertex2f(240, 365);
    glEnd();

    // Jendela bangunan1 6
    glBegin(GL_QUADS);
    glColor3ub(220, 220, 255);
    glVertex2f(270, 325);
    glVertex2f(290, 325);
    glVertex2f(290, 365);
    glVertex2f(270, 365);
    glEnd();

    // Jendela bangunan1 7
    glBegin(GL_QUADS);
    glColor3ub(220, 220, 255);
    glVertex2f(420, 375);
    glVertex2f(440, 375);
    glVertex2f(440, 415);
    glVertex2f(420, 415);
    glEnd();
    
    // Jendela bangunan1 8
    glBegin(GL_QUADS);
    glColor3ub(220, 220, 255);
    glVertex2f(390, 375);
    glVertex2f(410, 375);
    glVertex2f(410, 415);
    glVertex2f(390, 415);
    glEnd();

    // Jendela bangunan1 9
    glBegin(GL_QUADS);
    glColor3ub(220, 220, 255);
    glVertex2f(390, 325);
    glVertex2f(410, 325);
    glVertex2f(410, 365);
    glVertex2f(390, 365);
    glEnd();

    // Jendela bangunan1 10
    glBegin(GL_QUADS);
    glColor3ub(220, 220, 255);
    glVertex2f(420, 325);
    glVertex2f(440, 325);
    glVertex2f(440, 365);
    glVertex2f(420, 365);
    glEnd();


    // Bangunan5
    glBegin(GL_QUADS);
    glColor3ub(225, 220, 119);
    glVertex2f(20, 320);
    glVertex2f(145, 320);
    glVertex2f(145, 460);
    glVertex2f(20, 460);
    glEnd();

    // Atap bangunan5
    glBegin(GL_TRIANGLES);
    glColor3ub(30, 30, 0);
    glVertex2f(20, 460);
    glVertex2f(82.5, 520);
    glVertex2f(145, 460);
    glEnd();

    // Pintu bangunan5
    glBegin(GL_QUADS);
    glColor3ub(30, 30, 0);
    glVertex2f(65, 320);
    glVertex2f(100, 320);
    glVertex2f(100, 375);
    glVertex2f(65, 375);
    glEnd();

    // Jendela bangunan5 1
    glBegin(GL_QUADS);
    glColor3ub(30, 30, 0);
    glVertex2f(47.5, 390);
    glVertex2f(77.5, 390);
    glVertex2f(77.5, 415);
    glVertex2f(47.5, 415);
    glEnd();

    // Jendela bangunan5 2
    glBegin(GL_QUADS);
    glColor3ub(30, 30, 0);
    glVertex2f(87.5, 390);
    glVertex2f(117.5, 390);
    glVertex2f(117.5, 415);
    glVertex2f(87.5, 415);
    glEnd();

    // Jendela bangunan5 3
    glBegin(GL_QUADS);
    glColor3ub(30, 30, 0);
    glVertex2f(47.5, 425);
    glVertex2f(77.5, 425);
    glVertex2f(77.5, 450);
    glVertex2f(47.5, 450);
    glEnd();

    // Jendela bangunan5 4
    glBegin(GL_QUADS);
    glColor3ub(30, 30, 0);
    glVertex2f(87.5, 425);
    glVertex2f(117.5, 425);
    glVertex2f(117.5, 450);
    glVertex2f(87.5, 450);
    glEnd();

    // Tanah atas sungai
    glBegin(GL_QUADS);
    glColor3ub(150, 69, 19);
    glVertex2f(0, 130);
    glVertex2f(800, 130);
    glVertex2f(800, 110);
    glVertex2f(0, 110);
    glEnd();

    // Sungai
    glBegin(GL_QUADS);
    glColor3ub(135, 206, 250);
    glVertex2f(0, 110);
    glVertex2f(800, 110);
    glColor3ub(0, 191, 255);
    glVertex2f(800, 0);
    glVertex2f(0, 0);
    glEnd();

    // Jalan
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
    glVertex2f(0, 200);
    glVertex2f(800, 200);
    glVertex2f(800, 300);
    glVertex2f(0, 300);
    glEnd();

    glBegin(GL_LINES);// Top bar
    glLineWidth(2);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(0, 301);
    glVertex2i(800, 301);
    glEnd();

    glBegin(GL_LINES);// Middle bar
    glLineWidth(2);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(0, 254);
    glVertex2i(800, 254);
    glEnd();

    glBegin(GL_LINES);// Bottom bar
    glLineWidth(2);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(0, 199);
    glVertex2i(800, 199);
    glEnd();

    // POHON 1
    glBegin(GL_QUADS);
    glColor3ub(75, 35, 5);
    glVertex2f(100, 160);
    glVertex2f(113, 160);
    glVertex2f(113, 185);
    glVertex2f(100, 185);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);
    glVertex2f(83, 185);
    glVertex2f(107, 250);
    glVertex2f(128, 185);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);
    glVertex2f(83, 200);
    glVertex2f(107, 250);
    glVertex2f(128, 200);
    glEnd();

    // POHON 2
    glBegin(GL_QUADS);
    glColor3ub(75, 35, 5);
    glVertex2f(250, 160);
    glVertex2f(263, 160);
    glVertex2f(263, 185);
    glVertex2f(250, 185);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);
    glVertex2f(233, 185);
    glVertex2f(257, 250);
    glVertex2f(278, 185);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);
    glVertex2f(233, 200);
    glVertex2f(257, 250);
    glVertex2f(278, 200);
    glEnd();

    // POHON 3
    glBegin(GL_QUADS);
    glColor3ub(75, 35, 5);
    glVertex2f(400, 160);
    glVertex2f(413, 160);
    glVertex2f(413, 185);
    glVertex2f(400, 185);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);
    glVertex2f(383, 185);
    glVertex2f(407, 250);
    glVertex2f(428, 185);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);
    glVertex2f(383, 200);
    glVertex2f(407, 250);
    glVertex2f(428, 200);
    glEnd();

    // POHON 4
    glBegin(GL_QUADS);
    glColor3ub(75, 35, 5);
    glVertex2f(550, 160);
    glVertex2f(563, 160);
    glVertex2f(563, 185);
    glVertex2f(550, 185);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);
    glVertex2f(533, 185);
    glVertex2f(557, 250);
    glVertex2f(578, 185);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);
    glVertex2f(533, 200);
    glVertex2f(557, 250);
    glVertex2f(578, 200);
    glEnd();

    // POHON 5
    glBegin(GL_QUADS);
    glColor3ub(75, 35, 5);
    glVertex2f(700, 160);
    glVertex2f(713, 160);
    glVertex2f(713, 185);
    glVertex2f(700, 185);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);
    glVertex2f(683, 185);
    glVertex2f(707, 250);
    glVertex2f(728, 185);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);
    glVertex2f(683, 200);
    glVertex2f(707, 250);
    glVertex2f(728, 200);
    glEnd();


    // POHON 6
    glBegin(GL_QUADS);
    glColor3ub(75, 35, 5);
    glVertex2f(540, 315);
    glVertex2f(553, 315);
    glVertex2f(553, 340);
    glVertex2f(540, 340);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);
    glVertex2f(523, 340);
    glVertex2f(547, 405);
    glVertex2f(568, 340);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);
    glVertex2f(523, 355);
    glVertex2f(547, 405);
    glVertex2f(568, 355);
    glEnd();


    // POHON 7
    glBegin(GL_QUADS);
    glColor3ub(75, 35, 5);
    glVertex2f(790, 315);
    glVertex2f(803, 315);
    glVertex2f(803, 340);
    glVertex2f(790, 340);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);
    glVertex2f(773, 340);
    glVertex2f(797, 405);
    glVertex2f(818, 340);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);
    glVertex2f(773, 355);
    glVertex2f(797, 405);
    glVertex2f(818, 355);
    glEnd();
    
    // POHON 8
    glBegin(GL_QUADS);
    glColor3ub(75, 35, 5);
    glVertex2f(140, 315);
    glVertex2f(153, 315);
    glVertex2f(153, 340);
    glVertex2f(140, 340);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);
    glVertex2f(123, 340);
    glVertex2f(147, 405);
    glVertex2f(168, 340);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);
    glVertex2f(123, 355);
    glVertex2f(147, 405);
    glVertex2f(168, 355);
    glEnd();

    // POHON 9
    glBegin(GL_QUADS);
    glColor3ub(75, 35, 5);
    glVertex2f(5, 315);
    glVertex2f(18, 315);
    glVertex2f(18, 340);
    glVertex2f(5, 340);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);
    glVertex2f(-12, 340);
    glVertex2f(12, 405);
    glVertex2f(33, 340);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);
    glVertex2f(-12, 355);
    glVertex2f(12, 405);
    glVertex2f(33, 355);
    glEnd();

    drawBus();
    drawShip();

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glMatrixMode(GL_MODELVIEW);
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        busX -= 20;
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        busX += 20;
    }
    glutPostRedisplay(); 
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'a':
    case 'A':
        shipX -= 10;
        break;
    case 'd':
    case 'D':
        shipX += 10;
        break;
    case 'w':
    case 'W':
        shipY += 10;
        break;
    case 's':
    case 'S':
        shipY -= 10;
        break;
    }

    glutPostRedisplay(); 
}

void specialKeys(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT:
        planeX -= 10;
        break;
    case GLUT_KEY_RIGHT:
        planeX += 10;
        break;
    case GLUT_KEY_UP:
        planeY += 10;
        break;
    case GLUT_KEY_DOWN:
        planeY -= 10;
        break;
    }
    glutPostRedisplay(); 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Town of Marley");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMouseFunc(mouse); // Menghubungkan fungsi mouse callback
    glutKeyboardFunc(keyboard); // Menghubungkan fungsi keyboard callback
    glutSpecialFunc(specialKeys); // Menghubungkan fungsi special key callback

    glutMainLoop();

    return 0;
}
