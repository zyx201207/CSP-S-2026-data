#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string ra, rb, xa, xb;
    cin >> ra >> rb >> xa >> xb;
    string ans = "0000";
    if (ra != xa)
    {
        cout << ans << "\n";
        return 0;
    }
    ans[0] = '1';
    if (rb[0] != xb[0] || rb[1] != xb[1])
    {
        cout << ans << "\n";
        return 0;
    }
    if (rb[0] == xb[0] && rb[1] == xb[1]) ans[1] = '1';
    if (rb[2] == 'A' || rb[2] == 'B' || rb[2] == 'C')
    {
        if (xb[2] == 'A' || xb[2] == 'B' || xb[2] == 'C') ans[2] = '1';
        else if (xb[2] == 'D' || xb[2] == 'F')
        {
            cout << ans << "\n";
            return 0;
        }
    }
    else if (rb[2] == 'D' || rb[2] == 'F')
    {
        if (xb[2] == 'D' || xb[2] == 'F') ans[2] = '1', ans[3] = '1';
        else if (xb[2] == 'A' || xb[2] == 'B' || xb[2] == 'C')
        {
            cout << ans << "\n";
            return 0;
        }
    }
    if ((rb[2] == 'A' && xb[2] == 'B') || (xb[2] == 'A' && rb[2] == 'B')) ans[3] = '1';
    else if (rb[2] == 'B')
    {
        if (xb[2] == 'A' || xb[2] == 'C') ans[3] = '1';
    }
    else if (xb[2] == 'B')
    {
        if (rb[2] == 'A' || rb[2] == 'C') ans[3] = '1';
    }
    cout << ans;
    return 0;
}
