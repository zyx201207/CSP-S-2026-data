#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int a[2000010];
int min_dis[5010][5010];
int ch,ans=0;
bool spC=1;
void dfs(int x)
{
    if(x>=n) return;
    int r=lower_bound(a+1,a+n+1,x+d)-a-1;
    if(x!=r)
    {
        for(int i=x;i<=r;i++)
        {
            min_dis[i][r]=1;
        }
    }
    dfs(x+1);
}
void dij()
{
    for(int i=1;i<=n-2;i++)
    {
        for(int j=i+1;j<=n-1;j++)
        {
            for(int l=j+1;l<=n;l++)
            {
                min_dis[i][l]=min(min_dis[i][l],min_dis[i][j]+min_dis[j][l]);
            }
        }
    }
    for(int i=1;i<=n-2;i++)
    {
        for(int j=i+1;j<=n-1;j++)
        {
            int cnt=0;
            for(int l=j+1;l<=n;l++)
            {
                if(min_dis[i][j]+min_dis[j][l]==min_dis[i][l]) cnt++;
            }
            if(cnt==2) ans++;
        }
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        ans=0;
        cin>>n>>d;
        cin>>a[1]>>a[2];
        int ch=a[2]-a[1];
        for(int i=3;i<=n;i++)
        {
           scanf("%d",&a[i]);
           if(a[i]-a[i-1]!=ch) spC=0;
        }
        if(spC==1)
        {
            if(d<ch*2) cout<<0<<endl;
            else cout<<d/ch<<endl;
        }
        else if(n<=5000)
        {
            memset(min_dis,1e9,sizeof(min_dis));
            dfs(1);
            dij();
            cout<<ans<<endl;
        }
        else cout<<0<<endl;
    }
}
