#include <bits/stdc++.h>
using namespace std;
int main(){

    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);


    string co1, so1, co2, so2;
    cin >> co1 >> so1 >> co2 >> so2;

    int c1 = 0, s1 = 0, c2 = 0, s2 = 0;
    for(int i = 0; i < 2; i ++)
    {
        c1 = (co1[i] - '0') + c1 * 10;
        c2 = (co2[i] - '0') + c2 * 10;
    }
    for(int i = 0; i < 2; i ++)
    {
        s1 += (so1[i] - '0') + s1 * 10;
        s2 += (so2[i] - '0') + s2 * 10;
    }
    char x1 = so1[2], x2 = so2[2];

    if(c1 == c2)
    {
        cout << 1;
        if(s1 == s2)
        {
            cout << 1;
            if((x1 == 'C' && x2 == 'D') || (x1 == 'D' && x2 == 'C'))
            {
                cout << "00";
            }
            else
            {
                cout << 1;
                if(x1 - x2 == 1 || x1 - x2 == -1)
                    cout << 1;
                else
                    cout << 0;
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
