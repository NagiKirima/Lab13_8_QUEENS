#include <iostream>
using namespace std;
int deck[8][8] = {};
void add_queen(int i, int j)
{
    for (int g = 0; g < 8; g++)
    {
        deck[g][j]++; //заполнение ряда, где стоит ферзь
        deck[i][g]++; //заполнение строки, где стоит ферзь
        
        
        int k;
        //////////////////////
        k = j - i + g;
        if (k >= 0 && k < 8) //главная диагональ
        {
            deck[g][k]++;
        }
        //////////////////////
        k = j + i - g;
        if (k >= 0 && k < 8) // побочная диагональ
        {
            deck[g][k]++;
        }
    }
    deck[i][j] = -1;//присваивание позиции ферзя значения -1
}
void delete_queen(int i, int j) 
{
        for (int g = 0; g < 8; g++)
        {
            deck[g][j]--; //удаление ряда, где стоит ферзь
            deck[i][g]--; //удаление строки, где стоит ферзь


            int k;
            //////////////////////
            k = j - i + g;
            if (k >= 0 && k < 8) // удаление главной диагональ
            {
                deck[g][k]--;
            }
            //////////////////////
            k = j + i - g;
            if (k >= 0 && k < 8) // удаление побочной диагональ
            {
                deck[g][k]--;
            }
        }
        deck[i][j] = 0;//присваивание позиции ферзя значения 0
}
bool test_queen(int i) 
{
    bool check_pos = false;
    for (int j = 0; j < 8; j++) 
    {
        if (deck[i][j] == 0) 
        {
            add_queen(i, j);
            if (i == 7)
            {
                check_pos = true;
                break;
            }
            else if ((check_pos = test_queen(i + 1)) == false)
            {
                delete_queen(i, j);
            }
        }
    }
    return check_pos;
}
void print_deck() 
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (deck[i][j] == -1) 
            {
                cout << "!!\t";
            }
            else 
            {
                cout << "-\t";
            }
        }
        cout << endl << endl << endl;
    }
}
int GetPos() 
{
    int pos;
    while (!(cin >> pos) || (cin.peek() != '\n') || (pos < 0) || (pos > 7)) 
    {
        cin.clear();
        while (cin.get()!='\n') 
        {
            cout << "Введите корректное число:\t";
        }
    }
    return pos;
}
int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Введите позицию в первой строке (от 0 до 7):\t";
    int PosX = GetPos();
    cout << "===================================================" << endl;
    add_queen(0, PosX);
    if (test_queen(1))
    {
        print_deck();
    }
    else 
    {
        cout << "Решения для данной позиции в 1 строке нет!" << endl;
    }
}