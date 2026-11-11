#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5001;
int n;
ll m,a[N],f[N][N];
void solve(){
    ll a1,a2;
    cin>>a1>>a2;
    ll cz=abs(a1-a2);
    if(cz==0){
        cout<<n;
        return;
    }
    for(int i=1;i<=n;i++){
        if(1ll*cz*i*(i-1)/2>m){
            cout<<i-1;
            return;
        }
    }
    cout<<n;
    return;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    if(n>5000){
        solve();
        return 0;
    }
    memset(f,(ll)-1,sizeof(f));
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i][i]=0;
    }
    sort(a+1,a+n+1);
    for(int len=2;len<=n;len++){
        bool flag=0;
        for(int l=1;l+len-1<=n;l++){
            int r=l+len-1;
            if(f[l+1][r]==-1) continue;
            ll p=f[l+1][r]+a[r]-a[l];
            if(p>m) continue;
            flag=1;
            f[l][r]=p;
        }
        if(!flag){
            cout<<len-1;
            return 0;
        }
    }
    cout<<n;
    return 0;
}
