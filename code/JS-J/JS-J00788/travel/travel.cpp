#include <bits/stdc++.h>
using namespace std;
string cartR, seatR, cartX, seatX;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> cartR >> seatR >> cartX >> seatX;
    if (cartR == cartX)
    {
        cout << 1;
        if (seatR[0] == seatX[0] && seatR[1] == seatX[1])
        {
            cout << 1;
            if (
                (
                    ((seatR[2] == 'A') || (seatR[2] == 'B') || (seatR[2] == 'C'))
                    && 
                    ((seatX[2] == 'A') || (seatX[2] == 'B') || (seatX[2] == 'C'))
                )
                ||
                (
                    ((seatR[2] == 'D') || (seatR[2] == 'F'))
                    && 
                    ((seatX[2] == 'D') || (seatX[2] == 'F'))
                )
            )
            {
                cout << 1;
                if (
                    ((seatR[2] == 'B') || (seatX[2] == 'B'))
                    ||
                    ((seatR[2] == 'D') && (seatX[2] == 'F'))
                    ||
                    ((seatR[2] == 'F') && (seatX[2] == 'D'))
                )
                {
                    cout << 1;
                }
                else
                {
                    cout << 0;
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
        cout << "0000";
    }
    cout << endl;
    return 0;
}