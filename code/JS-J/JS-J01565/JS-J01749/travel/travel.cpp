#include <bits/stdc++.h>
using namespace std;
int mp[256];
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    mp['A'] = 1;
    mp['B'] = 2;
    mp['C'] = 3;
    mp['D'] = 11;
    mp['F'] = 12;
    int a, b;
    string A, B;
    cin >> a >> A >> b >> B;
    if (a != b)
    {
        cout << "0000" << endl;
        return 0;
    }
    else
    {
        cout << "1";
        if (stoi(A.substr(0, 2)) != stoi(B.substr(0, 2)))
        {
            cout << "000" << endl;
            return 0;
        }
        else
        {
            cout << "1";
            char c = A.back(), d = B.back();
            if (c > d)
            {
                swap(c, d);
            }
            if (mp[(unsigned char)d] - mp[(unsigned char)c] < 3)
            {
                cout << "1";
                if (mp[(unsigned char)d] - mp[(unsigned char)c] == 1)
                {
                    cout << "1" << endl;
                    return 0;
                }
                else
                {
                    cout << "0" << endl;
                    return 0;
                }
            }
            else
            {
                cout << "00" << endl;
            }
        }
    }
    return 0;
}