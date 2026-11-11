#include <bits/stdc++.h>
#define ll long long
#define MAXN 1e10
using namespace std;
ll c,t,n,k,u,v;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> c >> t;
    for(ll i = 1;i <= t;i++){
        cin >> n >> k;
        for(ll j = 1;j < n;j++){
            cin >> u >> v;
        }
        cout << k/2 << endl;
    }
    return 0;
}
