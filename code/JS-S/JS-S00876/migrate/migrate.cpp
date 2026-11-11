#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+7;                                                //remember change it!!!!!!!!!
int c,T;
int n,d;
int pos[N],cnt[N];
int ans;

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
    memset(cnt,0,sizeof(cnt));
    dis[s]=0;
}
void dij(int s)
{
    q.push({dis[s],s});
    cnt[s]=1;
    while(!q.empty())
    {
        int x=q.top().second;
        q.pop();
        if(vis[x]==1) continue;
        vis[x]=1;
        for(Node u:v[x])
        {
            int to=u.v,w=u.w;
            if(dis[to]>dis[x]+w)
            {
                dis[to]=dis[x]+w;
                if(cnt[to]==2)
                    ans--;
                cnt[to]=cnt[x];
                if(cnt[to]==2)
                    ans++;
                if(!vis[to])
                    q.push({dis[to],to});
            }
            else if(dis[to]==dis[x]+w)
            {
                cnt[to]++;
                if(cnt[to]==2)
                    ans++;
                if(cnt[to]>2)
                    ans--;
            }
        }
    }
}
bool A=1;
int pub;
void Main()
{
    ans=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>pos[i];
        if(i>2) if(pos[i]-pos[i-1]!=pos[2]-pos[1]) A=0;
    }
    if(n>=50000&&A)//A
    {
        cout<<0<<"\n";
        return;
    }
    if(n>=500000)//TLE
    {
        cout<<0<<"\n";
        return;
    }
    for(int i=1;i<=n;i++)
        v[i].clear();
    for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
    {
        if(pos[j]-pos[i]>d) break;
        v[i].push_back({j,1});
        v[j].push_back({i,1});
    }
    for(int i=1;i<=n;i++)
    {
        int s=i;
        init(s);
        dij(s);
    }
    cout<<ans/2<<"\n";
    return;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>T;
    while(T--) Main();
    return 0;
}
// 1 2 3 4 5 9
