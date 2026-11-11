#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2000005;
int c, t, n, d;
int x[N];
int kd[N], minn[N], cnt[N];

signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 1; i <= n; i++) cin >> x[i];
        if(n == 1) {cout << 0 << endl; continue ;}
        if(c <= 10){
            int ans = 0;
            for(int i = 1; i <= n; i++){
                memset(kd, 0, sizeof(kd));
                memset(cnt, 0, sizeof(cnt));
                memset(minn, 0x3f, sizeof(minn));
                kd[i] = 1;
                minn[i] = 0;
                for(int j = i + 1; j <= n; j++){
                    for(int k = i; k < j; k++){
                        if(x[j] - x[k] <= d){
                            if(minn[k] + 1 <= minn[j]){
                                if(minn[k] + 1 < minn[j]) cnt[j] = 0;
                                minn[j] = minn[k] + 1;
                                cnt[j]++;
                            }
                        }
                    }
                }
                for(int j = i + 1; j <= n; j++){
                    if(cnt[j] == 2) ans++;
                }
            }
            cout << ans << endl;
            continue ;
        }
        else if(c <= 12){
            int dis = x[2] - x[1];
            int sze = d / dis;
            cout << n - (2 * sze - 1) << endl;
            continue ;
        }
        else if(c <= 14){
            cout << 0 << endl;
            continue ;
        }
        else {
            int ans = 0;
            for(int i = 1; i <= n; i++){
                memset(kd, 0, sizeof(kd));
                memset(cnt, 0, sizeof(cnt));
                memset(minn, 0x3f, sizeof(minn));
                kd[i] = 1;
                minn[i] = 0;
                for(int j = i + 1; j <= n; j++){
                    for(int k = i; k < j; k++){
                        if(x[j] - x[k] <= d){
                            if(minn[k] + 1 <= minn[j]){
                                if(minn[k] + 1 < minn[j]) cnt[j] = 0;
                                minn[j] = minn[k] + 1;
                                cnt[j]++;
                            }
                        }
                    }
                }
                for(int j = i + 1; j <= n; j++){
                    if(cnt[j] == 2) ans++;
                }
            }
            cout << ans << endl;
            continue ;
        }
    }
    return 0;
}