#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int lc, lp, rc, rp;
    char lch, rch;
    cin >> lc;
    cin >> lp;
    cin >> lch;
    cin >> rc;
    cin >> rp;
    cin >> rch;
    cout << (lc == rc) << (lp == rp && lc == rc);
    if(lp == rp && lc == rc)
    {
        lc = lch - 'A';
        rc = rch - 'A';
        cout << ((lc <= 2 && rc <= 2) || (lc > 2 && rc > 2));
        if((lc <= 2 && rc <= 2) || (lc > 2 && rc > 2))
            cout << (abs(rc - lc) == 1) << endl;
        else
            cout << 0 << endl;

    }
    else
    {
        cout << "00" << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
