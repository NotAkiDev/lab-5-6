#ifndef LAB_5_6_FLAT_H
#define LAB_5_6_FLAT_H


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


#endif //LAB_5_6_FLAT_H
