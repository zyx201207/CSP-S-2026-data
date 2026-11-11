#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
typedef long long ll;
int c,t;
int n;
ll d;
ll ip[N];
ll tot;
bool vis[N][N];
bool jud[N],judge;
int e[N],ne[N],h[N],w[N],idx;
ll least=1e18,dis;
int dp[5000][5000],ans[5000][5000];
void add(int x,int y,int z)
{
    e[++idx]=y;
    ne[idx]=h[x];
    w[idx]=z;
    h[x]=idx;
    return;
}
//priority_queue<PII,vector<PII>,greater<PII>> q;
/*
void dijkstra(int u,int v)
{
    if(u==v)
    {
        if(dis<least)
        {
            ans=1;
            least=dis;
        }
        else if(dis==least)
        {
            ans++;
        }
        return;
    }
    for(auto k=h[u];k!=-1;k=ne[k])
    {
        auto v1=e[k];
        if(v1<=v)
        {
            dis+=w[k];
            dijkstra(v1,v);
            dis-=w[k];
        }
    }
    return;
}
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        tot=0;
        least=1e18;
       // map<ll,int> mp;
        cin>>n>>d;
        cout<<1;
        for(int i=1;i<=n;i++)
        {

            for(int j=1;j<=n;j++)
            {
                dp[i][j]=1e8;
            }
        }
        for(int i=1;i<=n;i++)
        {
            cin>>ip[i];
            dp[i][i]=0;
        }
        for(int i=2;i<=n;i++)
        {
            dp[i-1][i]=ip[i]-ip[i-1];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(ip[j]-ip[i]<=d)
                {
                    vis[i][j]=true;
                    add(i,j,ip[j]-ip[i]);
                }
            }
        }
     /*   for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                dis=0;
                dijkstra(i,j);
                if(ans==2)
                {
                    tot++;
                }
            }
        }
        */
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n,k!=i,k!=j;j++)
                {
                    if(dp[i][k]+dp[k][j]==dp[i][j])
                    {
                        ans[i][j]++;
                    }
                    else if(dp[i][k]+dp[k][j]<dp[i][j])
                    {
                        ans[i][j]=1;
                    }
                    dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                if(ans[i][j]==2)
                {
                    tot++;
                }
            }
        }
        cout<<tot<<"\n";
    }
    return 0;
}
