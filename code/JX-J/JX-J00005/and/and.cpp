#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
int n, m;
int a[N];
int ans, mask;
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 30; i >= 0; i--){
        int cnt = 0;
        mask |= (1 << i);
        for(int j = 1; j <= n; j++){
            if((a[j] & mask) == mask){
                cnt++;
            }
        }
        if(cnt >= m) ans += (1 << i);
        else mask ^= (1 << i);
    }
    cout << ans;
    return 0;
}

