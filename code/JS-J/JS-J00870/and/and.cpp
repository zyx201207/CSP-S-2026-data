#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,ans,a[N];
bool vis[N];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=29;i>=0;i--)
    {
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            if(vis[j]==1) continue;
            if((a[j]>>i)&1) cnt++;
        }
        if(cnt<m) continue;
        ans+=(1<<i);
        for(int j=1;j<=n;j++)
        {
            if(vis[j]==1) continue;
            if(((a[j]>>i)&1)==0) vis[j]=1;
        }
    }
    printf("%d\n",ans);
    return 0;
}
