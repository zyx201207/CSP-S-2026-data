#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 5e5 + 100;
int n, m;
int a[MAXN];
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    bool flag = 1;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    if(n > 2){
        int tmp = a[2] - a[1];
        for(int i = 3;i <= n;i++){
            if(a[i] - a[i - 1] != tmp){
                flag = 0;
                break;
            }
        }
    }
    if(flag){
        int ans = 0, sum = 0;
        for(int i = n;i >= 1;i--){
            sum += a[n] - a[i];ans++;
            if(sum > m){
                ans--;
                break;
            }
        }
        cout << ans << endl;
        return 0;
    }
    int ans = 0;
    for(int i = n;i >= 2;i--){
        int sum = 0, cnt = 0;
        for(int j = i;j >= 1;j--){
            sum += a[i] - a[j];
            cnt++;
            if(sum > m){
                cnt--;
                break;
            }
        }
        if(cnt > ans) ans = cnt;
    }
    if(ans < 1) cout << 1 << endl;
    else cout << ans << endl;
    return 0;
}
