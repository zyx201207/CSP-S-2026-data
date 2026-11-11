#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> PA;
const int N=5e2+10,M=5e5+10;
int c,n,m,ki[N],d,q,x,y,w[M],a[M],t[M];
struct Node{
    int v;
    ll len;
};
vector<Node> e[M];

ll dis[M];
bool f[M];
ll bfs()
{
    priority_queue<PA,vector<PA>,greater<PA>> q;
    memset(f,0,sizeof f);
    memset(dis,0x3f,sizeof dis);
    dis[x]=0;
    q.push({0,x});
    while(!q.empty()){
        int mi=q.top().second;
        q.pop();
        if(f[mi]) continue;
        else f[mi]=false;
        for(Node j:e[mi])
        {
            int to=j.v;
            if(dis[to]>dis[mi]+j.len)
            {
                dis[to]=dis[mi]+j.len;
                q.push({dis[to],to});
            }
        }
    }
    return dis[y];
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++) scanf("%d",&w[i]);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&ki[i]);
        for(int j=1;j<=ki[i];j++) scanf("%d%d",&a[j],&t[j]);
        for(int j=1;j<=ki[i];j++)
        {
            for(int k=1;k<=ki[i];k++)
            {
                if(j==k) continue;
                e[a[j]].push_back({a[k],t[j]+t[k]});
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d",&x,&y);
        ll ans=bfs()+w[x]+w[y];
        printf("%lld\n",ans);
    }
    return 0;
}
