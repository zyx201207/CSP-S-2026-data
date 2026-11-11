#include<bits/stdc++.h>
#define int long long
#define N 2000005
using namespace std;
int c, t, n, d, x[N], f[N], dp[N];
int pre[N], nxt[N];
void get_pre(){
    for(int i = 1; i <= n; i++){
        if(i == 1){
            pre[i] = 1;
            continue;
        }
        else{
            pre[i] = i;
        }
        int l = 1, r = i - 1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(x[mid] + d >= x[i]){
                pre[i] = mid, r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
    }
}
void get_nxt(){
    for(int i = 1; i <= n; i++){
        if(i == n){
            nxt[i] = n;
            continue;
        }
        else{
            nxt[i] = i;
        }
        int l = i + 1, r = n;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(x[i] + d >= x[mid]){
                nxt[i] = mid, l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 1; i <= n; i++){
            cin >> x[i];
        }
        get_pre(), get_nxt();
        if(c <= 10){
            int cnt = 0;
            for(int i = 1; i <= n; i++){
                f[i] = 0, dp[i] = 1;
                for(int j = i + 1; j <= n; j++){
                    if(pre[j] == j){
                        break;
                    }
                    int pos = max(i, pre[j]), sum = dp[pos]; f[j] = f[pos] + 1;
                    for(int k = pos + 1; k <= j - 1 && k <= pos + 3; k++){
                        if(f[k] == f[pos]){
                            sum += dp[k];
                        }
                        else{
                            break;
                        }
                    }
                    if(sum > 5){
                        sum = 5;
                    }
                    if(sum == 2){
                        cnt++;
                    }
                    dp[j] = sum;
                }
            }
            cout << cnt << "\n";
            continue;
        }
        if(c == 11 || c == 12){
            if(x[n] - x[1] <= d){
                cout << 0 << "\n";
                continue;
            }
            int pos = 2 * nxt[1] - 3;
            if(pos < 3){
                cout << 0 << "\n";
                continue;
            }
            cout << max(0ll, n - pos) << "\n";
            continue;
        }
        if(c == 13 || c == 14){
            int pos = 0;
            for(int i = 1; i <= n; i++){
                if(nxt[i] - pre[i] + 1 == n){
                    pos = i;
                    break;
                }
            }
            if(x[n] - x[1] <= d){
                cout << 0 << "\n";
                continue;
            }
            int cnt = 0;
            for(int i = 1; i < pos; i++){
                if(nxt[i] - pos + 1 > 2){
                    continue;
                }
                if(nxt[i] == i){
                    continue;
                }
                if(nxt[i] - pos + 1 == 2){
                    if(pos == 1){
                        continue;
                    }
                    cnt += (n - nxt[pos - 1]);
                }
                if(nxt[i] - pos + 1 == 1){
                    if(pos == 2){
                        continue;
                    }
                    cnt += (nxt[pos - 1] - nxt[pos - 2]);
                }
            }
            cout << cnt << "\n";
            continue;
        }
    }
    return 0;
}
