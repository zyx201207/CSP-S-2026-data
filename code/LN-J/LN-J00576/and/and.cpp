#include<bits/stdc++.h>
using namespace std;
#define int long long
int m,n,a[200005];
int ans=0;
void dfs(int loc,int lel,int sum)
{
    if(lel==1)
    {
        sum=a[loc];
    }
    if(lel==m)
    {
        sum=sum&a[loc];
        ans=max(ans,sum);
        return;
    }
    for(int i=loc+1;i<=n-(m-lel)+1;i++)
    {
        dfs(i,lel+1,sum&a[loc]);
    }
    return;
}
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    dfs(1,0,0);
    printf("%lld",ans);
    return 0;
}
