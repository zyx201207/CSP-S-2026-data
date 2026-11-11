#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
const int N = 2e5 + 10;
typedef long long ll;
int n, m;
ll a[N], ans = -1;

void init(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
}

void solve(){
    if(m == 2){
        for(int i = 1; i < n; ++i){
            for(int j = i + 1; j <= n; ++j){
                ans = max(ans, a[i] & a[j]);
            }
        }
        cout << ans << endl;
        return;
    }
    if(m == n){
        ans = a[1];
        for(int i = 2; i <= n; ++i)
            ans = ans & a[i];
        cout << ans << endl;
        return;
    }
    if(m == 1){
        sort(a + 1, a + 1 + n);
        ans = a[n];
        cout << ans << endl;
        return;
    }
    if(a[n] % 2 == 0){
            ans = a[n - 1];
        for(int i = 2; i <= m; ++i)
            ans = ans & a[n - i];
        cout << ans << endl;
        return;
    }
    if(m == n - 1){
        ll temp = 0;
        for(int i = 2; i <= n; ++i){
            ans = a[1];
            for(int j = 2; j <= n; ++j){
                if(i != j)
                    ans = ans & a[j];
            }
            ans = max(ans, temp);
            temp = ans;
        }
        cout << ans << endl;
        return;
    }
    sort(a + 1, a + 1 + n);
    ans = a[n - m + 1];
    cout << ans << endl;
}

int main(){
    init();
    solve();
    return 0;
}
