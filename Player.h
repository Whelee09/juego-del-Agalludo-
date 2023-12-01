#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
public:
    Player(std::string& nombre,int puntaje, int puntajeTemp);
    std::string getNombre();
    int getPuntuacion();
    void setPuntaje(int puntaje);
    int getPuntuacionTemp();
    void setPuntajeTemp(int puntaje);
private:
    std::string playerName;
    int puntaje, puntajeTemp;
};

#endif
