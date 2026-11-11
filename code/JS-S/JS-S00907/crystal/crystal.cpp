#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
ll n,m;
ll a[N];
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
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    read(n); read(m);
    for(int i = 1;i <= n;++i) read(a[i]);
    sort(a + 1,a + n + 1);
    if(n <= 5000)
    {
        int ans = 1;
        for(int i = 2;i <= n;++i)
        {
            ll tmp = m;
            int l = i - 1,cnt = 1;
            while(tmp && l)
            {
                ll dil = a[i] - a[l];
                if(tmp - dil >= 0)
                {
                    l--;
                    tmp -= dil;
                    cnt++;
                }else break;
            }
            ans = max(ans,cnt);
        }
        printf("%d\n",ans);
    }else
    {
        ll d = a[2] - a[1];
        if(m < d)
        {
            puts("1");
            return 0;
        }
        ll x = (n - 1) * d + (n - 1) * (n - 2) * d / 2;
        if(x <= m)
        {
            printf("%d\n",n);
            return 0;
        }
        ll cnt = 0,tmp = m;
        while(tmp > 0)
        {
            cnt++;
            tmp -= cnt * d;
        }
        if(tmp < 0) cnt--;
        printf("%lld\n",cnt + 1);
    }
    return 0;
}
