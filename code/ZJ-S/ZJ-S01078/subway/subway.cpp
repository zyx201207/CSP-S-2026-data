#include<bits/stdc++.h>
#define getchar getchar_unlocked
using namespace std;typedef long long ll;
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
const int maxn=5e5+5,maxm=505;const ll linf=1e18;
inline int read(){
    char c;int f=1;for(c=getchar();c<'0'||c>'9';c=getchar())c=='-'&&(f=-1,0);
    int res=0;for(;c>='0'&&c<='9';c=getchar())
        res=(res<<1)+(res<<3)+(c^48);
    return res*f;
}
int testid,n,m,mxnum,Q,mor[maxn];vector<pair<int,int>>trs[maxn];
ll pre[maxm][maxm];
int main(){open(subway);
    testid=read(),m=read(),n=read(),mxnum=read(),Q=read();
    for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)pre[i][j]=(i==j?0ll:linf);
    for(int i=1;i<=n;i++)mor[i]=read();
    for(int i=1,len;i<=m;i++){
        len=read();
        for(int j=1,u,w;j<=len;j++){
            u=read(),w=read();
            trs[u].emplace_back(i,w);
        }
    }for(int u=1;u<=n;u++)
        for(const auto&[i,x]:trs[u])
            for(const auto&[j,y]:trs[u])
                pre[i][j]=min(pre[i][j],(ll)(x+y));
    for(int k=1;k<=m;k++)for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)
        pre[i][j]=min(pre[i][j],pre[k][i]+pre[k][j]);
    for(int i=1,u,v;i<=Q;i++){
        u=read(),v=read();if(u==v){puts("0");continue;}
        ll ans=linf;
        for(const auto&[i,x]:trs[u])
            for(const auto&[j,y]:trs[v])
                ans=min(ans,x+pre[i][j]+y+mor[u]+mor[v]);
        printf("%lld\n",ans);
    }
    return 0;
}