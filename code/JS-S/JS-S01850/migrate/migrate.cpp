#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,x[5007],cnt[5007],dis[5007];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        memset(x,0,sizeof(x));
        vector<int>g[5007];
        cin>>n>>d;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(x[j]-x[i]<=d)
                {
                    g[i].push_back(j);
                    g[j].push_back(i);

                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            memset(cnt,0,sizeof(cnt));
            memset(dis,0x3f,sizeof(dis));
            dis[i]=0;
            cnt[i]=1;
            queue<int>q;
            q.push(i);
            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                for(auto v : g[u])
                {
                    if(dis[u]+1<dis[v])
                    {
                        dis[v]=dis[u]+1;
                        q.push(v);
                        cnt[v]=cnt[u];
                    }
                    else if(dis[u]+1==dis[v])
                    {
                        cnt[v]++;
                    }
                }
            }
            for(int j=i+1;j<=n;j++)
            {
                if(cnt[j]==2)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
