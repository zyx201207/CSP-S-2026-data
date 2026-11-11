#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T;

const int N=2e6+5;
int n,d,ans;
int a[N],L[N],R[N];
int sumL[N],sumR[N];
void solve(){
    cin>>n>>d;
    ans=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    int l=1,r=n;
    for(int i=1;i<=n;i++) {
        while(a[i]-a[l]>d) l++;
        L[i]=l-1;
    }
    for(int i=n;i>=1;i--) {
        while(a[r]-a[i]>d) r--;
        R[i]=r+1;
    }
    // for(int i=1;i<=n;i++) {
    //     cerr<<L[i]<<' '<<R[i]<<'\n';
    // }
    for(int i=1;i<=n;i++) {
        int l0=L[i]+1;
        if(l0==i) {sumL[i]=1;continue;}
        if(l0==i-1) {sumL[i]=sumL[i-1]+1;continue;}
        if(L[l0+1]==L[l0]) sumL[i]=i-l0+1;
        else sumL[i]=sumL[l0]+i-l0-sumL[L[l0+1]];
    }
    for(int i=n;i>=1;i--) {
        int r0=R[i]-1;
        if(r0==i) {sumR[i]=1;continue;}
        if(r0==i+1) {sumR[i]=sumR[i+1]+1;continue;}
        if(R[r0-1]==R[r0]) sumR[i]=r0-i+1;
        else sumR[i]=sumR[r0]+r0-i-sumR[R[r0-1]];
    }
    // for(int i=1;i<=n;i++) cerr<<sumL[i]<<' '<<sumR[i]<<'\n';
    for(int i=1;i<=n;i++) {
        if(R[L[i]]==i) {
            ans+=sumL[L[i]]*sumR[i];
            // cerr<<i<<' '<<ans<<'\n';
        }
    }
    cout<<ans<<'\n';
    
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);    
    cin>>c>>T;
    while(T--){
        solve();
    }
    return 0;
}