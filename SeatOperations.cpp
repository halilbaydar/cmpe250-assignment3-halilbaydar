#include "SeatOperations.h"
using namespace std;
vector<Person> lineA; vector<Person> lineB;
SeatOperations::SeatOperations(int N, int M) {
    this->N=N; this->M=M;
    Person person;
    for (int i = 0; i <N+1 ; ++i)
        lineA.push_back(person);
    for (int j = 0; j <M +1; ++j)
        lineB.push_back(person);
    lines[0]=lineA; lines[1]=lineB;
}
void SeatOperations::seatoperation( Person *p, char line, int index){
    int t=0;
    line=='A' ? t=0 : t=1;
    p->currentseat=index;
    p->line=line;
    p->lasti++;
    if(lines[t][index].type ==0 ){
        lines[t][index]=*p;
        return;
    }else{
        Person temp=lines[t][index];
        lines[t][index]=*p;
        seat(&temp);
        return;
    }
}
void SeatOperations:: seat( Person *p) {
    int index = p->seatnumber;
    if (p->lasti > 0){
        if (p->type == 1) {
            p->line == 'A' ? index = p->seatnumber % (M) : index = p->seatnumber % (N);
            if (index == 0) {
                p->line == 'A' ? seatoperation( p, 'B', M) : seatoperation( p, 'A', N);
            } else p->line == 'A' ? seatoperation( p, 'B', index) : seatoperation( p, 'A', index);
        } else if (p->type == 2) {
            if (p->line == 'A') {
                p->currentseat + 1 <= N ? seatoperation( p, 'A', p->currentseat + 1) : seatoperation( p, 'B',1);
            } else {
                p->currentseat + 1 < M + 1 ? seatoperation( p, 'B', p->currentseat + 1) : seatoperation( p,'A', 1);
            }
        } else if (p->type == 3) {
            index=(p->currentseat+p->lasti*2-1)%(M+N);
            if(p->line=='A'){
                if(index!=0)index>(N)? seatoperation(p,'B',index-N) :seatoperation(p,'A',index);
                else seatoperation(p,'B',M);
            }else{
                if(index!=0)index>(M)? seatoperation(p,'A',index-M) :seatoperation(p,'B',index);
                else seatoperation(p,'A',N);
            }
        }
    }else{
        if(p->line=='A'){
            index=index%(N);
            index!=0? seatoperation(p,'A',index):  seatoperation(p,'A',N);
        }else{
            index=index%(M);
            index!=0 ? seatoperation(p,'B',index) : seatoperation(p,'B',M);
        }
    }
}
void SeatOperations::addNewPerson(int personType, const string& ticketInfo){
    string s="";
    char typeseat=ticketInfo.at(0);
    int ticketnumber=std::stoi(ticketInfo.substr(1));
    Person person;
    person.line=typeseat;
    person.seatnumber=ticketnumber;
    person.ticketinfo=ticketInfo;
    person.currentseat=0;
    person.lasti=0;
    person.type=personType;
    seat(&person);
}
void SeatOperations::printAllSeats(ofstream& outFile){
    for (int i = 1; i <= N; ++i) {
        lines[0][i].type!=0 ? outFile << lines[0][i].type  << " " << lines[0][i].ticketinfo<<endl : outFile << lines[0][i].type<<endl;
    }
    for (int i = 1; i <=M; ++i) {
        lines[1][i].type!=0 ?  outFile<<lines[1][i].type << " "<< lines[1][i].ticketinfo<<endl : outFile<<lines[1][i].type<<endl;
    }
}