#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
typedef long long LL;
int c,n,m,d,p;
int w[N];
int g[N][30];
int cnt;
int head[N],Next[N*20],ver[N*20];
int edge[N*20];
void add(int a,int b,int c)
{
    ver[++cnt] = b;
    Next[cnt] = head[a];
    head[a] = cnt;
    edge[cnt] = c;
}
LL dist[N*20];
bool v[N];
priority_queue < pair < LL ,int > > q;
int  Dijkstra(int s,int t)
{
    memset(dist,0x3f ,sizeof dist);
    dist[s] =0;
    q.push({0,s});
    v[s] = 0;
    while(!q.empty())
    {
        int x = q.top().second;
        q.pop();
        if(v[x]) continue;
        v[x] = 1;
        for(int i = head[x];i;i = Next[i])
        {
            int y = ver[i];
            int z = edge[i];
            if(dist[y] > dist[x] + z) 
            {
                dist[y] = dist[x] + z;
                if(!v[y]) q.push({-dist[y],y});
            }
        }
    }
    return dist[t]  == 0x3f3f3f3f ? 0 : dist[t];
}
void work1()
{
    
    for(int i = 1;i<= m;i++) 
    {
        scanf("%d",&w[i]);
    }
    int f,t;
    for(int i = 1;i<= n;i++)
    {
        int sum ;
        scanf("%d",&sum);
        for(int i = 1;i<= sum;i++)
        {
            f,t;
            scanf("%d%d",&f,&t);
            add(f,m+i,t);
            add(m+i,f,t);
        }
    }
    for(int i = 1;i<= p;i++)
    {
        memset(v,0,sizeof v);
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%lld\n",1ll*Dijkstra(x,y)* t+ w[x]+ w[y]);
    }
    return ;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&p);
    
        work1();
    return 0;
}