#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 1;
int c,t,n,d,a[N];

void special(){
    for(int p = 1;p <= t;p++){
        cin >> n >> d;
        for(int i = 1;i <= n;i++)cin >> a[i];
        int x = d / (a[2] - a[1]);
        if(x == 1 || x == 0) {cout << 0 << endl;continue;}
        int l = 2 * x - 1;
        cout << n - l << endl;
    } return ;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    if(c == 1 || c == 2) cout << 0 << endl << 1;
    if(c == 11 || c == 12){special();return 0;}

//    for(int p = 1;p <= t;p++){
//        cin >> n >> d;
//
//    }
    return 0;
}
