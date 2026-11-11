#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200010];
long long v[200010];
long long ans=0;
void dfs(long long x,long long y,long long s)
{
    if(s==m)
    {
        ans=max(ans,y);
        return;
    }
    for(long long i=1;i<=n;i++)
    {
        for(long long j=i;j<=n;j++)
        {
            if(v[j]==0)
            {
                v[j]=1;
                s++;
                long long c=y&a[j];
                dfs(j,c,s++);
                s--;
                v[j]=0;
            }
        }
    }
}
int main()
{
  freopen("and.in","r",stdin);
  freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(0,a[1],0);
    cout<<ans;
    return 0;
}
