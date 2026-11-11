#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+7,Q=1e5+7;                                                //remember change it!!!!!!!!!
int c,d,n,m,question,ans[N];
pair<pair<int,int>,int> ques[Q];


struct Node{
    int v,w;
};
vector<Node> v[N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
int dis[N];
bool vis[N];
void init(int s)
{
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s]=0;
}
void dij(int s,int t)
{
    q.push({dis[s],s});
    while(!q.empty())
    {
        int x=q.top().second;
        //cout<<x<<" ";
        q.pop();
        if(vis[x]==1) continue;
        vis[x]=1;
        for(Node u:v[x])
        {
            int to=u.v,w=u.w;
            if(dis[to]>dis[x]+w)
            {
                dis[to]=dis[x]+w;
                if(!vis[to])
                    q.push({dis[to],to});
            }
        }
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>question;
    for(int i=1;i<=m;i++)
    {
        int x;
        cin>>x;
        v[i].push_back({i+m,x});
        v[i+m].push_back({i,x});
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        int th=2*m+i;
        for(int j=1;j<=k;j++)
        {
            int x,t;
            cin>>x>>t;
            v[th].push_back({x+m,t});
            v[x+m].push_back({th,t});
        }
    }
    for(int i=1;i<=question;i++)
    {
        int x,y;
        cin>>x>>y;
        ques[i].second=i;
        ques[i].first=make_pair(x,y);
    }
    sort(ques+1,ques+question+1);
    for(int i=1;i<=question;i++)
    {
        int s=ques[i].first.first,t=ques[i].first.second;
        if(s!=ques[i-1].first.first) {
            init(s);
            dij(s,t);
        }
        ans[ques[i].second]=dis[t];
    }
    for(int i=1;i<=question;i++)
        cout<<ans[i]<<"\n";
    return 0;
}
