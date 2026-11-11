#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5+10;

ll n,m;
ll a[maxn];
ll ans=-1;

void dfs(ll cnt,ll sum,ll inx)
{
    if(cnt==m)
    {
        cout << cnt << " " << sum  << " " << inx << " " << ans << "\n";
        ans=max(ans,sum);
        return ;
    }

    for(int i=inx;i<=n;i++)
    {
        if(i==inx)
        {
            continue;
        }
        ll temp = sum&a[i];

        cout << cnt << " " << sum << "&" << a[i] << "=" << temp << " " << i << "\n";

        dfs(cnt+1,sum&a[i],i);

    }

    return ;
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    if(n<=20)
    {
        for(int i=1;i<=n;i++) dfs(1,a[i],i);
    }
    cout << ans;

    return 0;
}
/*
2023/08/23 - 2026/10/31
Aetherius AFO
cout << "Bye World!";
Q.E.D
*/
