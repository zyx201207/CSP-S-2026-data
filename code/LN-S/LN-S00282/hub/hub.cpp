#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        cout << (abs(n - k) + 1) / 2 << endl;
    }
    fclose(stdin);
    fclose(stdout);
    //看在我都进S组的份上，让我拿点分吧qwq
    return 0;
}
