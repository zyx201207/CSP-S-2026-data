#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+5;
ll n,d,x[N];
void solve(){
    cin>>n>>d;
    if(n<=3){cout<<"0\n";return;}
    for(int i=1;i<=n;++i)cin>>x[i];
    bool A=true;
    for(int i=2;i<n;++i)if(x[i]-x[i-1]!=x[i+1]-x[i]){A=false;break;}
    if(A){
        ll can=d/(x[2]-x[1]);
        if(can<=1||2*can-1>=n){cout<<"0\n";return;}
        else cout<<n-(2*can-1)<<"\n";
    }
    return;
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,_;cin>>c>>_;
    while(_--)solve();
    return 0;
}
