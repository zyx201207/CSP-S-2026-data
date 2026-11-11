#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string cx1, cx2, zw1, zw2;
    cin >> cx1 >> zw1 >> cx2 >> zw2;
    if (cx1 == cx2)
    {
        cout << "1";
    }
    else
    {
        cout << "0000";
        return 0;
    }
    if (zw1[0] == zw2[0])
    {
        if (zw1[1] == zw2[1])
        {
            cout << "1";
            int a = zw1[2], b = zw2[2];
            if ((a + b == 131) || (a + b == 132) || (a + b == 133) || (a + b == 138))
            {
                cout << "1";
                if (a + b == 132)
                {
                    cout << "0";
                }
                else
                {
                    cout << "1";
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
        cout << "000";
    }
    return 0;
}
