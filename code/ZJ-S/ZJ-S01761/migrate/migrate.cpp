#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>v[2000005];
bool vis[2000005];
int c,t,n,d,x[2000005],di[2000005],s[2000005],ans=0;
void dij(int st)
{
    priority_queue<pair<int,int> >pq;
    for(int i=1;i<=n;i++) di[i]=1e18,vis[i]=0,s[i]=0;
    di[st]=0;
    s[st]=1;
    pq.push({0,st});
    while(!pq.empty())
    {
        int x=pq.top().second;
        pq.pop();
        if(vis[x]) continue;
        vis[x]=1;
        for(int y:v[x])
        {
            if(di[y]>di[x]+1)
            {
                di[y]=di[x]+1;
                s[y]=s[x];
                pq.push({-di[y],y});
            }
            else if(di[y]==di[x]+1) s[y]+=s[x];
        }
    }
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
            {
                if(x[j]-x[i]<=d)
                {
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
                else break;
            }
        ans=0;
        for(int i=1;i<=n;i++)
        {
            dij(i);
            for(int j=i+1;j<=n;j++)
            {
                if(s[j]==2) ans++;
            }
        }
        cout<<ans<<"\n";
        for(int i=1;i<=n;i++) v[i].clear();
    }
    return 0;
}
