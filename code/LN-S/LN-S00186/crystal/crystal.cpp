#include <bits/stdc++.h>
using namespace std;

long long a[500005], pref[500005];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio("false");
    cin.tie(0);
    int n;
    long long m;
    cin >> n >> m;
    if(n == 1){
        cout << 1;
        return 0;
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + a[i];
    }
    int ans = -1;
    for(int i = 2; i <= n; i++){
        long long sum = 0;
        sum = (i - 1) * a[i] - pref[i - 1];
        if(sum <= m){
            ans = i;
        }
    }
    cout << ans;
    return 0;
}
