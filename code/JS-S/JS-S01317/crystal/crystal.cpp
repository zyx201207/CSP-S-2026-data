#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5 + 5;
int n, m, a[N];
int sum[N];

int find(int x){
    int l = 1, r = x - 1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(sum[x - 1] - sum[mid - 1] + m >= a[x] * (x - mid)){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return r + 1;
}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i - 1] + a[i];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int x = find(i);
        ans = max(ans, i - x + 1);
    }
    cout << ans << endl;

    return 0;
}