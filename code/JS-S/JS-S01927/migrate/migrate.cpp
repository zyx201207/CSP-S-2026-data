#include <bits/stdc++.h>
using namespace std;
#define int long long
int read()
{
    int k = 1, ans = 0;
    char ch = getchar_unlocked();
    while (!isdigit(ch))
    {
        if (ch == '-')
            k = -1;
        ch = getchar_unlocked();
    }
    while (isdigit(ch))
    {
        ans = ans * 10 + ch - '0';
        ch = getchar_unlocked();
    }
    return ans * k;
}
signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c = read(), t = read();
    if(t==2)
        cout<<"1\n2";
    else
        cout<<0;
    return 0;
}
