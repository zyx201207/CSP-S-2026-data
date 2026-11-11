#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int a, b;
    string aa, bb;
    cin >> a >> aa >> b >> bb;
    if (a != b)
    {
        cout << "0000";
        return 0;
    } 
    cout << 1;
    if (aa[0] == bb[0] && aa[1] == bb[1])
    {
        cout << 1;
    } 
    else
    {
        cout << "000";
        return 0;
    } 
    if (aa[2] == 'D' || aa[2] == 'F')
    {
        if (bb[2] == 'D' || bb[2] == 'F')
        {
            cout << 11;
        } 
        else
        {
            cout << "00";
        } 
        return 0;
    } 
    else
    {
        if (bb[2] == 'A' || bb[2] == 'B' || bb[2] == 'C')
        {
            cout << 1;
        }
        else
        {
            cout << "00";
            return 0;
        }
    }
    if (abs(aa[2] - bb[2]) == 1) cout << 1;
    else cout << 0;
    return 0;
} 