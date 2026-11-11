#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+7;
const int inf=0x3f3f3f3f3f3f3f3f;
int c,t,a[maxn],nxt[maxn],rnxt[maxn],n,d,tmp[maxn],tg[maxn];
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    a[n+1]=inf; a[0]=-inf;
    int curR=1;
    for(int i=1;i<=n;i++){
        while(a[i]+d>=a[curR]) curR++;
        nxt[i]=curR-1;
        if(nxt[i]==i+1){
            tmp[i]=1;
        }
    }
    int curL=n;
    for(int i=n;i>=1;i--){
        while(a[curL]+d>=a[i]) curL--;
        rnxt[i]=curL+1;
    }
    for(int i=n;i>=1;i--){
        if(nxt[i]!=i+1) continue;
        tmp[i]+=tmp[i+1];
    }
    // for(int i=1;i<=n;i++){
    //     cout<<nxt[i]<<" \n"[i==n];
    // }
    // for(int i=1;i<=n;i++){
    //     cout<<rnxt[i]<<" \n"[i==n];
    // }
    // for(int i=1;i<=n;i++){
    //     cout<<tmp[i]<<" \n"[i==n];
    // }
    // return;
    // nxt 为最远到的位置
    int ans=0;
    for(int i=1;i<=n;i++){
        int L=nxt[i];
        for(int j=nxt[i]+1;j<=n;j++){
            // cerr<<i<<' '<<j<<'\n';
            while(nxt[L]<j){
                L=nxt[L];
                if(L==nxt[L]&&L<j) break;
            }
            int cnt=0;
            for(int o=L;o>=L-2&&o>i&&o>0;o--){
                if(a[o]+d>=a[j]) cnt++;
            }
            if(cnt==2){
                ans++;
                if(nxt[L]==j) ans+=tmp[j];
                // cerr<<L<<' '<<i<<' '<<j<<'\n';
            }
        }
    }
    // cerr<<'\n';
    cout<<ans<<'\n';
    for(int i=1;i<=n+2;i++) tmp[i]=nxt[i]=a[i]=0;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>c>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
Part of my heart was left behind that day.
*/