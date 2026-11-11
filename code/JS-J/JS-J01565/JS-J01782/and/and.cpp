#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
bool vis[N];
int n,m,ans=INT_MIN;
void dfs(int step,int s)
{
    if(step>m)
    {
        ans=max(ans,s);
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            dfs(step+1,s&a[i]);
            vis[i]=0;
        }
    }
}
int main()
{
   freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
   cin>>n>>m;
   for(int i=1;i<=n;i++)
   {
       cin>>a[i];
   }
   dfs(1,-1);
   cout<<ans<<endl;
    return 0;
}






































