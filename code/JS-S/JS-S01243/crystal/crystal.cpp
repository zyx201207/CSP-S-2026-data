#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int N = 5e5 + 10;

ll n, m;
ll a[N];

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ll sum = 0;
        ll k = 1;
        for(int j = i - 1; j >= 1; j--){
            if((a[i] - a[j]) + sum <= m){
                sum += a[i] - a[j];
                k++;
                ans = max(ans, k);
            }
            else break;
        }
    }
    cout << ans << "\n";
    return 0;
}
