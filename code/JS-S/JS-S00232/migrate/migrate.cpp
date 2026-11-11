#include <bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while(!isdigit(c))
    {
        if(c == '-') f = -1;
        c = getchar();
    }
    while(isdigit(c))
        x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x * f;
}
signed main()
{
    //freopen("migrate.in", "r", stdin);
    //freopen("migrate.out", "w", stdout);
    return 0;
}
