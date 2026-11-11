#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5;
int n;
long long d,dist[MAXN],cnt[MAXN],x[MAXN];
inline bool BFS(int u,int v)
{
    for(int i=1;i<=n;i++) dist[i]=INT_MAX,cnt[i]=0;
    struct node{int p,s;};
    queue<node> q;dist[u]=0,cnt[u]=1,q.push({u,0});
    while(!q.empty())
    {
        int p=q.front().p,s=q.front().s;q.pop();
        for(int i=p+1;i<=n&&x[i]-x[p]<=d;i++)
        {
            if(dist[i]==INT_MAX) dist[i]=s+1,q.push({i,s+1});
            if(s+1==dist[i]) cnt[i]+=cnt[p];
        }
        for(int i=p-1;i>=1&&x[p]-x[i]<=d;i--)
        {
            if(dist[i]==INT_MAX) dist[i]=s+1,q.push({i,s+1});
            if(s+1==dist[i]) cnt[i]+=cnt[p];
        }

    }
    return cnt[v]==2;
}
inline void dc()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>x[i];
    long long ans=0;
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++) ans+=BFS(i,j);
    cout<<ans<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;cin>>c>>t;
    while(t--) dc();
    return 0;
}
