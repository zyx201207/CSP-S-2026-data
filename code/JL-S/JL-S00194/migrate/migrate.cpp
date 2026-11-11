#include <bits/stdc++.h>
#define endl "\n"
#define con continue
#define ret return
#define pb push_back
#define claer clear
#define rp(i,a,b) for(int i=(a);i<=(b);i++)
#define pr(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
#define int long long
#define N 500005
void out(){
    cout<<endl;
}
template<class X,class ...Y>
void out(X x,Y...y){
    cout<<x;
    if(sizeof...(y)>0) cout<<" ";
    out(y...);
}
int read(){
    int res=0,f=1;
    char c=getchar();
    if(!isdigit(c)){
        f=0;
        c=getchar();
    }
    for(;isdigit(c);c=getchar()){
        res=(res<<1)+(res<<3)+c-'0';
    }
    if(!f) res=-res;
    ret res;
}
int a[N];
int l[N];
int r[N];
int f[N];
int g[N];
int c[N];
int sum[N];
void solve(){
    int n,d;
    n=read();
    d=read();
    int L=1;
    rp(i,1,n){
        a[i]=read();
    }
    rp(i,1,n){
        while(L<=i){
            if(a[i]-a[L]<=d){
                break;
            }
            else{
                L++;
            }
        }
        l[i]=L;
    }
    int ans=0;
    for(int j=1;j<=n;j++){
        f[j]=0,sum[j]=1;
        c[0]=j;
        for(int i=j+1;i<=n;i++){
            f[i]=f[l[i]]+1;
            if(l[i]==i) break;
            int k=c[f[i]-1];
            g[i]=sum[k]-sum[l[i]-1];
            sum[i]=sum[i-1]+g[i];
            c[f[i]]=i;
            if(g[i]==2) ans++;
           // out(j,i,f[i],g[i],k);
        }
        rp(i,j,n) sum[i]=g[i]=f[i]=0;
        rp(i,0,n) c[i]=0;
    }
    out(ans);
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    c=read();
    t=read();
    while(t--) solve();
}
