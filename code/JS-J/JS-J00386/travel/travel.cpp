#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.cpp","r","stdin");
    freopen("travel.cpp","w","stdout");
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a == c)
    {
        cout << "1";
        if(b[0] == d[0] && b[1] == d[1])
        {
            cout << "1";
            if(b[2] == 'D' && d[2] == 'F')
            {
                cout << "11";
                return 0;
            }
            if(d[2] == 'D' && b[2] == 'F')
            {
                cout << "11";
                return 0;
            }
            if((b[2] <= 'C' && d[2] <= 'C') || (b[2] > 'c' && d[2] > 'C'))
            {
                cout << "1";
                if(b[2] - 'A' + 1 == d[2] - 'A' || b[2] - 'A' - 1 == d[2] - 'A')
                {
                    cout << "1";
                }
                else cout << "0";
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
