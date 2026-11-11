#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
const int N=5005,inf=1e16;
vector<int> e[N];
int x[N];
//int dis[N][N],cnt[N][N];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
            e[i].clear();
        }
        //memset(dis,0x3f,sizeof(dis));
        //memset(cnt,0,sizeof(cnt));
        //const int tmp=n;
        //vector<int> dis[tmp+5](tmp+5,inf),cnt[tmp+5](tmp+5,0);
        vector<int> dis[n+5],cnt[n+5];
        for(int i=1;i<=n;i++)
        {
            dis[i].push_back(0),cnt[i].push_back(0);
            for(int j=1;j<=n;j++)
            {
                dis[i].push_back(inf);
                cnt[i].push_back(0);
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(abs(x[i]-x[j])<=d)e[i].push_back(j);
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            dis[i][i]=0;
            queue<int> q;
            q.push(i);
            cnt[i][i]=1;
            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                for(int v:e[u])
                {
                    if(dis[i][u]+1<dis[i][v])
                    {
                        dis[i][v]=dis[i][u]+1;
                        cnt[i][v]+=cnt[i][u];
                        q.push(v);
                    }
                    else if(dis[i][u]+1==dis[i][v])cnt[i][v]+=cnt[i][u];
                }
            }
            for(int j=1;j<=n;j++)
            {
                if(cnt[i][j]==2)ans++;
            }
        }
        cout<<ans/2<<"\n";
    }
    return 0;
}
