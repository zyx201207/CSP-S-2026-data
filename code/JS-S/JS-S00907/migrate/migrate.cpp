#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e6 + 5;
ll c,t,n,d;
ll x[N];
void read(ll &x)
{
    x = 0; int f = 1;
    char c = getchar();
    while(!isdigit(c)) f = c == '-' ? -1 : f,c = getchar();
    while(isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48),c = getchar();
    x *= f;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    read(c); read(t);
    while(t--)
    {
        read(n); read(d);
        for(int i = 1;i <= n;++i) read(x[i]);
        sort(x + 1,x + n + 1);
        bool flagA = true;
        for(int i = 2;i < n;++i)
        {
            if(x[i + 1] - x[i] != x[i] - x[i - 1])
            {
                flagA = false;
                break;
            }
        }
        if(flagA)
        {
            int cha = x[2] - x[1];
            int xx = d / cha;
            ll ans = 0;
            ans += ((n - xx - 1) + 1) * (n - xx - 1) / 2;
            if(ans < 0){ puts("0"); continue; }
            else printf("%lld\n",ans);
            /*
            while(xx + 2 + xx < n)
            {
                for(int r = xx + 2;r <= n && r <= xx * 2;++r)
                {
                    ans += n - r + 1;
                }
                if(xx * 2 + 1  + 1 + xx + 1 <= n) ans += xx * 2 - xx - 2
                xx += x;
            }
            printf("%lld\n",ans);*/
        }
    }
    return 0;
}
