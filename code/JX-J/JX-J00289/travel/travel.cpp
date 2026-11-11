#include <bits/stdc++.h>
#define buff ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
using namespace std;

string tnum, snum, tnum2, snum2;
bool flag = true, flag2 = true;

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    buff;

    cin >> tnum >> snum >> tnum2 >> snum2;
    for (int i = 0; i < 2; i++)
    {
        if (snum[i] == snum2[i])
        {
            continue;
        }
        flag = false;
    }
    if (!(((snum[2] == 'A' || snum[2] == 'B' || snum[2] == 'C') && (snum2[2] == 'A' || snum2[2] == 'B' || snum2[2] == 'C')) || ((snum[2] == 'D' || snum[2] == 'F') && (snum2[2] == 'D' || snum2[2] == 'F'))))
    {
        flag2 = false;
    }
    if (tnum != tnum2)
    {
        cout << 0 << 0 << 0 << 0;
        return 0;
    }
    else if (!flag)
    {
        cout << 1 << 0 << 0 << 0;
        return 0;
    }
    else if (!flag2)
    {
        cout << 1 << 1 << 0 << 0;
        return 0;
    }
    else if (!(snum[2] == 'A' && snum2[2] == 'B' || snum[2] == 'B' && snum[2] == 'A') || (snum[2] == 'B' && snum2[2] == 'C' || snum[2] == 'C' && snum[2] == 'B') || (snum[2] == 'D' && snum2[2] == 'F' || snum[2] == 'F' && snum[2] == 'D'))
    {
        cout << 1 << 1 << 1 << 0;
        return 0;
    }
    cout << 1 << 1 << 1 << 1;
    return 0;
}
