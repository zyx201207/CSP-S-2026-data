#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    for(int i = 0; i < t; i++){
        int n, d;
        cin >> n >> d;
        int pos[n];
        for(int j = 0; j < n; j++){
            cin >> pos[j];
        }
        int ans = 0;
        for(int u = 0; u < n; u++){
            for(int v = u + 1; v < n; v++){
                int mi = 0;
                bool l = false;
                for(int step = 1; step <= d; step++){
                    if((pos[v] - pos[u]) % step == 0){
                        mi = min(mi, (pos[v] - pos[u]) / step);
                        
                    }else{
                        mi = min(mi, (pos[v] - pos[u]) / step+1);
                        l = true;
                    }
                }
                if(l) ans++;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}