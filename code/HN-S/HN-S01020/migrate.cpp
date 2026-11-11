#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e6 + 12;

int c, n, d, Arr[N], lst[N], cnt[N], Sum[N];

void solve(){ cin >> n >> d;
    for(int i = 1; i <= n; i ++) cin >> Arr[i];
    if(c == 11 || c == 12){
        int x = Arr[2] - Arr[1];
        if(x >= d) cout << 0 << '\n';
        else{
            int y = d / x;
            cout << max(0ll, n - 2 * y + 1) << '\n';
        }
        return;
    }
    for(int i = 1; i <= n; i ++){
        int l = 1, r = i, Ans = i;
        while(l <= r){
            int mid = l + r >> 1;
            if(Arr[mid] + d < Arr[i]) l = mid + 1;
            else Ans = mid, r = mid - 1;
        }
        lst[i] = Ans;
    }
    int res = 0;
    for(int i = 1; i <= n; i ++){ Sum[i - 1] = 0; cnt[i] = 1; Sum[i] = 1;
        int Cnt = 1, lim = Arr[i] + d, r = i;
        for(int j = i + 1; j <= n; j ++){
            if(Arr[j] > lim){
                r = j - 1; lim = Arr[j - 1] + d; ++ Cnt;
                if(lim < Arr[j]) break;
            }
            int l = max(i, lst[j]);
            cnt[j] = Sum[r] - Sum[l - 1];
            // cerr << i << ' ' << j << ' ' << cnt[j] << '\n';
            if(cnt[j] == 2) ++ res;
            Sum[j] = Sum[j - 1] + cnt[j];
        }
    }
    cout << res << '\n';
}

signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T = 1; cin >> c >> T;
    while(T --) solve();
}