#include "Flat.h"
#include <iostream>

using namespace std;

Flat::Flat() {
    ++counter;
    Flat **new_arr = new Flat *[counter];

    for (int i = 0; i < counter - 1; ++i) {
        new_arr[i] = arr[i];
    }
    new_arr[counter - 1] = this;
    delete[] arr;
    arr = new_arr;


}

Flat::Flat(int Rooms, int SquareCount, int CostPerMeter, int PeopleLive, int Floor) {
    Flat::Rooms = Rooms;
    Flat::SquareCount = SquareCount;
    Flat::CostPerMeter = CostPerMeter;
    Flat::PeopleLive = PeopleLive;
    Flat::Floor = Floor;

    ++counter;
    Flat **new_arr = new Flat *[counter];

    for (int i = 0; i < counter - 1; ++i) {
        new_arr[i] = arr[i];
    }
    new_arr[counter - 1] = this;
    delete[] arr;
    arr = new_arr;

}

Flat::Flat(const Flat &other) {
    Rooms = other.Rooms;
    SquareCount = other.SquareCount;
    CostPerMeter = other.CostPerMeter;
    PeopleLive = other.PeopleLive;
    Floor = other.Floor;

    ++counter;
    Flat **new_arr = new Flat *[counter];

    for (int i = 0; i < counter - 1; ++i) {
        new_arr[i] = arr[i];
    }
    new_arr[counter - 1] = this;
    delete[] arr;
    arr = new_arr;
}

void Flat::insertCost(int CostPerMeter) {
    Flat::CostPerMeter = CostPerMeter;
};

void Flat::insertSquare(int SquareCount) {
    Flat::SquareCount = SquareCount;
};

void Flat::insertPeople(int PeopleLive) {
    Flat::PeopleLive = PeopleLive;
};

void Flat::insertFloor(int Floor) {
    Flat::Floor = Floor;
};

void Flat::insertRooms(int Rooms) {
    Flat::Rooms = Rooms;

}

float Flat::AllAverageCost(int SquareCount) {
    int sum = 0;
    int count = 0;
    for (int i = 0; i < counter; ++i) {
        Flat *pointer = arr[i];

        if (pointer->SquareCount != 0 && pointer->CostPerMeter != 0 && pointer->SquareCount > SquareCount) {
            sum += (pointer->SquareCount * pointer->CostPerMeter);
            ++count;
        }
    }

    return sum / count;
};

float Flat::FloorAverageCost(int Floor) {
    int sum = 0;
    int count = 0;
    for (int i = 0; i < counter; ++i) {
        Flat *pointer = arr[i];

        if (pointer->SquareCount != 0 && pointer->CostPerMeter != 0 && pointer->Floor == Floor) {
            sum += (pointer->SquareCount * pointer->CostPerMeter);
            ++count;
        }
    }

    return sum / count;
};

void Flat::SortByPrice() {
    cout << "Цены квартир по-возрастанию на человека:" << endl;
    int count = 0; // Счётчик для квартир, в которых достаточно данных для анализа
    int counter_info = 0; // Счётчик для верного индексирования массива с данными о ценах
    Flat *pointer = nullptr;

    for (int i = 0; i < counter; ++i) {
        pointer = arr[i];
        if (pointer->SquareCount != 0 && pointer->CostPerMeter != 0 && pointer->PeopleLive != -1) {
            ++count;
        }
    }

    float *arr_data = new float[count];

    for (int i = 0; i < counter; ++i) {
        pointer = arr[i];
        if (pointer->SquareCount != 0 && pointer->CostPerMeter != 0 && pointer->PeopleLive != -1) {
            arr_data[counter_info++] = (pointer->SquareCount * pointer->CostPerMeter) / pointer->PeopleLive;
        }
    }

    for (int i = 0; i < counter_info - 1; ++i)
        for (int j = 0; j < counter_info - i - 1; j++)
            if (arr_data[j] > arr_data[j + 1])
                swap(arr_data[j], arr_data[j + 1]);

    for (int i = 0; i < counter_info; i++){
        cout << arr_data[i] << endl;
    }
    delete []arr_data;
}