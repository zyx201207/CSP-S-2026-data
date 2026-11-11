#include<bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 5;

int n, ans;
long long m, a[maxn], s[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++){
        s[i] = s[i - 1] + a[i];
    }
    for(int i = 1; i <= n; i++){
        int l = 1, r = i;
        while(l < r){
            long long mid = (l + r + 1) / 2;
            if(a[i] * mid - (s[i] - s[i - mid]) <= m) l = mid;
            else r = mid - 1;
        }
        ans = max(ans, l);
    }
    cout << ans;
    return 0;
}

//Oct31==Dec25?
