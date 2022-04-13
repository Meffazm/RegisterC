#include "register.h"
#include <iostream>
#include <fstream>

Register::Register(const Register& other)
{
    for (Record* r : other._storage)
    {
        Record* rec = new Record(*r);
        _storage.push_back(rec);
        _nameInd[rec->getName()] = rec;
        _depInd[rec->getDep()].push_back(rec);
        if (rec->getBoss() != "")
            _subInd[rec->getBoss()].insert(rec);
    }
}

void Register::deserialize(string path, char delim)
{
    ifstream file(path);
    string line;
    if (file.is_open())
    {
        while (file)
        {
            getline(file, line);
            if (!line.empty())
            {
                Record* rec = new Record(line, delim);
                _storage.push_back(rec);
                _nameInd[rec->getName()] = rec;
                _depInd[rec->getDep()].push_back(rec);
                if (rec->getBoss() != "")
                    _subInd[rec->getBoss()].insert(rec);
            }

        }
        cout << "File is loaded to database\n";
    }
    else
        cout << "Couldn't open the file!\n";
}

void Register::clear()
{
    eraseRecords();
    _storage.clear();
    _nameInd.clear();
    _depInd.clear();
    _subInd.clear();
    cout << "All records are deleted\n";
}

Record* Register::operator[](string s)
{
    if (_nameInd.find(s) == _nameInd.end())
    {
        char delim(',');
        string str;
        return new Record(str, delim);
    }
    else
        return _nameInd[s];
}

Register& Register::operator = (const Register& rhv)
{
    if (this == &rhv)
        return *this;

    Register temp(rhv);
    swap(temp, *this);
    return *this;
}

void Register::eraseRecords()
{
    for (Record* p: _storage)
    {
        delete p;
    }
}

