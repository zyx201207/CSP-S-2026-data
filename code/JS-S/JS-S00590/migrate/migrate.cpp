#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d,ans=0,cnt=0;
int a[100000];
void dfs(int x,int y,int p,int nw)
{
    if(nw==y)
    {
        ans=min(ans,p);
    }
    else{
        for(int i=1;i+nw<=y;i++)
        {
            if(a[nw+i]-a[nw]<=d)
            {
                dfs(x,y,p+1,nw+i);
            }
        }
    }
}
void dfs2(int x,int y,int p,int nw)
{
    if(nw==y&&ans==p)
    {
        cnt++;
    }
    else{
        for(int i=1;i+nw<=y;i++)
        {
            if(a[nw+i]-a[nw]<=d)
            {
                dfs(x,y,p+1,nw+i);
            }
        }
    }
}
signed main()
{
    freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cnt=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                ans=n+1;
                dfs(i,j,0,i);
                cout<<i<<" "<<j<<" "<<ans<<endl;
                dfs2(i,j,0,i);
                cnt--;
            }
        }
        cout<<cnt<<endl;
    }
}
