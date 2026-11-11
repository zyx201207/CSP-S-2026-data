#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int x[N];
void solve(){
    int n,d;
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>x[i];
    int ca=x[2]-x[1];
    int mca=x[n]-x[1];
    int t=d*2-1;
    if((mca/ca)%2==1&&(mca/ca)!=1){
        if((mca/ca)<=x[n]){
            cout<<x[n]-(mca/ca)<<endl;
        }
    }else{
        cout<<0<<endl;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        solve();
    }
    return 0;
}
