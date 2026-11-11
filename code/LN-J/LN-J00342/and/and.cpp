#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,m;
    cin>>n>>m;
    int a[n];
    for(auto &e:a){
        cin>>e;
    }
    sort(a,a+n);
    cerr<<a[n/2+(n&1)-1];
    cout<<a[n/2+(n&1)-1];
}

signed main(){
    clock_t st=clock();

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cerr.tie(0);

    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    cerr<<"\n\n\n\n耗时:"<<(double)(clock()-st)*1000/CLOCKS_PER_SEC<<"ms";
}
