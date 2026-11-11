#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
            f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
        x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*f;
}
void cmax(int &x,int y)
{
    x=max(x,y);
}
void cmin(int &x,int y)
{
    x=min(x,y);
}
void write(int x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        write(x/10);
    putchar('0'+x%10);
}
const int N=505,M=5e5+5;
int sub,n,m,ooo,tc,a[M],eg[N][N],dis[N][N],w[M];
bool vis[N];
#define pii pair<int,int>
vector<pii> v[M];
priority_queue<pii,vector<pii>, greater<pii> > q;
void dijk(int s)
{
    q.push({0,s});
    memset(vis,0,sizeof(vis));
    while(!q.empty())
    {
        int x=q.top().second;
        q.pop();
        if(vis[x])
            continue;
        vis[x]=1;
        for(int i=1;i<=n;i++)
        {
            if(dis[s][i]>dis[s][x]+eg[x][i])
            {
                dis[s][i]=dis[s][x]+eg[x][i];
                q.push({dis[s][i],i});
            }
        }
    }
}
int calc(int x,int y)
{
    int ans=1e18;
    for(auto [pp,tt]:v[x])
        for(auto [qq,rr]:v[y])
            cmin(ans,tt+dis[pp][qq]+rr);//,cout<<"D"<<x<<' '<<y<<' '<<pp<<' '<<qq<<' '<<tt<<' '<<rr<<endl;
    return ans;
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    sub=read(),n=read(),m=read(),ooo=read(),tc=read();
    memset(dis,0x3f,sizeof(dis));
    memset(eg,0x3f,sizeof(eg));
    for(int i=1;i<=m;i++)
    {
        w[i]=read();
    }
    for(int i=1,le,x;i<=n;i++)
    {
        le=read();
        for(int j=1;j<=le;j++)
        {
            a[j]=read();
            x=read();
            v[a[j]].push_back({i,x});
        }
        dis[i][i]=0,eg[i][i]=0;
    }
    for(int i=1,sz;i<=m;i++)
    {
        sz=v[i].size();
        for(int j=0,tox,px;j<sz-1;j++)
        {
            tox=v[i][j].first,px=v[i][j].second;
            for(int k=j+1,toy,py;k<sz;k++)
            {
                toy=v[i][k].first,py=v[i][k].second;
                cmin(eg[tox][toy],px+py);
                cmin(eg[toy][tox],px+py);
            }
        }
    }
    for(int i=1;i<=n;i++)
        dijk(i);
    while(tc--)
    {
        int x=read(),y=read();
        write(calc(x,y)+w[x]+w[y]);puts("");
    }
    return 0;
}
