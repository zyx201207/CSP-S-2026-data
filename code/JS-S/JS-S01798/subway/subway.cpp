#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 500005
#define M 505
#define pii pair<ll,ll>
#define fi first
#define se second
ll read(){
    ll x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')
        ch=getchar();
    while(ch>='0'&&ch<='9')
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return x;
}
ll c,n,m,q,w[N],u,v,t,d[M][M],ans;
vector<pii>E[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),c=read(),q=read();
    for(int i=1;i<=m;i++)w[i]=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)d[i][j]=1e18;
        d[i][i]=0;
        c=read();
        for(int j=1;j<=c;j++){
            u=read(),t=read();
            E[u].push_back({t,i});
        }
    }
    for(int i=1;i<=m;i++){
        for(auto &&u:E[i])
        for(auto &&v:E[i])
        d[u.se][v.se]=min(d[u.se][v.se],u.fi+v.fi);
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    while(q--){
        ans=1e18; u=read(),v=read();
        for(auto &&i:E[u])
            for(auto &&j:E[v])
                ans=min(ans,i.fi+j.fi+d[i.se][j.se]);
        printf("%lld\n",ans+w[u]+w[v]);
    }
    return 0;
}
