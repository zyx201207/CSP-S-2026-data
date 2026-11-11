#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int c,t;
ll n,d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    ll e = 0;
    while(t--){
        cin>>n>>d;
        cout<<(n+e)/2;
        e += n;
        e -= k;
    }
    return 0;
}
