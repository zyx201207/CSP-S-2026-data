#include <bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> r1 >> r2 >> x1 >> x2;
    if(r1 == x1)
    {
        cout << 1;
        if(r2.substr(0,2) == x2.substr(0,2))
        {
            cout << 1;
            if(r2[2] == 'D' && x2[2] == 'F')
            {
                cout << 11;
            }
            else if(r2[2] == 'F' && x2[2] == 'D')
            {
                cout << 11;
            }
            else if(r2[2] <= 'C' && r2[2] >= 'A')
            {
                if(x2[2] <= 'C' && x2[2] >= 'A')
                {
                    cout << 1;
                    switch(r2[2])
                    {
                        case 'B':
                            cout << 1;
                            break;
                        case 'A':
                            cout << (x2[2] == 'B'?1:0);
                            break;
                        case 'C':
                            cout << (x2[2] == 'B'?1:0);
                            break;
                    }
                }
                else cout << "00";
            }
            else cout << "000";
        }
        else cout << "000";
    }
    else cout << "0000";
    return 0;
}
