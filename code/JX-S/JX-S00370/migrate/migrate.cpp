#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10;
int c,t,n,d,x[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 1;i <= n;i++){
            cin >> x[i];
        }
        int g = x[2] - x[1];
        if(2 * g > d){
            cout << 0 << endl;
            continue;
        }
        int s = d / g;
        cout << max(0ll,n - s - 1) << endl;
    }
    return 0;
}
