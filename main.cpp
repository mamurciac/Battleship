#include<iostream>
#include<iomanip>
#include<cmath>
#include<math.h>
#include<windows.h>
#include<stdlib.h>
#include<chrono>
#include<random>

using namespace std;

/**
auto semilla = chrono::system_clock::now().time_since_epoch().count();
default_random_engine generador(semilla);
uniform_int_distribution<int> Distribucion(0, 99);
uniform_int_distribution<int> Distribucion1(0, 1);

void Inicializar(int T[][10]);
void Barcos(int T[][10]);
void Imprimir(int T[][10]);
void Adivinar(int T[][10],int m, int n);

int main(){
    HANDLE ColorConsola = GetStdHandle(STD_OUTPUT_HANDLE);
    int B1[2];
    int B2[3];
    int B3[4];
    int B4[5];
    int T[10][10];
    int n, m;

    Inicializar(T);
    Barcos(T);
    int turnos = 40;

    cout<<"Bienvenida a la batalla naval"<<endl;
    for(int k = 0; k < 40; k++){
        Imprimir(T);
        SetConsoleTextAttribute(ColorConsola, 15);
        cin >> m >> n;
        Adivinar(T, m, n);
        system("CLS");
    }
    return 0;
}
void Inicializar(int T[][10]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            T[i][j] = 0;
        }
    }
}

void Imprimir(int T[][10]){
    HANDLE ColorConsola=GetStdHandle(STD_OUTPUT_HANDLE);
    char A[11]="ABCDEFGHIJ";
    FlushConsoleInputBuffer(ColorConsola);
    SetConsoleTextAttribute(ColorConsola,31);
    cout<<" / 0 1 2 3 4 5 6 7 8 9";
    SetConsoleTextAttribute(ColorConsola,0);
    cout<<" "<<endl;
    for(int i=0;i<10;i++){
        SetConsoleTextAttribute(ColorConsola,31);
        cout<<A[i]<<" ";
        for(int j=0;j<10;j++){
            if(T[i][j]==0 || T[i][j]==2 || T[i][j]==3 || T[i][j]==4 || T[i][j]==5){
                    if((i+j)%2==0)
                        SetConsoleTextAttribute(ColorConsola,11*16+11);
                    else
                        SetConsoleTextAttribute(ColorConsola,51);
                    cout<<" A";
            }
            else{
                SetConsoleTextAttribute(ColorConsola,15);
                cout<<" "<<T[i][j]-10;
            }
        }
        SetConsoleTextAttribute(ColorConsola,0);
        cout<<"A"<<endl;
    }
    SetConsoleTextAttribute(ColorConsola,0);
}
void Barcos(int T[][10]){
    int k[4];
    int i[4];
    int j[4];
    int b[4];
    int aux;
    for(int s = 0; s < 4; s++){
        k[s] = Distribucion(generador);
        b[s] = Distribucion1(generador);
    }
    for(int l = 0; l < 4; l++){
        if(b[l] == 1){
            for(int s = 0; s <= l + 1; s++){
                aux = (k[l] + s) % 100;
                j[l] = aux % 10;
                i[l] = (aux - j[l]) / 10;
                T[i[l]][j[l]] = l + 2;
            }
        }else{
            for(int s = 0; s <= l + 1; s++){
                aux = (k[l] + 10 * s) % 100;
                j[l] = aux % 10;
                i[l] = (aux - j[l]) / 10;
                T[i[l]][j[l]] = l + 2;
            }
        }
    }
}

void Adivinar(int T[][10], int m, int n){
    if(T[m][n] == 2 || T[m][n] == 3 || T[m][n] == 4 || T[m][n] == 5){
        T[m][n] += 10;
    }
}
*/

char** initializeGameboard(int numberRows, int numberColumns, char emptySpace){
    char** gameBoard = new char*[numberRows];
    for(int row = 0; row < numberRows; row++){
        gameBoard[row] = new char[numberColumns];
    }

    for(int row = 0; row < numberRows; row++){
        for(int column = 0; column < numberColumns; column++){
            gameBoard[row][column] = emptySpace;
        }
    }
    return gameBoard;
}

void showGameboard(char** gameBoard, int numberRows, int numberColumns, int numberLeftSpaces, int numberAboveSpaces, bool allowGameboardLines){
    for(int space = 0; space < numberAboveSpaces; space++){
        cout << endl;
    }
    cout << "  ";
    for(int space = 0; space < numberLeftSpaces; space++){
        cout << " ";
    }
    for(int column = 0; column < numberColumns; column++){
        if(allowGameboardLines == true){
            cout << " " << setw(2) << column + 1 << " ";
        }else{
            cout << setw(2) << column + 1 << " ";
        }
    }
    cout << endl;

    if(allowGameboardLines == true){
        cout << "  ";
        for(int space = 0; space < numberLeftSpaces; space++){
            cout << " ";
        }
        for(int column = 0; column < numberColumns; column++){
            if(column == 0){
                cout << char(201) << char(205) << char(205) << char(205);
            }else if(column > 0 && column <= numberColumns - 1){
                cout << char(203) << char(205) << char(205) << char(205);
            }

            if(column == numberColumns - 1){
                cout << char(187) << endl;
            }
        }
    }

    for(int row = 0; row < numberRows; row++){
        for(int space = 0; space < numberLeftSpaces; space++){
            cout << " ";
        }
        cout << char(65 + row) << " ";
        if(allowGameboardLines == true){
            cout << char(186);
        }
        for(int column = 0; column < numberColumns; column++){
            if(allowGameboardLines == true){
                cout << " " << gameBoard[row][column] << " " << char(186);
            }else{
                cout << " " << gameBoard[row][column] << " ";
            }
        }
        cout << endl;

        if(row >= 0 && row < numberRows - 1 && allowGameboardLines == true){
            cout << "  ";
            for(int space = 0; space < numberLeftSpaces; space++){
                cout << " ";
            }
            for(int column = 0; column < numberColumns; column++){
                if(column == 0){
                    cout << char(204) << char(205) << char(205) << char(205);
                }else if(column > 0 && column <= numberColumns - 1){

                    cout << char(206) << char(205) << char(205) << char(205);
                }

                if(column == numberColumns - 1){
                    cout << char(185) << endl;
                }
            }
        }
    }

    if(allowGameboardLines == true){
        cout << "  ";
        for(int space = 0; space < numberLeftSpaces; space++){
            cout << " ";
        }
        for(int column = 0; column < numberColumns; column++){
            if(column == 0){
                cout << char(200) << char(205) << char(205) << char(205);
            }else if(column > 0 && column <= numberColumns - 1){
                cout << char(202) << char(205) << char(205) << char(205);
            }

            if(column == numberColumns - 1){
                cout << char(188) << endl;
            }
        }
    }
}

int main(){
    int numberRows = 11, numberColumns = 12, numberLeftSpaces = 3, numberAboveSpaces = 1;
    char emptySpace = ' ';
    bool allowGameboardLines = true;
    char** gameBoard = initializeGameboard(numberRows, numberColumns, emptySpace);
    showGameboard(gameBoard, numberRows, numberColumns, numberLeftSpaces, numberAboveSpaces, allowGameboardLines);
    return 0;
}
