#include<bits/stdc++.h>
#define ll long long
#define il inline
#define gc getchar
#define pc putchar
using namespace std;
int read_int()
{
    int x=0,y=1;
    char ch=gc();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')y=-1;
        ch=gc();
    }
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=gc();
    }
    return x*y;
}
ll read_ll()
{
    ll x=0,y=1;
    char ch=gc();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')y=-1;
        ch=gc();
    }
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=gc();
    }
    return x*y;
}
void write_int(int x)
{
    if(x<0)
    {
        x=-x;
        pc('-');
    }
    if(!x)
    {
        pc('0');
        return;
    }
    char st[20];
    int tot=0;
    while(x)
    {
        st[++tot]=x%10+48;
        x/=10;
    }
    while(tot)pc(st[tot--]);
}
void write_ll(ll x)
{
    if(x<0)
    {
        x=-x;
        pc('-');
    }
    if(!x)
    {
        pc('0');
        return;
    }
    char st[20];
    int tot=0;
    while(x)
    {
        st[++tot]=x%10+48;
        x/=10;
    }
    while(tot)pc(st[tot--]);
}
const int M=5e5+5;
const ll INF=1e18;
int c,n,m,d,q;
ll w[M];
int tot,h[M],to[M<<1],ne[M<<1];
ll line[M<<1];
void add(int x,int y,ll z)
{
    tot++;
    ne[tot]=h[x];
    to[tot]=y;
    line[tot]=z;
    h[x]=tot;
}
int id[M];
int k;
vector<pair<int,ll> >e[M];
int b[M];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read_int();
    n=read_int();
    m=read_int();
    d=read_int();
    q=read_int();
    for(int i=1;i<=m;i++)w[i]=read_ll();
    for(int i=1;i<=n;i++)
    {
        k=read_int();
        for(int j=1;j<=k;j++)
        {
            int y=read_int();
            ll t=read_ll();
            e[y].push_back({i,t});
            b[y]++;
        }
    }
    int cnt=n;
    for(int i=1;i<=m;i++)
    {
        if(b[i]>1)
        {
            id[i]=++cnt;
            for(int j=0;j<(int)e[i].size();j++)
            {
                pair<int,ll>cur=e[i][j];
                int x=cur.first;
                int y=i;
                ll z=cur.second;
                add(x,id[y],z);
                add(id[y],x,z);
            }
        }
    }
    while(q--)
    {
        priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >q;
        vector<bool>vis(cnt+1,0);
        vector<ll>f(cnt+1,INF);
        int s=read_int();
        int t=read_int();
        ll sum=w[s];
        if(b[s]==1){sum+=e[s][0].second;s=e[s][0].first;}
        else s=id[s];
        f[s]=sum;
        ll ans=w[t];
        if(b[t]==1){ans+=e[t][0].second;t=e[t][0].first;}
        else t=id[t];
        q.push({f[s],s});
        vis[s]=1;
        while(!q.empty())
        {
            pair<ll,int>cur=q.top();
            int x=cur.second;
            q.pop();
            if(!vis[x])continue;
            vis[x]=0;
            for(int i=h[x];i;i=ne[i])
            {
                int y=to[i];
                if(f[y]>f[x]+line[i])
                {
                    f[y]=f[x]+line[i];
                    vis[y]=1;
                    q.push({f[y],y});
                }
            }
        }
        write_ll(f[t]+ans);
        pc('\n');
    }
    return 0;
}