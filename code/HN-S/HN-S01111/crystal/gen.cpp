#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("./crystal/cs.in","w",stdout);
    int n=5e5;ll m=1e18;cout<<n<<' '<<m<<'\n';
    ll c=-1e11;
    for(int i=1;i<=n;i++){
        c+=ll(1e7);cout<<c<<' ';
    }
    cout<<'\n';
    return 0;
}