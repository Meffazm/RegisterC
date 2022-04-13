#ifndef RECORD_H
#define RECORD_H

#include <string>
#include <sstream>
#include<set>

using namespace std;

class Record
{

public:

    //constructors
    Record();
    Record(string& str, char& delim);

    //copy
    Record(const Record& other);

    //operators overloading
    friend ostream& operator<<(ostream& output, const Record& item);

    //getters
    const short getAge() const {return _age;}
    const string getName() const {return _name;}
    const string getDep() const {return _department;}
    const string getBoss() const {return _boss;}
    const set<string> getDays() const {return _days;}

private:
    //fields
    string _name, _department, _position, _boss;
    short _age;
    set<string> _days;

};

#endif // RECORD_H
