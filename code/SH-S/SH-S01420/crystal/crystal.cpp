#include<bits/stdc++.h>
using namespace std;

bool Mbe;

#define ll long long
const int N=5e5+5;

ll n,m;
ll a[N],sum[N];
bool check(ll k){
    for(int i=n;i>=k;i--){
        if(m>=(a[i]*k-(sum[i]-sum[i-k]))){
            return 1;
        }
    }
    return 0;
}


void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    
    ll l=1,r=n,ans=0;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(check(mid)){
            ans=max(ans,mid);
            l=mid+1;
        }
        else r=mid-1;
    }

    cout<<ans<<"\n";
    return;
}

bool Med;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T=1;
    while(T--){
        solve();
    }

    // cerr<<fabs(&Mbe-&Med)/1024.0/1024.0<<"MB\n";
    // cerr<<ceil(clock()*1000.0/CLOCKS_PER_SEC)<<"ms\n";

    return 0;
}