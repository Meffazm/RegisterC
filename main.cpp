#include "resource/record.h"
#include "resource/register.h"
#include "resource/helpers.cpp"

using namespace std;

int main()
{
    Register r;
    char inp = 'z';
    string input, buff;
    set<string> days;
    short a, b;

    printHeader();
    while (inp != 'x')
    {
        cout << "\nChoose an action: ";
        getline(cin, input);
        if  (input.length() == 0)
            continue;
        else if (input.length() > 1)
        {
            cout << "Wrong input!\n";
            continue;
        }
        else
           inp = tolower(input[0]);
        switch (inp) {
            case 'l':
                cout << "Enter a file path: ";  //example filepath D:/cpp/employees.csv
                getline(cin, input);
                r.deserialize(input);
                break;
            case 'c':
                r.clear();
                break;
            case 'n':
                cout << r.getSize() << endl;
                break;
            case 'p':
                allRecords(r);
                break;
            case 'e':
                cout << "Enter a name: ";
                getline(cin, input);
                findByName(r, input);
                break;
            case 'a':
                cout << "Enter an age interval: ";
                cin >> a >> b;
                ageRecords(r, a, b);
                cin.ignore();
                break;
            case 'd':
                cout << "Enter a department: ";
                getline(cin, input);
                findByDep(r, input);
                break;
            case 's':
                cout << "Enter a name: ";
                getline(cin, input);
                findSubordinates(r, input);
                break;
            case 'w':
                cout << "Enter days separated by spaces: ";
                getline(cin, input);
                findDays(r, setFromString(input));
                break;
            case 'h':
                cout << endl;
                printHeader();
                break;
            case 'x':
                cout << "\nFarewell!\n\n";
                break;
        default:
            cout << "Wrong input!\n";
            break;
        }
    }
    return 0;
}


