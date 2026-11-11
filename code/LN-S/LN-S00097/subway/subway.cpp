#include<bits/stdc++.h>
#define int long long
#define inf 1e18
using namespace std;
inline int read()
{
    int c=0,w=1;
    char ch=getchar();
    while(ch>'9'||ch<'0')
    {
        if(ch=='-')w=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        c=(c<<1)+(c<<3)+ch-48;
        ch=getchar();
    }
    return w*c;
}
#define maxn 500100
#define maxm 510
int c,n,m,d,q;
int W[maxn];
struct node{int bel,val;};
vector<node>tag[maxn];
int f[maxm][maxm];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++)W[i]=read();
    for(int i=1;i<=n;i++)
    {
        int k=read();
        for(int j=1;j<=k;j++)
        {
            int v=read(),w=read();
            tag[v].push_back({i,w});
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i==j)f[i][j]=0;
            else f[i][j]=inf;
    for(int i=1;i<=m;i++)
    {
        if(tag[i].size()==1)continue;
        for(auto u:tag[i])
            for(auto v:tag[i])
                if(u.bel==v.bel)continue;
                else f[u.bel][v.bel]=f[v.bel][u.bel]=u.val+v.val;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    while(q--)
    {
        int l=read(),r=read();
        int ans=inf;
        for(auto i:tag[l])
            for(auto j:tag[r])
                ans=min(ans,f[i.bel][j.bel]+i.val+j.val);
        printf("%lld\n",ans+W[l]+W[r]);
    }
    return 0;
}
