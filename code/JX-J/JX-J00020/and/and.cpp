#include<bits/stdc++.h>
using namespace std;
int n, m;
long long a[200010];
long long ans;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    if(m == 1){
        for(int i = 1; i <= n; ++i){
            ans = max(ans, a[i]);
        }
        cout << ans << '\n';
        return 0;
    }
    if(m == 2){
        for(int i = 1; i <= n; ++i){
            for(int j = i + 1; j <= n; ++j){
                ans = max(ans, a[i] & a[j]);
            }
        }
        cout << ans << '\n';
        return 0;
    }
    if(m == n && n != 1){
        ans = a[1];
        for(int i = 2; i <= n; ++i){
            ans &= a[i];
        }
        cout << ans << '\n';
        return 0;
    }
    return 0;
}
