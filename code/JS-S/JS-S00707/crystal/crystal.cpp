#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500005], ans, sum, x, y;
bool t = true;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(i >= 3){
            if(a[i] - a[i - 1] != a[i - 1] - a[i - 2]){
                t = 0;
            }
        }
    }
    if(t){
        long long p = 0;
        while(m >= 0 && p <= a[n] - a[1]){
            p += a[2] - a[1];
            m -= p;
            ans++;
        }
        cout << ans;
        return 0;
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++){
        bool t = true;
        for(int j = 1; j <= n; j++){
            x = min(i, j), y = max(i, j);
            sum = 0;
            for(int k = x; k <= y; k++){
                sum += a[y] - a[k];
                if(sum > m){
                    t = false;
                    break;
                }
            }
            if(t){
                ans = max(ans, y - x + 1);
            }
            else{
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
