#include<bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#define dbgblk if(1)
#else
#define dbgblk if(0)
#endif
#define dbg (cerr<<"["<<__LINE__<<"]:")
const int N=5005,inf=1e9;
int n;
using ll=long long;
ll d;
array<int,N>f,g;array<ll,N>x;
ll ans;
inline void dp(int s){
    for(int i=s;i<=n;++i)f[i]=inf,g[i]=0;
    int l=s;
    f[s]=0,g[s]=1;
    for(int i=s+1;i<=n;++i){
        while(x[i]-x[l]>d)++l;
        if(l==i)return;
        int t=f[l];
        int cnt=g[l];
        if(l+1<i&&f[l+1]==t)cnt+=g[l+1];
        if(l+2<i&&f[l+2]==t)cnt+=g[l+2];
        if(cnt>2)g[i]=3;else g[i]=cnt;
        f[i]=t+1;
        if(g[i]==2)++ans;
    }
}
inline void sol(){
    ans=0;
    cin>>n>>d;
    for(int i=1;i<=n;++i)cin>>x[i];
    for(int i=1;i<=n;++i)dp(i);
    cout<<ans<<'\n';
}
int main(){
    freopen("migrate.in","r",stdin);
    dbgblk{freopen("migrate.err","w",stderr);}
    freopen("migrate.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    int c,T;cin>>c>>T;
    while(T--)sol();
    return 0;
}
