#include "record.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

Record::Record(string& str, char& delim)
{
    stringstream input(str);
    string field;
    size_t counter(0);

    while (input)
    {
        getline(input, field, delim);
        switch (counter) {
        case 0:
            _name = field;
            break;
        case 1:
            _age = stoi(field);
            break;
        case 2:
            _department = field;
            break;
        case 3:
            _position = field;
            break;
        case 4:
            _boss = field;
            break;
        default:
            _days.insert(field);
            break;
        }
        ++counter;
    }
}

Record::Record(const Record& other)
{
    _name = other._name;
    _department = other._department;
    _position = other._position;
    _boss = other._boss;
    _age = other._age;
    _days = other._days;
}

ostream& operator<<(ostream& output, const Record& item)
{
    output << "Name: " << item._name << ", Age: " << item._age << ", Department: " << item._department;
    output << ", Position: " << item._position << ", Boss: " << item._boss;
    return output;
}
