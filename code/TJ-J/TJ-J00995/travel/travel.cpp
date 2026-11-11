#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string c,d;
    cin >> a >> c >> b >> d;
    if (a==b)
    {
        cout << 1;
        if (c[0]+c[1]==d[0]+d[1])
        {
            cout << 1;
            if (c[2]<='C' && d[2]<='C')
            {
                cout << 1;
                if (c[2]-'A'-1==d[2]-'A')
                {
                    cout << 1;
                }
                else if (c[2]-'A'+1==d[2]-'A')
                {
                    cout << 1;
                }
                else
                {
                    cout << 0;
                }

            }
            else if (c[2]>='D' && d[2]>='D')
            {
                cout << 1;
                cout << 1;
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
    cout << endl;
    return 0;
}

