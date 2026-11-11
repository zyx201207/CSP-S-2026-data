#include <bits/stdc++.h>
using namespace std;
namespace chennie_bless_me{
typedef long long ll;
typedef long double ld;
typedef __int128 i128;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
namespace fastio{
    const int BUFSZ=1<<20;
    char buf[BUFSZ],*p1=buf,*p2=buf,ch; int sgn;
    #define gc() ((p1==p2&&(p1=buf,p2=p1+fread(buf,1,BUFSZ,stdin))),(p1==p2?EOF:*p1++))
    template<typename T>
    inline void read(T &x){
        x=0; sgn=0; ch=gc();
        while(!isdigit(ch)){
            if(ch=='-') sgn=1;
            ch=gc();
        }
        while(isdigit(ch)){
            x=x*10+(ch-'0');
            ch=gc();
        }
        if(sgn) x=-x;
    }
    #undef gc
}
using fastio::read;
template<typename T>
inline void chmax(T &a,T b){
    if(a<b) a=b;
}
template<typename T>
inline void chmin(T &a,T b){
    if(b<a) a=b;
}
const int N=2e6+5;
int testcase,T;
int n;
ll d,x[N],f[N],pre[N],g[N];
void solve(){
    x[0]=-4e18;
    read(n); read(d);
    for(int i=1;i<=n;i++){
        read(x[i]);
        f[i]=g[i]=0;
    }
    ll ans=0;
    for(int i=1,j=1;i<=n;i++){
        pre[i]=pre[i-1];
        for(;x[i]-x[j]>d;j++);
        g[i]=i-j+1;
        // cout<<"?"<<i<<' '<<j<<'\n';
        if(i==j) continue;
        if(i==j+1){
            f[i]=f[i-1];
            g[i]=g[i-1]+1;
        }
        else{
            int p=lower_bound(x+1,x+j+1,x[j]-d)-x;
            int q=lower_bound(x+1,x+j+1,x[j+1]-d)-x;
            int r=lower_bound(x+1,x+j+1,x[j+2]-d)-x;
            f[i]=pre[q-1]-pre[p-1];
            if(q!=r){
                f[i]+=g[r-1];
                if(q+1<r||p!=q) f[i]-=g[q-1];
            }
            if(p!=q) g[i]+=g[q-1];
            // cout<<"#"<<i<<' '<<j<<' '<<p<<' '<<q<<' '<<r<<'\n';
        }
        ans+=f[i];
        pre[i]+=f[i];
    }
    cout<<ans<<'\n';
    // for(int i=1;i<=n;i++) cout<<f[i]<<' ';cout<<'\n';
    // for(int i=1;i<=n;i++) cout<<g[i]<<' ';cout<<'\n';
}
void main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    read(testcase);
    read(T);
    while(T--) solve();
}
}
int main(){
    assert(freopen("migrate.in","r",stdin));
    assert(freopen("migrate.out","w",stdout));
    chennie_bless_me::main();
    return 0;
}
// gg