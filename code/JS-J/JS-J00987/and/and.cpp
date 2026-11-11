#include <bits/stdc++.h>
using namespace std;
int m,n;
long long a[200005];
long long maxn=-1;
void dfs(long long last,int cnt,long long sum,int la,int step)
{
    if(cnt==m)
    {
        maxn=max(maxn,sum);
        return;
    }
    if(la==n) return;
    for(int i=la+1;i<=n;i++)
    {
        if(step==1) dfs(a[i],1,a[i],i,2);
        else if(a[i]!=a[la]) dfs(a[i],cnt+1,sum&a[i],i,step+1);
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    dfs(-1,0,0,0,1);
    cout<<maxn;
    return 0;
}
