#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, ans = 0;
int w[N], s[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> w[i];
    sort(w + 1, w + n + 1);
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + w[i];
    for(int i = 1; i <= n; i++){
        int t = 0;
        int l = i, r = n;
        while(l <= r){
            int mid = l + r >> 1;
            int now = (mid - i + 1) * w[mid] - (s[mid] - s[i - 1]);
            if(now > m){
                r = mid - 1;
            }else{
                l = mid + 1;
                t = mid - i + 1;
            }
        }
        ans = max(ans, t);
    }
    cout << ans << "\n";
    return 0;
}
