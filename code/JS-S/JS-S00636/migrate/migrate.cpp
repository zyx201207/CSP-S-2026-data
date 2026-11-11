#include<bits/stdc++.h>
using namespace std;
#define N 2000007
#define int long long
int n,m,t=0,ms=1<<62-1,mx=1<<62-1;
int a[N],sol[N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m>=3*(a[1]-a[2]))cout<<0;
    else if(a[2]==a[1]&&a[1]==a[3]) cout<<n-3;
    else{
        for(int i=2;i<n;i++){
            int v=ms;
            ms=min(ms,a[i+1]-a[i-1]);
            if(ms==a[i+1]-a[i-1]) mx=min(mx,v);
        }
        if(m>mx) cout<<0;
        else cout<<n-3;
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int T;
    cin>>T;
    cin>>T;
    for(int i=1;i<=T;i++) solve();
    return 0;
}
