#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int a1, a2, c = 4, f = 0, n1 = 0, n2 = 0;
    string b1, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    if(a1 == a2)
    {
        cout << 1;
        c--;
        if(b1[0] == b2[0] && b1[1] == b2[1])
        {
            cout << 1;
            c--;
            if(b1[2] >= 'D' && b2[2] >= 'D')
            {
                cout << 1;
                c--;
            }
            else if(b1[2] <= 'C' && b2[2] <= 'C')
            {

                cout << 1;
                c--;
            }

        }
        if(b1[0] == b2[0] && b1[1] == b2[1])
        {
            if(b1[2] == 'D' || b2[2] == 'D')
            {
                if(b1[2] == 'F' || b2[2] == 'F')
                {
                    f = 1;
                    c--;
                }
            }
            else if(b1[2] == 'B' || b2[2] == 'B')
            {
                if(b1[2] == 'A' || b2[2] == 'A')
                {
                    f = 1;
                    c--;
                }
                else if(b1[2] == 'C' || b2[2] == 'C')
                {
                    f = 1;
                    c--;
                }
            }
        }
    }

    if(c > 0)
    {
        for(int i = 1; i <= c; i++)
        {
            cout << 0;
        }

    }
    if(f == 1)
    {
        cout << 1;
    }
    return 0;






    return 0;
}
