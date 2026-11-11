#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>

using namespace std;

string c1, s1, c2, s2;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    cin >> c1 >> s1 >> c2 >> s2;

    if (c1 == c2)
    {
        cout << "1";
        if (((int)s1[0] * 10 + (int)s1[0]) == ((int)s2[0] * 10 + (int)s2[0]))
        {
            cout << "1";
            if ((char(s1[2]) >= 'A' && 
                char(s1[2]) <= 'C') &&
                (char(s2[2]) >= 'A' && 
                char(s2[2]) <= 'C')
                )
            {
                cout << "1";
                if (abs(int(char(s1[2])) - int(char(s2[2]))) == 1)
                {
                    cout << "1";
                    return 0;
                }
                else
                {
                    cout << "0";
                    return 0;
                }
            }
            else if ((char(s1[2]) >= 'D' && 
                     char(s1[2]) <= 'F') &&
                     (char(s2[2]) >= 'D' && 
                     char(s2[2]) <= 'F')
                     )
            {
                cout << "11";
                return 0;
            }
            else
            {
                cout << "00";
                return 0;
            }
        }
        else
        {
            cout << "000";
            return 0;
        }
    }
    else
    {
        cout << "0000";
        return 0;
    }

    return 0;
}