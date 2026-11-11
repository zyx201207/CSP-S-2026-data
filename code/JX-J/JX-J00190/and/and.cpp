#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N  = 1e6 + 10;
int a[N];
int pre[N];
int suf[N];
int n, m;
int ans;
void dfs(int i, int cnt, int now){
    if(cnt == m){
        ans = max(ans, now);
        return ;        
    }
    if(i > n){
        return ;
    }
    dfs(i + 1, cnt, now);
    if(cnt == 0) dfs(i + 1, cnt + 1, a[i]);
    else dfs(i + 1, cnt + 1, now & a[i]);
}
signed main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    pre[1] = a[1];
    suf[n] = a[n];
    if(n <= 20 && m <= n){
        dfs(1, 0, 1);
        cout << ans;
        return 0;
    }
    if(n <= 2000){
		if(m == 1){
			for(int i = 1;i <= n;i++){
                ans = max(ans, a[i]);
			}
            cout << ans;
            return 0;
		} else if(m == n){
            ans = a[1];
            for(int i = 2;i <= n;i++){
                ans &= a[i];
            }
            cout << ans;
            return 0;
        } else if(m == 2){
            for(int i = 1;i <= n;i++){
                for(int j = i + 1;j <= n;j++){
                    ans = max(ans, a[i] & a[j]);
                }
            }
            cout << ans;
            return 0;
        }
	} else {
        if(m == n - 1){
            for(int i = 2;i <= n;i++){
                pre[i] = pre[i - 1] & a[i];
            }
            for(int i = n - 1;i >= 1;i--){
                suf[i] = suf[i + 1] & a[i];
            }
            for(int i = 1;i <= n;i++){
                if(i == 1){
                    ans = max(ans, suf[i + 1]);
                } else if(i == n){
                    ans = max(ans, pre[i - 1]);
                } else {
                    ans = max(ans, suf[i + 1] & pre[i - 1]);
                }
            }
            cout << ans;
            return 0;
        } else {
            for(int i = 1;i <= n;i++){
                ans = max(ans, a[i]);
			}
            cout << ans;
            return 0;
        }
    }
    return 0;
}
