#include <bits/stdc++.h>
using namespace std;

string a, b, c, d;

map<char, int> mp;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    mp['A'] = 1;
    mp['B'] = 1;
    mp['C'] = 1;
    mp['D'] = 2;
    mp['F'] = 2;
    cin >> a >> b >> c >> d;
    if (a == c)
    {
        cout << "1";
        if (b[0] == d[0] && b[1] == d[1])
        {
            cout << "1";
            if (mp[b[2]] == mp[d[2]])
            {
                cout << "1";
                if ((b[2] == 'D' && d[2] == 'F') || (b[2] == 'A' && d[2] == 'B') || (b[2] == 'B' && d[2] == 'C'))
                {
                    cout << "1";
                }
                else
                {
                    cout << "0";
                }
            }
            else
            {
                cout << "00";
            }
        }
        else
        {
            cout << "000";
        }
    }
    else
    {
        cout << "0000";
    }
    return 0;
}
/*
love ccf
ak
my luogu uid:forget but my name is Ryan20121209
8:30
let me see
oh how long the problem
8:35
oh it's so eazy
8:45
AC
*/
