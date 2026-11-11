#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxN = 2e6+10;
ll n,d,a[5050],f[5050],g[5050];
void solve1(){
    cin>>n>>d;
    int ans = 0;
    for(int i = 1;i <= n;i++) cin>>a[i];
    for(int l = 1;l <= n;l++){
        for(int i = 1;i <= n;i++) f[i]=n+1,g[i]=0;
        f[l] = 0;g[l]=1;
        for(int r = l+1;r <= n;r++){
            for(int i = r-1;i >= l;i--){
                if(a[r]-a[i] > d) break;
                f[r] = min(f[r],f[i]+1);
            }
            for(int i = r-1;i >= l;i--){
                if(a[r]-a[i] > d) break;
                if(f[i] == f[r]-1){
                    if(g[i] >= 3) g[r] = 3;
                    else g[r] += g[i];
                }
            }
            if(g[r] == 2){
                ans++;
                //cout<<l<<' '<<r<<'\n';
            }
        }
    }
    cout<<ans<<'\n';
}
ll b[maxN];
void solve2(){
    cin>>n>>d;
    for(int i = 1;i <= n;i++) scanf("%lld",b+i);
    ll awa = b[2]-b[1];
    //cout<<n<<' '<<d<<' '<<awa<<' ';
    if(d >= awa*2){
        ll x = d/awa;
        if(x >= n-1) cout<<0<<'\n';
        else{
            ll ans = n-x-1;
            cout<<ans<<'\n';
        }
    }
    else cout<<0<<'\n';
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;cin>>c>>t;
    while(t--){
        if(c >= 1 && c <= 6) solve1();
        if(c == 11 || c == 12) solve2();
    }
    return 0;
}
