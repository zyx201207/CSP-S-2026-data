#include<bits/stdc++.h>
using namespace std;

const int N=510,M=5e5+10,INF=0x3f3f3f3f,NINF=0xc0c0c0c0;
int c,n,m,d,Q;
int w[N],t[N][M],dis[M],k[N],a[N][M],ans[M];
vector<int> on[N],belong[M];
bool vis[M];
struct node
{
    int d,u,nowp;
    bool operator<(const node& rhs)const{return d<rhs.d;}
};
inline int read()
{
    char c=getchar();
    bool sign=0;
    int p=0;
    while(c<'0'||c>'9') sign=(c=='-'),c=getchar();
    while(c>='0'&&c<='9') p=(p<<3)+(p<<1)+c-'0',c=getchar();
    return (sign?-p:p);
}
void dijkstra(int s,int sp,int T)
{
    memset(ans,INF,sizeof ans),memset(dis,INF,sizeof dis),memset(vis,false,sizeof vis);
    priority_queue<node> pq;
    dis[s]=t[sp][s],pq.push({-dis[s],s,sp});
    while(!pq.empty())
    {
        node x=pq.top();
        pq.pop();
        int u=x.u,d=x.d,nowp=x.nowp;
        if(vis[u]) continue;
        vis[u]=1;
        for(auto p:belong[u])
        {
            for(auto v:on[p])
            {
                if(v==u) continue;
                if(nowp==p)
                {
                    dis[v]=min(dis[v],-d);
                    ans[v]=dis[v]+t[p][v];
                    pq.push({-dis[v],v,p});
                }
                else if(dis[v]>dis[u]+t[nowp][u]+t[p][u])
                {
                    dis[v]=min(-d+t[nowp][u]+t[p][u],dis[v]);
                    ans[v]=dis[v]+t[p][v];
                    pq.push({-dis[v],v,p});
                }
            }
        }
    }
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),Q=read();
    for(int i=1;i<=m;i++) w[i]=read();
    for(int p=1;p<=n;p++)
    {
        k[p]=read();
        for(int i=1;i<=k[p];i++)
        {
            a[p][i]=read();
            belong[a[p][i]].push_back(p);
            t[p][a[p][i]]=read();
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k[i];j++)
        {
            on[i].push_back(a[i][j]);
        }
    }
    while(Q--)
    {
        int S,T,ansn=-1;
        S=read(),T=read();
        for(auto p:belong[S])
        {
            dijkstra(S,p,T);
            ansn=max(w[S]+ans[T]+w[T],ansn);
            cout<<ansn<<"\n";
        }
    }
    return 0;
}
