#include <iostream>
#include "register.h"
#include <algorithm>

using namespace std;

void printHeader()
{
    cout << "Emplyee Database\n";
    cout << "================\n\n";
    cout << "(H) Print header\n";
    cout << "(L) Load a file\n";
    cout << "(C) Clear dataset\n";
    cout << "(N) Print number of records in dataset\n";
    cout << "(P) Print all records\n";
    cout << "(E) Print an employee by their name\n";
    cout << "(A) Print all employees with an age in a given interval\n";
    cout << "(D) Print all employees in particular department\n";
    cout << "(S) Print all subordinates of employee\n";
    cout << "(W) Print all employees working in this days\n";
    cout << "(X) Exit\n";
}

void allRecords(Register& r)
{
    for (Record* p: r.getStorage())
    {
        cout << *p << endl;
    }
}

void ageRecords(Register& r, short a, short b)
{
    bool empty = true;
    for (Record* p: r.getStorage())
    {
        if ((p->getAge() >= a) && (p->getAge() <= b))
        {

            cout << *p << endl;
            empty = false;
        }
    }
    if (empty)
        cout << "No employees in a given range\n";
}


void findByName(Register& r, string name)
{
    if (r[name]->getName() == "")
        cout << "No employee with this name\n";
    else
        cout << *r[name] << endl;
}

void findByDep(Register& r, string dep)
{
    if (r.getDepIndex().find(dep) == r.getDepIndex().end())
        cout << "No employees in this Department\n";
    else
        for (Record* p: r.getDepIndex().at(dep))
        {
            cout << *p << endl;
        }
}

void subordinatesRecursion(Register& r, string name, vector<Record*>& res)
{
    if (r.getSubIndex().find(name) != r.getSubIndex().end())
    {
        for (Record* p: r.getSubIndex().at(name))
        {
            res.push_back(p);
            subordinatesRecursion(r, p->getName(), res);
        }
    }
    else
        return;
}

vector<Record*> findSubordinates(Register& r, string name)
{
    vector<Record*> res;
    if (r[name]->getName() == "")
        cout << "No employee with this name\n";
    else
        subordinatesRecursion(r, name, res);

    if (!res.empty())
    {
        for (Record* p: res)
        {
            cout << *p << endl;
        }
    }
    return res;
}

bool checkCommon(set<string> const& a, set<string> const& b)
{
    return find_first_of(a.begin(), a.end(), b.begin(), b.end()) != a.end();
}

set<string> setFromString(string& str)
{
    set<string> res;
    string buff;
    stringstream sstr(str);
    while (sstr)
    {
        sstr >> buff;
        if (!buff.empty())
            res.insert(buff);
    }
    return res;
}

set<Record*> findDays(Register& r, set<string> days)
{
    set<Record*> res;
    for (Record* p: r.getStorage())
    {
        if (checkCommon(p->getDays(), days))
        {
            res.insert(p);
            cout << *p << endl;
        }
    }
    if (res.empty())
        cout << "No employees working in this days";
    return res;
}
