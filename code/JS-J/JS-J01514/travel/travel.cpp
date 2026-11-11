#include <bits/stdc++.h>
#define int long long
using namespace std;
int f(char ch)
{
    switch (ch)
    {
    case 'A':
        return 1;
    case 'B':
        return 2;
    case 'C':
        return 3;
    case 'D':
        return -1;
    case 'F':
        return -2;
    }
}
signed main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int rc, xc, rp, xp, rpo, xpo;
    string tmp;
    cin >> rc >> tmp;
    rp = stoll(tmp.substr(0, 2));
    rpo = f(tmp[2]);
    cin >> xc >> tmp;
    xp = stoll(tmp.substr(0, 2));
    xpo = f(tmp[2]);
    if (rc != xc)
        cout << "0000";
    else
    {
        if (rp != xp)
            cout << "1000";
        else if ((rpo >= 0 && xpo >= 0) || (rpo <= 0 && xpo <= 0))
        {
            if (abs(xpo - rpo) == 1)
                cout << "1111";
            else
                cout << "1110";
        }
        else
            cout << "1100";
    }
    return 0;
}