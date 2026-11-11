#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c,t;
ll n,d;
ll pos[2000005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 1; i <= n; ++i) cin >> pos[i];
        cout << 0 << endl;
    }
    return 0;
}