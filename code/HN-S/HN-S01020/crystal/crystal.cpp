#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e5 + 12;

int n, m, Arr[N], Sum[N], res;

void solve(){ cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> Arr[i];
    sort(Arr + 1, Arr + n + 1);
    for(int i = 1; i <= n; i ++) Sum[i] = Sum[i - 1] + Arr[i];
    for(int i = 1; i <= n; i ++){
        int l = 1, r = i, Ans = i;
        while(l <= r){
            int mid = l + r >> 1;
            if(Arr[i] * (i - mid + 1) - (Sum[i] - Sum[mid - 1]) <= m) Ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        res = max(res, i - Ans + 1);
    }
    cout << res << '\n';
}

signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T = 1;// cin >> T;
    while(T --) solve();
}