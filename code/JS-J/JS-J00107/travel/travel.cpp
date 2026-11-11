#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin >> a >> b >> c >> d;
    //cout << a << endl << b << endl << c << endl << d << endl;
    if(a != c)
    {
        cout << "0000";
    }
    else
    {
        cout << "1";
        if(b[0] == d[0] && b[1] == d[1])
        {
            cout << "1";
            if(b[2] >= 'A' && b[2] <= 'C')
            {
                if(d[2] >= 'A' && d[2] <= 'C' && b[2] != d[2])
                {
                    cout << "1";
                    if((b[2] == 'A' && d[2] == 'B') || (b[2] == 'B' && d[2] == 'A') || (b[2] == 'B' && d[2] == 'C') || (b[2] == 'C' && d[2] == 'B'))
                    {
                        cout << "1";
                    }
                    else cout << "0";
                }
                else cout << "00";
            }
            else if(b[2] == 'D' || b[2] == 'F')
            {
                if((d[2] == 'D' || d[2] == 'F') && b[2] != d[2])
                {
                    cout << "11";
                }
                else cout << "00";
            }
        }
        else cout << "000";
    }
    return 0;
}
