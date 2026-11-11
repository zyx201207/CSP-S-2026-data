#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m;
const int MAXN = 5 * 1e5 + 10;
ll cnt[MAXN];
bool f[MAXN];
ll ans[MAXN];
ll a[MAXN];
ll pre[MAXN];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%lld %lld", &n, &m);
    bool A = true;
    for(int i = 1;i <= n;i++)
    {
        scanf("%lld", &a[i]);
        if(a[i] < a[i - 1]) A = false;
        cnt[a[i]]++;
    }
    if(A)
    {
        for(int i = 1;i <= m;i++)
        {
            pre[i] = pre[i - 1] + cnt[i];
        }
        for(int i = 1;i <= m;i++)
        {
            printf("%lld ", pre[i]);
        }
        return 0;
    }
    for(int i = 1;i <= n;i++)
    {
        cnt[a[i - 1]]--;
        ll h = i;
        ll max_mw = i + 1;
        while(h < n)
        {
            if(cnt[a[h]] == 1)
            {
                h++;
                continue;
            }
            for(int i = n;i > h;i--)
            {
                if(a[i] == a[h])
                {
                    h = i;
                    max_mw = i + 1;
                    break;
                }
            }
            h++;
        }
        if(a[i] != a[max_mw - 1])
        {
            ans[a[i]]++;
            //printf("%lld ", a[i]);
        }
        for(int j = max_mw - 1;j <= n;j++) {
            ans[a[j]]++;
            //printf("%lld ", a[j]);
        }
        //printf("\n");
    }
    for(int i = 1;i <= m;i++) printf("%lld ", ans[i]);
    return 0;
}
