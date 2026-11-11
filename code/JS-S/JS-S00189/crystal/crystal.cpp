#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 500005;
int n, m;
int a[N];
int sec[N];

bool check(int k, int t){
    if(sec[t] - sec[k] - (k - 1) * (a[t] - a[k]) <= m) return true;
    else return false;
}

signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + n + 1);
    
    sec[0] = sec[1] = 0;
    for(int i = 2; i <= n; i++){
        sec[i] = sec[i - 1] + (a[i] - a[i - 1]) * (i - 1);
    }

    int ans = 1;
    for(int i = 1; i <= n; i++){
        int l = 1, r = i;
        int tmp = 1;
        while(l < r){
            int mid = (l + r) / 2;
            if(check(mid, i)){
                tmp = max(tmp, (i - mid + 1));
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
