#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n, m;
ll a[500005];
ll b[500005];
ll ans = 1;

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++){
        //cout << a[i] << ' ';
        b[i] = a[i] - a[i - 1];
    }
    //for(int i = 1; i <= n; i++){
    //    cout << b[i] << ' ';
    //}
    ll i = 1, j = 1, tmp = 0, tmp2 = 0;
    while(j <= n){
        if(b[j + 1] * (j - i + 1) + tmp <= m){
            tmp += b[j + 1] * (j - i + 1);
            tmp2 += b[j + 1];
            j++;
        }
        else{
            tmp -= tmp2;
            tmp2 -= b[i + 1];
            i++;
        }
        //cout << i << ' ' << j << endl;
        ans = max(ans, j - i + 1);
    }
    cout << ans;
}
