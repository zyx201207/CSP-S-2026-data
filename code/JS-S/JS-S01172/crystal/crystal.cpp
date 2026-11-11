#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5e5 + 8;
LL n, m, a[N], pfx[N], ans = 0;
inline LL read()
{
    LL num = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-')
        {
            f = -1;
        }
        ch = getchar();
    }
    while('0' <= ch && ch <= '9')
    {
        num = (num << 3) + (num << 1) + ch - '0';
        ch = getchar();
    }
    return (f == 1 ? num : -num);
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n = read(), m = read();
    for(int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    LL l = 1, r = 1;
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
    {
        pfx[i] = pfx[i - 1] + a[i];
    }
    while(r <= n)
    {
        LL num = r - l + 1;
        if(num * a[r] - (pfx[r] - pfx[l - 1]) <= m)
        {
            ans = max(ans, num);
            r++;
        }
        else
        {
            l++;
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
