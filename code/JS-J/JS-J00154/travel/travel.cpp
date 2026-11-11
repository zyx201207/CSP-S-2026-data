#include <bits/stdc++.h>
using namespace std;

string trainr, trainx, seatr, seatx;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> trainr >> seatr >> trainx >> seatx;
    if (trainr == trainx)
    {
        cout << 1;
        if (seatr[0] == seatx[0] && seatx[1] == seatr[1])
        {
            cout << 1;
            if ((seatr[2] >= 'D' && seatx[2]>='D') || (seatr[2] <= 'C' && seatx[2] <= 'C'))
            {
                cout << 1;
                if (seatr[2] >= 'D' && seatx[2]>='D')
                {
                    cout << 1;
                }
                else if (seatr[2] <= 'C' && seatx[2] <= 'C')
                {
                    if ((seatr[2] + 1 == seatx[2]) || (seatr[2] - 1 == seatx[2]))
                        cout << 1;
                    else
                        cout << 0;
                }
                
                else cout << 0;
            }
            else{
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

