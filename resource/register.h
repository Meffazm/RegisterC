#ifndef REGISTER_H
#define REGISTER_H

#include "record.h"
#include <vector>
#include <map>

using namespace std;

class Register
{
public:
    //datatypes
    typedef vector<Record*> RecVector;
    typedef map<string, Record*> NameIndex;
    typedef map<string, vector<Record*>> DepIndex;
    typedef map<string, set<Record*>> SubIndex ;

    //constructors
    Register(){}
    Register(string path, char delim){deserialize(path, delim);}

    //copy
    Register(const Register& other);

    //destructor
    ~Register(){eraseRecords();}

    //methods
    void deserialize(string path, char delim = '\t');
    void clear();

    //getters
    const RecVector& getStorage() const {return _storage;}
    const short getSize() const {return _storage.size();}
    const DepIndex& getDepIndex() const {return _depInd;}
    const SubIndex& getSubIndex() const {return _subInd;}

    //indexing
    Record* operator[](string s);

    //copy assignment
    Register& operator = (const Register& rhv);

private:
    //fields
    RecVector _storage;
    NameIndex _nameInd;
    DepIndex _depInd;
    SubIndex _subInd;


    //methods
    void eraseRecords();
    static void swap(Register& lhv, Register& rhv) noexcept
    {
        std::swap(lhv._storage, rhv._storage);
        std::swap(lhv._nameInd, rhv._nameInd);
        std::swap(lhv._depInd, rhv._depInd);
        std::swap(lhv._subInd, rhv._subInd);
    };
};

#endif // REGISTER_H
