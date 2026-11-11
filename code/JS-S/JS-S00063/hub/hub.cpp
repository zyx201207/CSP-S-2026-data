#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+9;
int n,k;


void solve(){
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
    }
    /*
    int l=0,r=n,ans;
    while(l<=r){
        if(check(mid)){
            r=mid-1;
            ans=mid;
        }
        else l=mid+1;
    }
    */
    n=n/2+1;
    cout<<n-k*3<<'\n';
}



signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int C,_;
    cin>>C>>_;
    while(_--){
        solve();
    }
    return 0;
}
