#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
struct Edge
{
    int to,next,w;
}edge[N];
int head[N],tot;int c,n,m,d,q;
void init()
{
    for(int i=0;i<=m;i++)
    {
        head[i]=edge[i].to=edge[i].next=edge[i].w=-1;
    }
}
void addedge(int u,int v,int w)
{
    tot++;
    edge[tot].to=v;
    edge[tot].next=head[u];
    edge[tot].w=w;
    head[u]=tot;
}
int hao[N];
int x,y;

struct Node
{
    int dis,pos;
    bool operator <(const Node &x)const
    {
        return x.dis<dis;
    }
};
int ans[N];
bool f[N];
int dij()
{
    memset(f,0,sizeof(f));
    memset(ans,0x3f,sizeof(ans));
    priority_queue<Node>q;
    q.push({x,0});
    ans[x]=0;
    while(!q.empty())
    {
        Node dd=q.top();
        q.pop();
        int pos=dd.pos,dis=dd.dis;
        if(f[pos])continue;
        f[pos]=1;
        for(int i=head[pos];~i;i=edge[i].next)
        {
            if(i==0)break;
            int y=edge[i].to;
            if(ans[y]>ans[pos]+edge[i].w)
            {
                ans[y]=ans[pos]+edge[i].w;
                if(!f[y])
                {
                    q.push({ans[y],y});
                }
            }
        }
    }
    return ans[y];
}



int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
    {
        int w;
        scanf("%d",&w);
        addedge(i,i+m,w);
        addedge(i+m,i,w);
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++)
        {
            int tim;
            scanf("%d%d",&hao[j],&tim);
            addedge(2*m+(hao[j]-1)*d+1,m+hao[j],tim);
            addedge(m+hao[j],2*m+(hao[j]-1)*d+1,tim);
            if(j>=1)
            {
                addedge(2*m+(hao[j]-1)*d+1,2*m+(hao[j-1]-1)*d+1,0);
                addedge(2*m+(hao[j-1]-1)*d+1,2*m+(hao[j]-1)*d+1,0);
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",dij());
    }
    return 0;
}
