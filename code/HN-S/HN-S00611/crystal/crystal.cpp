#include<bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int n;
long long m, a[N], s[N];

bool check(int l, int r, long long x){
    long long num = (x + 0ll) * (r - l + 1ll) - (s[r] - s[l - 1]);
    return num <= m;
}

int Find(int x, int y, long long num){
    if(!check(y, y, num)) return 0;
    int l = x, r = y + 1;
    while(l < r){
        int mid = (l + r) >> 1;
        check(mid, y, num) ? r = mid : l = mid + 1;
    }
    return y - l + 1;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++){
        s[i] = s[i - 1] + a[i];
    }
    int ans = 0;
    for(int i = 1, j = 1; i <= n; i = j){
        for(; j <= n && a[j] == a[i]; j++){
        }
        ans = max(ans, Find(1, i - 1, a[i]) + j - i);
    }
    cout << ans;
    return 0;
}
