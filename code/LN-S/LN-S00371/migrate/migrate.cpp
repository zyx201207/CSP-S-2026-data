#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define db cerr<<"fff"<<'\n';
/*
max_element()
accumulate()
priority_queue
*/

signed main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c,t;
    cin >> c >> t;
    while(t--) {
        int n,d;
        cin >> n >> d;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int flag = 0;
            for (int j = i+1; j < n; j++) {
                if (a[j]-a[j-1]>d)break;
                if (j < i+2 && j-a[j-2] <= d){
                    ans++;
                    flag = 1;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
