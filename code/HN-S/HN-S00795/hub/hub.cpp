#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define all(v) v.begin(),v.end()
#define pb push_back
#define ppb pop_back
using namespace std;
inline void MAX(auto &x,auto y){x=max(x,y);}
inline void MIN(auto &x,auto y){x=min(x,y);}
const int N=1e6+5,inf=1e9;
int n,m,lim,d[N],len[N];
bool tag[N];
vector<int> e[N];
void col(int x,int F,int to)
{
    if(x==to)
        return void(tag[x]=1);
    tag[x]=0;
    for(auto y:e[x]) if(y^F)
        col(y,x,to),tag[x]|=tag[y];
}
int dfs(int x,int F)
{
    int ret=len[x]=0;
    for(auto y:e[x]) if(y^F)
        ret+=dfs(y,x),MAX(len[x],len[y]+1);
    return ret+(len[x]>=lim);
}
void dfs1(int x,int F)
{
    tag[x]=1;
    for(auto y:e[x])
        if(y^F&&!tag[y])
            dfs1(y,x);
}
bool check(int mid)
{
    lim=mid;
    for(int x=1;x<n;x++)
    {
        for(int y=x+1;y<=n;y++)
        {
            for(int i=1;i<=n;i++)
                tag[i]=0,d[i]=inf;
            col(x,0,y);
            int w=0;
            for(auto i:e[x])
                if(!tag[i]) w+=dfs(i,x);
            for(auto i:e[y])
                if(!tag[i]) w+=dfs(i,y);
            for(auto i:e[x])
                if(i^y&&tag[i]) dfs1(i,x);
            for(auto i:e[y])
                if(i^x&&tag[i]) dfs1(i,y);
            queue<int> q;
            q.push(x),q.push(y),d[x]=d[y]=0;
            while(q.size())
            {
                int u=q.front();
                q.pop();
                for(auto v:e[u])
                    if(tag[v]&&d[v]==inf)
                        d[v]=d[x]+1,q.push(y);
            }
            bool ck=1;
            for(int i=1;i<=n;i++)
                if(tag[i]) ck&=d[i]<=lim;
            if(ck&&w<=m-2) return 1;
        }
    }
    return 0;
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        e[i].clear();
    for(int i=1,x,y;i<n;i++)
        cin>>x>>y,e[x].pb(y),e[y].pb(x);
    int l=0,r=n-1,mid,ans=n-1;
    while(l<=r)
    {
        mid=l+r>>1;
        if(check(mid))
            ans=mid,r=mid-1;
        else l=mid+1;
    }
    cout<<ans<<'\n';
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int C,T;cin>>C>>T;
    while(T--) solve();
    return 0;
}