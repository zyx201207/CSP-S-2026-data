#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, l = 1, r = 1, ans = 1, cnt;
long long a[N], m, s[N], sum, c[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 2; i <= n; i++)c[i - 1] = a[i] - a[i - 1], s[i - 1] = s[i - 2] + c[i - 1];
    while(1){
        if(sum + ans * c[r] > m || r == n){
            break;
        }
        sum += ans * c[r];
        ans++;
        r++;
    }
    cnt = ans;
    while(r < n){
        l++, sum -= (s[r - 1] - s[l - 2]), cnt--;
        while(1){
            if(sum + cnt * c[r] > m || r == n){
                break;
            }
            sum += cnt * c[r];
            cnt++;
            r++;
        }
        ans = max(ans, cnt);
        if(r == n || l == r || l >= n - ans + 1)break;
    }
    cout << ans;
}
