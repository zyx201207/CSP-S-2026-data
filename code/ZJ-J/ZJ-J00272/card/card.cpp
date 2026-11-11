#include <bits/stdc++.h>

// #define int long long

using namespace std;

const int N = 5e5 + 10, M = 3e5 + 10; 
int a[N], pos[M];
int ans[M];
signed main() {

     freopen("card.in", "r", stdin);
     freopen("card.out", "w", stdout);
    cin.tie(0) -> ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    
    bool te_A = 1;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i > 1 && a[i] < a[i-1]) te_A = 0;
    }
    
	if (te_A) {
		for (int i = 1; i <= n; ++i) {
			memset(pos, 0, sizeof(pos));
	        for (int j = i; j <= n; ++j) {
	        	if (j == i || pos[a[j]] == 0) {
	                pos[a[j]] = j;
	                continue;
            	} else {
            		pos[a[j]] = j;
				}
			}
			for (int j = 1; j <= m; ++j) {
            	ans[j] += (pos[j] > 0);
        	}
		}
		for (int j = 1; j <= m; ++j) {
        	cout << ans[j] << ' ';
    	}
		return 0;
	}
	
	for (int i = 1; i <= n; ++i) {
		memset(pos, 0, sizeof(pos));
        for (int j = i; j <= n; ++j) {
            if (j == i || pos[a[j]] == 0) {
                pos[a[j]] = j;
                continue;
            }
            else {
                for (int k = 1; k <= m; ++k) {
                    if (j != k && pos[k] > pos[a[j]]) {
                        pos[k] = 0;
                    }
                }
                pos[a[j]] = j;
            }

        }
        for (int j = 1; j <= m; ++j) {
//        	cerr << j << ' ' << pos[j] << '\n';
            ans[j] += (pos[j] > 0);
        }
//		cerr << "\n\n\n\n";
	}
    
    for (int j = 1; j <= m; ++j) {
        cout << ans[j] << ' ';
    }

    cout << '\n';
    return 0;
}


