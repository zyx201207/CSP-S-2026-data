#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,m;
    cin>>n>>m;
    while(m--){
        cout<<"0 ";
    }
}

signed main(){
    clock_t st=clock();

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cerr.tie(0);

    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    cerr<<"\n\n\n\n耗时:"<<(double)(clock()-st)*1000/CLOCKS_PER_SEC<<"ms";
}
