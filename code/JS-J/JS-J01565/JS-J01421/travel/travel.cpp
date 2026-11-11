#include <bits/stdc++.h>
using namespace std;
string a,c;
char b[5],d[5];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a >> b >> c >> d;
    if(a == c)
    {
        cout << "1";
        if(b[0] == d[0] && b[1] == d[1])
        {
            cout << "1";
            if(((b[2] == 'D' || b[2] == 'E') && (d[2] == 'A' || d[2] == 'B' || d[2] == 'C')) || ((d[2] == 'D' || d[2] == 'E') && (b[2] == 'A' || b[2] == 'B' || b[2] == 'C')))
            {
                cout << "00";
            }
            else{
                cout << "1";
                if((b[2] == 'D' && d[2] == 'E') || (b[2] == 'E' && d[2] == 'D') ||  (b[2] == 'A' && d[2] == 'B') || (d[2] == 'A' && b[2] == 'B') || (b[2] == 'A' && d[2] == 'C') || (b[2] == 'C' && d[2] == 'A') || (b[2] == 'C' && d[2] == 'B') || (b[2] == 'B' && d[2] == 'C')
                   )
                {
                    cout << "1";
                }
                else{
                    cout << "0";
                }
            }
        }
        else
        {
            cout<<"1000";
        }
    }
    else{
        cout << "0000";
    }
    return 0;
}
