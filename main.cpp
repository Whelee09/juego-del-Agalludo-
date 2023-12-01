#include <iostream>
#include <string>
#include <ctime>
#include "Player.h"

using namespace std;

int tirarDado();
void jugar(int num, Player** players);

int main(int argc, char** argv) {
    int numPlayers;
    do{
    	cout << "Ingrese el número de jugadores" << std::endl;
    	cin >> numPlayers;
	}while(numPlayers<2);
    

    Player** players = new Player*[numPlayers];  // Crear un arreglo dinámico de punteros a Player

    for (int i = 0; i < numPlayers; i++) {
        string playerName;
        cout << "Ingrese el nombre del jugador " << i + 1 << std::endl;
        cin >> playerName;

        players[i] = new Player(playerName, 0, 0);
    }
    bool timeToFinish = false;
    
	do{
		for (int i = 0; i < numPlayers; i++){
			players[i]->setPuntajeTemp(0);
			jugar(i, players);
			if(players[i]->getPuntuacion()>=10){
				timeToFinish = true;
				cout<<players[i]->getNombre()<< "	Ha ganado, presione cualquier tecla para cerrar el programa"<<endl;
				system("pause");
				break;
			}	
    	}
	}while(!timeToFinish);
	
    
    // Liberar la memoria
    for (int i = 0; i < numPlayers; i++) {
        delete players[i];
    }
    //delete[] players;

    return 0;
}

void jugar(int i, Player** players){
	int opcion = 0, puntosRonda;
	system("cls");
	cout<<"\nEs el turno de "<<players[i]->getNombre()<<endl;
	cout<<"Tu puntaje general es de: "<<players[i]->getPuntuacion()<<endl;
	cout<<"Tu puntaje acomulado de ronda es de: "<<players[i]->getPuntuacionTemp()<<endl;
	cout<<"\n\nPresiona cualquier tecla para lanzar el dado"<<endl;
	system("pause");
	puntosRonda = tirarDado();
	cout<<"Has sacado un: "<< puntosRonda<<endl;
	if(puntosRonda == 1 || puntosRonda==6){
		players[i]->setPuntajeTemp(0);
		cout<<"perdiste, pulsa culquier tecla para continuar"<<endl;
		system("pause");
	}else{
		players[i]->setPuntajeTemp(puntosRonda + players[i]->getPuntuacionTemp());
		cout<<"\nQue accion deseas hacer?,\n presiona 1 para volver a tirar o 2 para parar"<<endl;
		cin>>opcion;
		if(opcion == 1){
			jugar(i, players);	
		}else{
			players[i]->setPuntaje(players[i]->getPuntuacionTemp() + players[i]->getPuntuacion());
		}
	}
	
}


int tirarDado(){
    srand(time(NULL));//permite generar numeros diferentes
   	int aleatorio, DESDE=1, HASTA=6;
   	aleatorio = rand()%(HASTA-DESDE+1)+DESDE;
   	return aleatorio;        
}




