#include <bits/stdc++.h>
using namespace std;

int a[2000005];

void solve(){
    int n,d;
    cin>>n>>d;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }


    int ans=(a[n]-a[1])/d;
    cout<<ans<<endl;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c,t;
    cin>>c>>t;

    while(t--){
        solve();
    }
}