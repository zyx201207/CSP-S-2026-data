#include <bits/stdc++.h>
using namespace std;

string t[7][20];

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a,b;
    int a1,a2;
    bool _1 = false, _2 = false, _3 = false, _4 = false;
    cin >> a1 >> a >> a2 >> b;
    if (a1 != a2)
    {
        cout << "0000";
        return 0;
    }
    else _1 = true;
    string s1;
    s1 = a[0] + a[1];
    string s2;
    s2 = b[0] + b[1];
    if (s1 == s2)
    {
        _2 = true;
        if (a[2] >= 'A' && a[2] <= 'C' && b[2] >= 'A' && b[2] <= 'C')
        {
            _3 = true;
            if (a[2] == 'A')
            {
                if (b[2] == 'B')
                    _4 = true;
            }
            else if (a[2] == 'B')
            {
                if (b[2] == 'A' || b[2] == 'C')
                    _4 = true;
            }
            else if (a[2] == 'C')
            {
                if (b[2]=='B') _4 = true;
            }
        }
        else if (a[2] >= 'D' && a[2] <= 'F' && b[2] >= 'D' && b[2] <= 'F')
        {
                _3 = true;
                _4 = true;
        }
    }

    cout << _1 << _2 << _3 << _4;
    return 0;
}
