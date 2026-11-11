#include<bits/stdc++.h>
using namespace std;
const long long MAX=1e17;
struct edge{
    long long we;
    long long to;
};
long long c,n,m,d,q;
long long w[505050];
long long dis[505050];
long long les[601][601];
bool intq[505050];
struct inq{
    long long no;
    bool operator  < ( const inq & oth ) const {
        return dis[no]>dis[oth.no];
    }
};
vector<edge> ed[505050];
void dij(long long st)
{
    priority_queue<inq> que;
    que.push({st});
    for(int i=1;i<=n+m;i++)
        dis[i]=MAX,intq[i]=false;
    dis[st]=0;
    while(!que.empty())
    {
        long long u=que.top().no;
        que.pop(),intq[u]=false;
        for(int i=0;i<ed[u].size();i++)
        {
            long long v=ed[u][i].to;
            if(dis[v]>dis[u]+ed[u][i].we)
            {
                dis[v]=ed[u][i].we+dis[u];
                if(!intq[v])
                {
                    que.push({v});
                    intq[v]=true;
                }
            }
        }
    }
    for(int i=m+1;i<=n+m;i++)
        les[st-m][i-m]=dis[i];
}
void find(long long st,long long en)
{
    long long ans=MAX;
    for(int i=0;i<ed[st].size();i++)
        for(int j=0;j<ed[en].size();j++){
            long long u=ed[st][i].to-m;
            long long v=ed[en][j].to-m;
            ans=min(ans,les[u][v]+ed[st][i].we+ed[en][j].we);
        }
    cout<<ans+w[st]+w[en]<<'\n';
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        long long k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            long long st,ti;
            cin>>st>>ti;
            ed[st].push_back({ti,m+i});
            ed[m+i].push_back({ti,st});
        }
    }
    for(int i=m+1;i<=m+n;i++)
        dij(i);
    for(int i=1;i<=q;i++)
    {
        long long a,b;
        cin>>a>>b;
        find(a,b);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
