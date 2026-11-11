#include<bits/stdc++.h>
using namespace std;
using i64=long long;
template<class T>
void Cmin(T &x,const T& y){ x=(x<y?x:y); }
template<class T>
void Cmax(T &x,const T& y){ x=(x<y?y:x); }
const int N=2e6+5;
int n,nxt[N],pre[N];
i64 d,x[N],f[N],g[N];
void Work(){
    cin>>n>>d;
    for(int i=1;i<=n;++i) cin>>x[i];
    for(int i=1;i<=n;++i){
        nxt[i]=upper_bound(x+i,x+n+1,x[i]+d)-x-1;
        pre[i]=lower_bound(x+1,x+i+1,x[i]-d)-x;
    }
    nxt[n+1]=pre[n+1]=n+1;
    i64 ans=0;
    for(int u=n;u;--u){
        if(nxt[u]==u||nxt[u]==nxt[u-1]) f[u]=0;
        else f[u]=nxt[u]-max(nxt[u-1],u)+f[nxt[u]];
    }
    for(int u=1;u<=n;++u){
        if(pre[u]==u||pre[u]==pre[u+1]) g[u]=0;
        else g[u]=min(pre[u+1],u)-pre[u]+g[pre[u]];
    }
    for(int i=1;i<n;++i){
        int a=0,b=0;
        if(nxt[i]==nxt[i+1]) a=max(f[i]-(nxt[i]>=i+1&&nxt[i-1]<i+1),0ll);
        else if(nxt[i]>i+1) a=nxt[i]-max(nxt[i-1],i+1);
        if(pre[i]==pre[i+1]) b=max(g[i+1]-(pre[i+1]<=i&&pre[i+2]>i),0ll);
        else if(pre[i+1]<i) b=min(pre[i+2],i)-pre[i+1];
        ans+=1ll*a*b;
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int sid,T;
    cin>>sid>>T;
    while(T--) Work();
    fclose(stdin),fclose(stdout);
    return 0;
}