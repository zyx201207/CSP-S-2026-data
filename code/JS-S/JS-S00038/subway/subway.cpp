#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=505;
const int maxm=5e5+5;
const int inf=0x3f3f3f3f3f3f3f3f;

inline int read()
{
    char ch=getchar_unlocked(); int x=0;
    for(;!isdigit(ch);ch=getchar_unlocked());
    for(;isdigit(ch);ch=getchar_unlocked()) x=(x<<3)+(x<<1)+ch-'0';
    return x;
}
void write(int x)
{
    if(x>=10) write(x/10);
    putchar_unlocked(x%10+'0');
}

struct pqh {int a,t;};
int c,n,m,d,q;
int WW[maxm];
int g[maxn][maxn];
vector<pqh>lin[maxn];
vector<pqh>sta[maxm];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    memset(g,0x3f,sizeof(g));
    c=read(); n=read(); m=read(); d=read(); q=read();
    for(int i=1;i<=m;i++) WW[i]=read();
    for(int i=1;i<=n;i++)
    {
        int k=read();
        for(int j=1;j<=k;j++)
        {
            int a=read(),t=read();
            lin[i].push_back({a,t});
            sta[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++) g[i][i]=0;
    for(int i=1;i<=n;i++)
    {
        for(auto j:lin[i])
        {
            int a=j.a,t1=j.t;
            for(auto k:sta[a])
            {
                int b=k.a,t2=k.t;
                g[i][b]=min(g[i][b],t1+t2);
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    while(q--)
    {
        int ans=inf;
        int x=read(),y=read();
        for(auto i:sta[x])
        {
            for(auto j:sta[y])
            {
                ans=min(ans,i.t+j.t+g[i.a][j.a]);
            }
        }
        ans+=WW[x]+WW[y];
        write(ans); puts("");
    }
    return 0;
}
// won't surpass O_laf.
