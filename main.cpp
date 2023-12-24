#include <iostream>

using namespace std;


class Flat {
private:
    int Rooms = 0;
    int SquareCount = 0;
    int CostPerMeter = 0;
    int PeopleLive = -1;
    int Floor = 0;

    inline static int counter = 0;
    inline static Flat **arr = {};

public:
    Flat();

    Flat(int Rooms, int SquareCount, int CostPerMeter, int PeopleLive, int Floor);

    Flat(const Flat &other);

    ~Flat(){};

    void insertRooms(int Rooms);

    void insertCost(int CostPerMeter);

    void insertSquare(int SquareCount);

    void insertPeople(int PeopleLive);

    void insertFloor(int Floor);

    float AllAverageCost(int SquareCount);

    float FloorAverageCost(int Floor);

    void SortByPrice();

};

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
};

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
