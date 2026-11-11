#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int c, t, n, d, f[5005][5005], cnt[5005][5005];
bitset<2000005> bs;

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> c >> t >> n >> d;
    while(t--){
        bs.reset();
        memset(cnt, 0, sizeof(cnt));
        memset(f, 0x3f, sizeof(f));
        for(int i = 1, x;i <= n;i++){
            cin >> x;
            bs[x] = 1;
            f[x][x] = 0;
        }
        for(int s = 1;s <= 5005;s++){
            if(bs[s]){
                for(int i = s + 1;i <= 5005;i++){
                    if(bs[i]){
                        for(int j = i + 1;j <= i + d;j++)
                            f[s][j] = min(f[s][j], f[s][i] + 1);
                    }
                }
            }
        }
        for(int s = 1;s <= 5005;s++){
            if(bs[s]){
                for(int i = s + 1;i <= 5005;i++){
                    if(bs[i]){
                        for(int j = i + 1;j <= i + d;j++){
                            if(bs[j] && f[s][j] == f[s][i] + 1)
                                cnt[s][j]++;
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 1;i <= 5005;i++){
            for(int j = i + 1;j <= i + d;j++)
                ans += (cnt[i][j] == 2);
        }
        cout << ans << '\n';
    }
    return 0;
}

