#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],vis[500005],tong[500005],num[500005],sum[500005],cnt,flag;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i <=n ; i++)
    {
        cin>>a[i];
        tong[a[i]]++;
    }
    for(int i=1; i <= m; i++)
    {
        sum[i]=sum[i-1]+tong[i];
    }
    for(int i=1; i <= m; i++)
    {
        cout<<sum[i]<<" ";
    }
    return 0;
}


