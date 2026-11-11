#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int c,t;
ll n,k;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    ll e = 1;
    while(t--){
        cin>>n>>k;
        cout<<e<<endl;
        ++e;
        if(!(t % 4)){
            e += n;
            e -= k;
        }
    }
    return 0;
}
