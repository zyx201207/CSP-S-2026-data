#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=5005;

ll c,t,n,d;
ll x[N];

int nxt[N];

void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>x[i];
    for(int i=1,j=1;i<=n;i++){
        while(j<=n&&(x[j]-x[i]<=d)) j++;
        nxt[i]=j-1;
    }
    ll ans=0;
    for(int j=3;j<=n;j++){
        int f=0;
        for(int k=j-3;k>=1;k=nxt[k]){
            int end=min(j,nxt[nxt[k]]);
            if(nxt[k]<=k+1||nxt[k]>j) continue;
            if(nxt[nxt[k]-1]>=end&&nxt[nxt[k]-2]<end) f++;
        }
        if(f==1) ans++;
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("migrate3.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--) solve();
    return 0;
}