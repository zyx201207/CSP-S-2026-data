#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a[0] != c[0] or a[1] != c[1]) cout << 0000;
    else
    {
        cout << 1;
        if(b[0] != d[0] or b[1] != d[1]) cout << 000;
        else
        {
            cout << 1;
            if(b[2] == 'A' or b[2] == 'B' or b[2] == 'C')
            {
                if(d[2] == 'A' or d[2] == 'B' or d[2] == 'C')
                {
                    cout << 1;
                    if(b[2] == 'B' or d[2] == 'B') cout << 1;
                    else cout << 0;
                }
            }
            else
            {
                if(d[2] == 'D' or d[2] == 'F') cout << 11;
                else cout << 00;
            }
        }
    }
    return 0;
}
