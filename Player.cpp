#include "Player.h"
#include <string>


Player::Player(std::string& nombre, int puntaje, int puntajeTemp){
	this->playerName = nombre;
	this->puntaje = puntaje;
	this->puntajeTemp = puntajeTemp;
}

std::string Player::getNombre(){
    return playerName;
}

void Player::setPuntaje(int newPuntaje) {
    puntaje = newPuntaje;
}
void Player::setPuntajeTemp(int newPuntaje) {
    puntajeTemp = newPuntaje;
}
int Player::getPuntuacion(){
	return puntaje;
}
int Player::getPuntuacionTemp(){
	return puntajeTemp;
}

