#ifndef CMPE250_ASSIGNMENT3_SEATOPERATIONS_H
#define CMPE250_ASSIGNMENT3_SEATOPERATIONS_H
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Person{
    int currentseat=1;
    int type=0;
    char line='C';
    int seatnumber=0;
    int lasti=0;
    string ticketinfo="";
};
class SeatOperations{
public:
    SeatOperations(int N, int M);
    void addNewPerson(int personType, const string& ticketInfo);
    void printAllSeats(ofstream& outFile);
    void seat(Person *p);
    void seatoperation(Person *p, char line, int index);
    vector<Person> lines[2];
    int N, M;
    // YOU CAN ADD YOUR HELPER FUNCTIONS
};

#endif //CMPE250_ASSIGNMENT3_SEATOPERATIONS_H