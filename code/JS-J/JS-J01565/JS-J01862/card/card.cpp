#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[500005], cnt = 0;
int mm[300005], rest[300005];
signed main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int j = 1; j <= n; j++){
        //memset(mm, -1, sizeof(mm));
        for (int i = j; i <= n; i++){
            if (mm[a[i]] == -1){
                mm[a[i]] = ++cnt;
            }
            else{
                for (int k = 1; k <= m; k++){
                    if (mm[k] > mm[a[i]]){
                        mm[k] = -1;
                    }
                }
                cnt = mm[a[i]];
            }
        }
        for (int i = 1; i <= m; i++){
            if (mm[i] != -1){
                rest[i]++;
                mm[i] = -1;
            }
        }
    }
    for (int i = 1; i <= m; i++){
        cout << rest[i] << ' ';
    }
    return 0;
}
