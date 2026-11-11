#include<bits/stdc++.h>
using namespace std;
long long read()
{
    long long x=0;
    short f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')  f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
void wit(long long x)
{
    if(x<=9)    putchar(x+'0');
    else{
        wit(x/10);
        putchar(x%10+'0');
    }
}
void write(long long x,bool enld)
{
    if(x>=0)    wit(x);
    else{
        putchar('-');
        wit(-x);
    }
    if(enld)    putchar('\n');
    else    putchar(' ');
}


const int N=6e5+3;
const long long INF=((long long )1<<60);
struct node{
    int u;
    long long vic;
};
struct Node{
    int idx;
    long long vic;
    bool operator < (const Node& nxt) const {
        return vic > nxt.vic;
    }
};
struct xunwen{
    int u,v,idx;
}xw[N];
bool cmp(xunwen x,xunwen y)
{
    return x.u<y.u;
}
long long n,c,m,d,q,w[N];
vector<node>e[N];
priority_queue<Node>Q;
long long dis[N];
bool vis[N];
bool fnd[N];//shi fou ji suan i de dij
long long ans[N];
void dij(int s)
{
    for(int i=1;i<=n+m;i++) dis[i]=INF;
    for(int i=1;i<=n+m;i++) vis[i]=false;
    dis[s]=0;
    Q.push((Node){s,dis[s]});
    while(Q.size()!=0)
    {
        Node x=Q.top();
        Q.pop();
        int nw=x.idx;
        if(vis[nw]) continue;
        vis[nw]=true;
        for(auto ed:e[nw])
        {
            if(dis[ed.u]>dis[nw]+ed.vic)
            {
                dis[ed.u]=dis[nw]+ed.vic;
                Q.push((Node){ed.u,dis[ed.u]});
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read();n=read();m=read();d=read();q=read();
    for(int i=1;i<=m;i++)   w[i]=read();
    for(int i=1;i<=n;i++)
    {
        long long k;
        k=read();
        for(int j=1;j<=k;j++)
        {
            long long a,t;
            a=read();t=read();
            e[a].push_back((node){i+m,t});
            e[i+m].push_back((node){a,t});
        }
    }
    for(int i=1;i<=q;i++)
    {
        int u,v;
        u=read();v=read();
        if(u>v) swap(u,v);//u<v is true
        fnd[u]=1;
        xw[i]=(xunwen){u,v,i};
    }
    sort(xw+1,xw+1+q,cmp);
    /*for(int i=1;i<=q;i++)
    {
        cout<<xw[i].u<<' '<<xw[i].v<<endl;
    }*/
    int j=1;
    for(int i=1;i<=m;i++)
    {
        if(!fnd[i]) continue;
        dij(i);
        while(j<=q&&xw[j].u==i)
        {
            ans[xw[j].idx]=dis[xw[j].v]+w[i]+w[xw[j].v];
            j++;
        }
        if(j>q) break;
    }
    for(int i=1;i<=q;i++)
    {
        write(ans[i],1);
    }
    return 0;
}
