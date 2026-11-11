#include<iostream>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
ll n,m;
const int N = 500010;
ll a[N];
ll sum, ans, mn_num, mn_id, mn = 1e18;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    sum += m;
    sum /= n;
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++){
        int cnt = sum - a[i];
        if(cnt < 0) cnt *= -1;
        if(cnt <= mn) {
            mn = cnt;
            mn_num = a[i];
            mn_id = i;
        }
    }
    sort(a + 1, a + mn_id + 1, greater<ll>());
    for(int i = 1; i <= mn_id; i++){
        if(a[i] == mn_num) ans++;
        else if((a[i] < mn_num) && (m >= (mn_num - a[i]))){
            ans++;
            m -= (mn_num - a[i]);
        }
    }
    cout << ans;
    return 0;
}
