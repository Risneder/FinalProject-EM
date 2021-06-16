#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>

using namespace std;

int random(int min, int max) {
    return min + rand() % (max - min + 1);
}

class Engine
{
private:
    int size = 52;
    int iteration = 15;
    int grass = 1, rabbit = 0, wolf = 0;
    string a = " ";
    vector <vector<int> > row;

    void startMessage(int numberMessage) {
        if (numberMessage == 1) {//Стартовове
            cout << "Gama \"Life\"" << endl;

            cout << "# - Трава" << endl;
            cout << "& - Заец" << endl;
            cout << "@ - Волк" << endl;
        }
        else if (numberMessage == 2) {
            cout << "Введи количество итераций: ";
            cin >> iteration;
            cout << endl;
        }
    }

    void creationGameField() {
//Генерация вектора
        for (int i = 0; i < size; i++)
        {
            vector<int> col;
            for (int j = 0; j < size; j++)
            {
                col.push_back(0);
            }
            row.push_back(col);
        }
// Генерация бортов поля
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                row[0][j] = 4;
                row[size - 1][j] = 4;
                row[i][0] = 4;
                row[i][size - 1] = 4;
            }
        }

        grass += 3;
    }
   
    void print() {
        // 0 - " "
        // 1 - #
        // 2 - &
        // 3 - @
        // 4 - поле "*"
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (row[i][j] == 0) {
                    cout << " ";
                }
                else if (row[i][j] == 1) {
                    cout << "#";
                }
                else if (row[i][j] == 2) {
                    cout << "&";
                }
                else if (row[i][j] == 3) {
                    cout << "@";
                }
                else if (row[i][j] == 4) {
                    cout << "*";
                }
                cout << " ";
            }
            cout << endl;
        }
    }

public:
    void startGame() {
        startMessage(1);
        startMessage(2);
        creationGameField();
        print();

        system("cls");
        gameLogic();
    }
    void gameLogic() {

        for (int i = 0; i < iteration; i++) {
            grass += 3 + grass / 2; //вычисление травы

            if (grass >= 5) { // если травы больще 5 , спавн зайца по формуле
                rabbit += grass / 5;
            }

            grass -= rabbit; // зайец съедает траву

            if (grass < rabbit) { // если зайцев больше чем травы , то от зайцев отнимаем разницу 
                int a;
                a = rabbit - grass;
                rabbit -= a;
            }

            if (rabbit >= 5) {//зайцев больше 5, спавн волка
                wolf += rabbit / 5;
            }

            rabbit -= wolf; // волк съедает зайца

            if (rabbit < wolf) { //если волков больше зайцев , то от волков отнимаем разницу
                int a;
                a = wolf - rabbit;
                wolf -= a;
            }

            if (grass < 0) { //проверка , чтоб в случае отрицательного кол-ва объектов их удалять с массива
                //очистка
                for (int j = 0; j < abs(grass); j++) {
                    int a = random(1, 51);
                    int b = random(1, 51);
                    if (row[a][b] == 1) {
                        row[a][b] = 0;
                    }
                    else {
                        j--;
                    }
                }
            }
            else if (rabbit < 0) {
                for (int j = 0; j < abs(rabbit); j++) {
                    int a = random(1, 51);
                    int b = random(1, 51);
                    if (row[a][b] == 2) {
                        row[a][b] = 0;
                    }
                    else {
                        j--;
                    }
                }
            }
            else if (wolf < 0) {
                for (int j = 0; j < abs(wolf); j++) {
                    int a = random(1, 51);
                    int b = random(1, 51);
                    if (row[a][b] == 3) {
                        row[a][b] = 0;
                    }
                    else {
                        j--;
                    }
                }
            }

            for (int j = 0; j < grass; j++) {
                int a = random(1, 51);
                int b = random(1, 51);
                if (row[a][b] == 0) {
                    row[a][b] = 1;
                }
                else {
                    j--;
                }
            }

            for (int j = 0; j < rabbit; j++) {
                int a = random(1, 51);
                int b = random(1, 51);
                if (row[a][b] == 0) {
                    row[a][b] = 2;
                }
                else {
                    j--;
                }
            }

            for (int j = 0; j < wolf; j++) {
                int a = random(1, 51);
                int b = random(1, 51);
                if (row[a][b] == 0) {
                    row[a][b] = 3;
                }
                else {
                    j--;
                }
            }
            system("cls");
            print();
        }
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(0));
    
    Engine game;
    game.startGame();

}
