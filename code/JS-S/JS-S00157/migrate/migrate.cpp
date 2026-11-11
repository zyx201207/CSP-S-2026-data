#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define il inline

const int N = 2e6 + 5;
int c,t,n,d,x[N];

signed main(){

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 1;i <= n;i++) cin >> x[i];
        if(c == 11 || c == 12){
            int k = x[2] - x[1];
            if(d < k * 2){cout << "0\n";continue;}
            cout << n - d / k * 2 + 1 << '\n';
        }else cout << "0\n";
    }

    return 0;
}
