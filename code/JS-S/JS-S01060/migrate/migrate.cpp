#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 2e6+6;

ll n,d,x[N],ri[N],le[N];
ll f[N],g[N],cnt[N];
ll lb[N],rb[N];

void solve(){
    cin>>n>>d;
    for (int i=1; i<=n; i++){
        lb[i]=n+1,rb[i]=0;
    }
    for (int i=1; i<=n; i++) cin>>x[i];
    for (int i=1,j=1; i<=n; i++){
        while (j+1<=n && x[j+1]-x[i]<=d) j++;
        ri[i]=j;
    }
    for (int i=n,j=n; i; i--){
        while (j-1>=1 && x[i]-x[j-1]<=d) j--;
        le[i]=j;
        lb[j]=min(lb[j],(ll)i);
        rb[j]=max(rb[j],(ll)i);
    }
    ll ans=0;
    for (int i=1; i<=n; i++){
        f[i]=g[i]=cnt[i]=0;
    }
    for (int i=1; i<=n; i++){
        if (ri[i]!=i){
            f[ri[i]]++;
            if (le[ri[i]]==i) f[ri[i]]+=f[i];
        }
    }
    for (int i=1; i<=n; i++) cnt[i]=0;
    for (int i=n; i; i--){
        if (le[i]!=i){
            g[le[i]]++;
            if (ri[le[i]]==i) g[le[i]]+=g[i];
        }
    }
    for (int i=1; i<=n; i++){
        int x=ri[i],y=ri[x];
        if (i==x || x==y) continue;
        if (le[y]==x-1 && le[x-1]==i){
            ans+=f[i]*g[y];
        }
    }
    for (int i=1; i<=n; i++){
        int x=ri[i],y=ri[x];
        if (i==x || x==y) continue;
        if (le[y]==x-1){
            ans+=g[y];
        }
    }
  //  for (int i=1; i<=n; i++){
 //       cout<<f[i]<<","<<g[i]<<"\n";
  //  }
    for (int i=1; i<=n; i++){
        int x=ri[i],y=ri[x];
        if (i==x || x==y) continue;
        if (le[x-1]==i){
            ll cnt=min(ri[x],rb[x-1])-max(x+1ll,lb[x-1])+1;
            ans+=f[i]*max(cnt,0ll);
        }
    }
    for (int i=1; i<=n; i++){
        int x=ri[i],y=ri[x];
        if (i==x || x==y) continue;
        ll cnt=min(ri[x],rb[x-1])-max(x+1ll,lb[x-1])+1;
        ans+=max(cnt,0ll);
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while (t--){
        solve();
    }
    return 0;
}

/*
- Read the problem statements carefully.
- int/long long/__int128.
- The memory limit: /usr/bin/time -v ./T1
- The time limit.
*/

// world.execute(me);