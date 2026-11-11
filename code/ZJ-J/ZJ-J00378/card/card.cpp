#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200010];
int loc[200010];
int val[200010];
int ans[200010];
int main () {
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        memset (loc, 0, sizeof (loc));
        int cnt = 0;
        for (int j = i; j <= n; ++j) {
            if (loc[i]) {
                for (int u = loc[i] + 1; u <= cnt; ++u) {
                    loc[val[u]] = 0;
                    val[u] = 0;
                }
                cnt = loc[i];
                
            } else {
                loc[i] = ++cnt;
                val[loc[i]] = i;
            }
            
        }
        for (int j = 1; j <= m; ++j) {
            if (loc[i]) {
                ++ans[i];
            }
        }
       
    }
    for (int i = 1; i <= m; ++i) {
        cout << ans[i] << endl;
    }
    
	fclose (stdin);
	fclose (stdout);
	return 0;
} 