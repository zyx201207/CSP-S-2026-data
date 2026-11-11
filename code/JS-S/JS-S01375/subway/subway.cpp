#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{

    int f=1,x=0;
    char c=getchar();
    while(c<'0'||c>'9'){if(c=='-'){f=-1;}c=getchar();}
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+c-'0',c=getchar();
    return f*x;
}
const int MAXN=5e5+9;
int c,n,m,d,q,w0[MAXN],dis0[1009][1009],dis[MAXN];
struct Node
{
    int v,w;
};
struct point
{
    int id,val;
};
vector<Node>e[MAXN*3];
vector<pair<int,int>>subw[MAXN];
point pq[MAXN*3];
int num,cnt;
bool vis[MAXN*3];
void cleaning()
{
    cnt=0;
    memset(dis,0x3f3f3f3f3f3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=num;i++)
    {
        pq[i]={0,0x3f3f3f3f3f3f};
    }
    num=0;
}
void challengeup(int idx)
{
    if(idx==1)
        return;
    int fa=(idx>>1);
    if(pq[fa].val>pq[idx].val)
    {
        swap(pq[fa],pq[idx]);
        challengeup(fa);
    }
}
point getmin()
{
    return pq[1];
}
void cleardown(int idx)
{
    pq[idx]={0,0x3f3f3f3f3f3f};
    int lson=(idx<<1),rson=(idx<<1)+1;
    if(pq[lson].id==0&&pq[rson].id==0)
        return;
    else if(pq[lson].id==0||pq[lson].val>pq[rson].val)
    {
        swap(pq[rson],pq[idx]);
        cleardown(rson);
    }
    else
    {
        swap(pq[lson],pq[idx]);
        cleardown(lson);
    }

}
void pushin(int x,int v)
{
    pq[++num]={x,v};
    challengeup(num);
    cnt++;
}
void popout()
{
    cnt--;
    cleardown(1);
}
void dijkstra(int pos)
{
    num=max(num,1LL*100);cleaning();
    pushin(pos,0);
    while(cnt>0)
    {
        point top=getmin();
        popout();
        vis[top.id]=true;
        dis[top.id]=top.val;
        for(auto i:e[top.id])
        {
            int v1=i.w+top.val;
            if(v1<dis[i.v]&&vis[i.v]==false)
            {
                dis[i.v]=v1;
                pushin(i.v,v1);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        dis0[pos-2*m][i]=dis[i+2*m];
    }
    /*
    cout<<endl<<pos<<endl;
    for(int j=1;j<=m*2+n;j++)
    {
        cout<<dis[j]<<" ";
    }cout<<endl;*/
}
//1~m station
//m+1~2m gate
//2m+1~2m+n subway
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read();n=read();m=read();d=read();q=read();
    for(int i=1;i<=m;i++)
    {
        int w;
        w=read();
        w0[i]=w;
        e[i].push_back({i+m,w});
        e[i+m].push_back({i,w});
    }
    for(int i=1;i<=n;i++)
    {
        int k=read(),pos=2*m+i;
        for(int j=1;j<=k;j++)
        {
            int x=read(),y=read();
            subw[x].push_back({pos,y});//!!!
            e[pos].push_back({x,y});
            e[x].push_back({pos,y});
        }
    }
    for(int pos=2*m+1;pos<=2*m+n;pos++)
    {
        dijkstra(pos);
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        x=read();y=read();
        int ans=0x3f3f3f3f3f3f;
        for(auto j:subw[x])
        {
            for(auto k:subw[y])
            {
                ans=min(ans,dis0[j.first-2*m][k.first-2*m]+j.second+k.second);
                //cout<<ans<<" "<<j.first-2*m<<" "<<k.first-2*m<<" "<<dis0[j.first-2*m][k.first-2*m]<<" "<<j.second+k.second<<endl;
            }
        }
        cout<<ans+w0[x]+w0[y]<<endl;
    }
    return 0;
}
