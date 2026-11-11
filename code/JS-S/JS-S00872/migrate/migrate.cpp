#include<bits/stdc++.h>
using namespace std;
long long op, t, n, d, a[2000010], ans, minn, cnt, p;
void dfs(long long x, long long y, long long s){
    if(cnt >= 3) return ;
    if(x >= y){
        if(s <= minn) cnt += 1;
        return ;
    }
    if(s >= minn) return ;
    if(a[y] - a[x] <= d) dfs(y, y, s + 1);
    else{
        long long p = x;
        while(a[p + 1] - a[x] <= d) p += 1;
        for(int i = max(x + 1, p - 2); i <= p; i++){
            if(a[i] - a[x] <= d) dfs(i, y, s + 1);
            else break;
        }
    }
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    cin >> op >> t;
    while(t--){
        cin >> n >> d;
        for(long long i = 1; i <= n; i++) cin >> a[i];
        ans = 0;
        for(long long l = 1; l <= n; l++){
            for(long long r = l + 1; r <= n; r++){
                minn = 0, cnt = 0, p = l;
                while(p < r){
                    if(a[p + 1] - a[p] > d) break;
                    long long p2 = p + 1;
                    while(p2 < r && a[p2 + 1] - a[p] <= d) p2 += 1;
                    minn += 1, p = p2;
                }
                if(p >= r){
                    dfs(l, r, 0);
                    ans += (cnt == 2);
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
