#include<bits/stdc++.h>
using namespace std;
const int N=102;
int ma[N][N];
int cnt[1<<15];
vector<int>Ma[1000010];
int vis[1111],n;
void dfs(int x,int f)
{
    vis[x]=f;
    for(int i=1;i<=n;i++)
    {
        if(ma[i][x]==1&&vis[i]!=f&&(0!=(f&(1<<i-1))))
            dfs(i,f);
    }
}
void solve()
{
    int k;
    cin>>n>>k;
    if(n>15)
    {
        ;
    }
    memset(ma,0x3f,sizeof ma);
    for(int i=1;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            ma[x][y]=1;
            ma[y][x]=1;
        }
    for(int i=0;i<=n;i++)
        ma[i][i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                ma[j][k]=min(ma[i][k]+ma[j][i],ma[j][k]);
            }
        }
    }
    int ans=11111;
    for(int i=1;i<1<<n;i++)
    {
        cnt[i]=cnt[i&i-1]+1;
        if(cnt[i]==k)
        {
            int ct=0;
            for(int j=1;j<=n;j++)
            {
                if(vis[j]!=i&&(0!=(i&(1<<j-1))))
                    dfs(j,i),ct++;
            }
            if(ct>2)continue;
            int aa=0;
            for(int j=1;j<=n;j++)
            {
                if(i&(1<<j-1))continue;
                int aaa=111111;
                for(int k=1;k<=n;k++)
                {
                    if(i&(1<<k-1))aaa=min(aaa,ma[j][k]);
                }
                aa=max(aaa,aa);
            }
            ans=min(aa,ans);
        }
    }
    cout<<ans<<'\n';
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
        solve();
    return 0;
}
