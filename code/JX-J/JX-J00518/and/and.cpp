#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;
int n,m;
ll a[N],ans,maxn;
bool vis[N];
void df(int dep,ll sum)
{
    if(sum == 0) return;
    if(sum <= ans) return;

    if(dep == m+1)
    {
        ans = max(ans,sum);
        return;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        if(vis[i]) continue;
        vis[i] = 1;
        df(dep+1,sum&a[i]);
        vis[i] = 0;
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    for(int i = 0 ; i <= 30 ; i++)
    {
        maxn += (ll)(1<<i);
    }
    df(1,maxn);
    cout << ans << "\n";


    return 0;
}
