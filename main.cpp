#include <iostream>
#include "Flat.h"
using namespace std;


int main() {
    Flat flat1;
    flat1.insertCost(15);
    flat1.insertSquare(20);
    flat1.insertPeople(12);
    flat1.insertFloor(5);

    Flat flat2(2, 15, 3, 3, 5);

    Flat flat3 = flat2;
    cout << flat1.FloorAverageCost(5) << endl; // Вывод средней стоимости квартир на этаже

    cout << flat1.AllAverageCost(15) << endl; // Вывод средней цены на квартиры больше 15 кв. м

    flat3.SortByPrice(); // Цены квартир по-возрастанию на человека

    return 0;
}
