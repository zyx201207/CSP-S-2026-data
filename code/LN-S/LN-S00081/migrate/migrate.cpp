#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,d,x[2000005];
vector<int>e[10005];
int dis[10005],cnt[10005],vis[10005],r[2000005],l[2000005],sum[2000005];
queue<int>q;
int bfs(int s)
{
    memset(dis,0x3f,sizeof(dis));
    memset(cnt,0,sizeof(cnt));
    memset(vis,0,sizeof(vis));
    dis[s]=0,cnt[s]=1;q.push(s);int cc=0;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        if(cnt[u]==2) cc++;
        if(cnt[u]>2) continue;
        for(auto v:e[u])
        {
            if(dis[v]==dis[u]+1) cnt[v]+=cnt[u];
            else if(dis[v]>dis[u]+1) 
            {
                dis[v]=dis[u]+1;cnt[v]=cnt[u];
                if(!vis[v]) q.push(v);
            }
        }
    }
    return cc;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c,t;cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        if(n<=5000)
        {
            for(int i=1;i<=n;i++)
            {
                cin>>x[i];e[i].clear();
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    if(x[j]-x[i]<=d)
                    {
                        e[i].push_back(j);
                    }
                }
            }int ans=0;
            for(int i=1;i<=n;i++)
            {
                ans+=bfs(i);
            }
            cout<<ans<<endl;
        }
        else
        {
            int qwq=0;
            for(int i=1;i<=n;i++) cin>>x[i];
            for(int i=2;i<=n;i++) if(x[i]-x[i-1]!=x[2]-x[1]) qwq=1;
            if(qwq)
            {
                int qw=0;
                for(int i=0;i<=n;i++) sum[i]=0;
                for(int i=1;i<=n;i++)
                {
                    r[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
                    l[i]=lower_bound(x+1,x+n+1,x[i]-d)-x;
                    sum[l[i]]++;
                    if(r[i]==n) qw=r[i];
                }
                int ans=0;
                for(int i=1;i<n;i++)
                {
                    if(r[i]-1<=i) continue;
                    ans+=sum[r[i]-1];
                }
                cout<<ans<<endl;
            }
            if(!qwq)
            {
                qwq=abs(x[2]-x[1]);
                if(d<qwq*2) cout<<0<<endl;
                else
                {
                    cout<<max(0ll,n-(d/qwq)*2+1)<<endl;
                }
            }
        }
    }
    return 0;
} 
//咋办来着，不会T3/dk

//100+100+40 有NOIP进么

//加Q群 “What should I do" 谢谢呱。