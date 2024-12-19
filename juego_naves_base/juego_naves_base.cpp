#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
using namespace std;
#define ANCHO 20
#define ALTO 10
char mapa[ALTO][ANCHO];
int posX = ANCHO / 2, posY = ALTO - 2; // Posición inicial de la nave
vector<pair<int, int>> enemigos; // Lista de enemigos
void inicializarMapa() {
for (int i = 0; i < ALTO; i++) {
for (int j = 0; j < ANCHO; j++) {
if (i == 0 || i == ALTO - 1 || j == 0 || j == ANCHO - 1) {
mapa[i][j] = '#'; // Bordes del mapa
} else {
mapa[i][j] = ' ';
}
}
}
}
void dibujarMapa() {
mapa[posY][posX] = '>'; // Dibuja la nave
for (int i = 0; i < enemigos.size(); i++) {
mapa[enemigos[i].second][enemigos[i].first] = 'E'; // Dibuja enemigos
}
for (int i = 0; i < ALTO; i++) {
for (int j = 0; j < ANCHO; j++) {
cout << mapa[i][j];
}
cout << endl;
}
}
void moverNave(char tecla) {
mapa[posY][posX] = ' '; // Borra la nave en su posición actual
if (tecla == 'a' && posX > 1) posX--; // Mueve la nave a la izquierda
if (tecla == 'd' && posX < ANCHO - 2) posX++; // Mueve la nave a la derecha
}
void moverEnemigos() {
for (int i = 0; i < enemigos.size(); i++) {
mapa[enemigos[i].second][enemigos[i].first] = ' '; // Borra al enemigo
enemigos[i].second++; // Mueve al enemigo hacia abajo
if (enemigos[i].second == ALTO - 1) {
enemigos.erase(enemigos.begin() + i); // Elimina el enemigo si llega al final
i--;
}
}
}
void disparar() {
int posBalaY = posY - 1;
int posBalaX = posX;
while (posBalaY > 0) {
if (mapa[posBalaY][posBalaX] == 'E') {
mapa[posBalaY][posBalaX] = ' '; // Destruye al enemigo
for (int i = 0; i < enemigos.size(); i++) {
if (enemigos[i].first == posBalaX && enemigos[i].second == posBalaY) {
enemigos.erase(enemigos.begin() + i);
break;
}
}
return;
}
posBalaY--;
Sleep(50);
}
}
int main() {
char tecla;
inicializarMapa();
enemigos.push_back({5, 1}); // Agrega un enemigo al mapa
enemigos.push_back({10, 1}); // Agrega otro enemigo
while (true) {
system("cls"); // Limpia la pantalla
dibujarMapa();
if (_kbhit()) {
tecla = _getch();
if (tecla == 'a' || tecla == 'd') {
moverNave(tecla);
}
if (tecla == ' ') {
disparar();
}
}
moverEnemigos();
Sleep(100); // Controla la velocidad del juego
}
return 0;
}