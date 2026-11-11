#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,m,ans;
ll a[200010];

void dfs(ll k,ll l,ll sum)
{
    if(l == m)
    {
        ans = max(ans,sum);
        return ;
    }

    if(k > n)
        return ;

    if(l == 1 && sum == 0)
        sum = a[k - 1];
    dfs(k + 1,l + 1,sum & a[k]);
    dfs(k + 1,l,sum);
}

int main( )
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(ll i = 1;i <= n;i ++)
        cin>>a[i];

    dfs(1,0,0);

    cout<<ans;

    return 0;
}
