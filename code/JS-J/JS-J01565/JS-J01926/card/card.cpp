#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,m;
ll a[500010],place[300010],pre[500010],last[500010],ans[500010],sum[300010],behind[500010];

void dfs(ll k,ll beh)
{
    behind[k] = beh;

    if(k > n)
        return ;

    ans[k] = k - beh;

    if(last[k] == beh && k != 1)
        ans[k] = k - behind[last[k]];
    if(pre[k] != 0)
    {
        ans[k] = 0;
        dfs(k + 1,k);
    }
}

int main( )
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;
    for(ll i = 1;i <= n;i ++)
        cin>>a[i];

    for(ll i = 1;i <= n;i ++)
    {
        if(place[a[i]] != 0)
            last[i] = place[a[i]];
        place[a[i]] = i;
    }
    for(ll i = 1;i <= m;i ++)
        place[i] = 0;
    for(ll i = n;i >= 1;i --)
    {
        if(place[a[i]] != 0)
            pre[i] = place[a[i]];
        place[a[i]] = i;
    }

    for(ll i = 1;i <= n;i ++)
        ans[i] = ans[i - 1] + 1;
    dfs(1,0);
    for(ll i = 1;i <= n;i ++)
    {
        if(pre[i] != 0)
            ans[i] = 0;
        sum[a[i]] += ans[i];
    }

    for(ll i = 1;i <= m;i ++)
        cout<<sum[i]<<" ";

    return 0;
}
