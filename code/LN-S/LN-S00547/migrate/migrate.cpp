#include <bits/stdc++.h>
using namespace std;
int n,f[2000005],g[2000005],h[2000005],p[2000005];
long long d,a[2000005];
inline void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int L=i,R=n+1;
        while(L+1<R){
            int M=L+R>>1;
            if(a[M]-a[i]<=d){
                L=M;
            } else{
                R=M;
            }
        }
        p[i]=L;
    }
    for(int i=1;i<=n;i++){
        f[i]=g[i]=h[i]=0;
    }
    long long ans=0;
    for(int i=n;i>=1;i--){
        if(p[i]==i) continue;
        if(i>1&&p[i-1]!=p[i]){
            f[i]=f[p[i]]+p[i]-p[i-1];
        }
        if(i>1&&p[i]!=i+1&&p[i]==p[i+1]&&p[i-1]!=p[i]){
            g[i]=f[p[i]];
        }
        if(i>1&&p[i]!=i+1){
            g[i]+=p[i]-p[i-1];
        }
        if(i==1||p[i-1]!=p[i]){
            h[i]=h[p[i]];
        }
        if(i==1||p[i-1]<p[i]-1){
            h[i]+=g[p[i]-1];
        }
        ans+=h[p[i]]+g[p[i]-1];
    }
    cout<<ans<<'\n';
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,T;
    cin>>c>>T;
    while(T--){
        solve();
    }

    return 0;
}
