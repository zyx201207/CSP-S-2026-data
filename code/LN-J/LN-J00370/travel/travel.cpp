#include <iostream>
#include <string>
using namespace std;
//
int cr, cx;
string sr, sx;
//
int main()
{
    freopen ("travel.in", "r", stdin);
    freopen ("travel.out", "w", stdout);
    //
    cin >> cr >> sr >> cx >> sx;
    if (cr == cx)
    {
        cout << 1;
    }
    else
    {
        cout << "0000";
        return 0;
    }
    if (sr[0] * 10 + sr[1] == sx[0] * 10 + sx[1])
    {
        cout << 1;
    }
    else
    {
        cout << "000";
        return 0;
    }
    if (sr[2] > 'C' && sx[2] > 'C')
    {
        cout << "11";
        return 0;
    }
    else if (sr[2] < 'D' && sx[2] < 'D')
    {
        if (sr[2] - sx[2] == 1 || sr[2] - sx[2] == -1)
        {
            cout << "11";
            return 0;
        }
        else
        {
            cout << "10";
            return 0;
        }
    }
    else
    {
        cout << "00";
        return 0;
    }
    //
    return 0;
}