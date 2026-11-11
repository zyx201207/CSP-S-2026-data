#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXX = 2e6 + 5;

int t, sum[MAXX], num[MAXX], vis[MAXX], ans, a[MAXX], n, d, op, tot, flag[MAXX];

int Get_L(int x){
    int l = x, r = n, id;
    while(l <= r){
        int mid = (l + r) / 2;
        if(a[mid] - a[x] <= d) id = mid, l = mid + 1;
        else r = mid - 1;
    } return id;
}

int Get_R(int x){
    int l = 1, r = x, id;
    while(l <= r){
        int mid = (l + r) / 2;
        if(a[x] - a[mid] <= d) id = mid, r = mid - 1;
        else l = mid + 1;
    } return id;
}

void solveA(){
    cin >> n >> d; ans = 0;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        int tmp = a[i] + d, flag = 0, tot = 0;
        // cout << a[i] << " " << d << '\n';
        num[++tot] = i;
        for(int j = i + 1; j <= n; j++){
            if(a[j] - a[j - 1] > d) break;
            if(a[j + 1] > tmp || j + 1 > n){
                tmp = a[j] + d, num[++tot] = j;
                if(tot > 2 && num[tot - 2] < num[tot - 1] - 1 && a[num[tot - 1] - 1] + d >= a[num[tot]] && flag) break;
                if(tot > 2 && num[tot - 2] < num[tot - 1] - 2 && a[num[tot - 1] - 2] + d >= a[num[tot]]) break;
                if(tot > 2 && num[tot - 2] < num[tot - 1] - 1 && a[num[tot - 1] - 1] + d >= a[num[tot]]) flag = 1;
                // cout << flag << '\n';
                if(flag && tot >= 2) ans++;
            }else{
                // cout << "Get_R" << " " << Get_R(j) << '\n';
                if(tot >= 2 && num[tot] - Get_R(j) == 1 && !flag) ans++;
                if(tot >= 2 && num[tot] - Get_R(j) == 0 && flag) ans++;
            }
            // cout << i << " " << j << " " << tot << " " << tmp << '\n';
        }  // cout << "  "  << ans << '\n';
    } cout << ans << '\n';
}

void solve(){
    cin >> n >> d; sum[n] = vis[n] = num[1] = flag[1] = 1;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = n - 1; i >= 2; i--){
        int id1 = Get_L(i - 1), id2 = Get_L(i);
        if(id1 == id2 || vis[id2] == 0 || id1 == i || Get_L(Get_R(i) + 1) > i) vis[i] = sum[i] = 1;
        else vis[i] = 1, sum[i] = sum[id2] + (id2 - id1);
        // cout << i << " " << vis[i] << " " << sum[i] << '\n';
    }
    for(int i = 2; i <= n - 1; i++){
        int id1 = Get_R(i + 1), id2 = Get_R(i);
        if(id1 == id2 || flag[id2] == 0 || id1 == i || Get_R(Get_L(i) - 1) < i) flag[i] = num[i] = 1;
        else flag[i] = 1, num[i] = num[id2] + (id1 - id2);
        // cout << i << " " << flag[i] << " " << num[i] << '\n';
    } ans = 0;
    for(int i = 2; i <= n - 2; i++){
        int r = Get_L(i), l = Get_R(i + 1);
        if(l == i || r == i + 1 || l == i + 1 || r == i) continue;
        if(vis[r] && flag[l] && Get_L(l) == i + 1 && Get_R(r) == i){
            // cout << i << " " << i + 1 << " " << l << " -- " << r << " " << vis[r] << " " << flag[l] << '\n';
            // cout << (sum[r] + r - Get_L(i - 1) - 1) << '\n';
            ans = (ans + (sum[r] + r - Get_L(i - 1) - 1) * (num[l] + Get_R(i + 2) - l - 1));
            // cout << i << " : " << i + 1 << " " << (sum[r] + r - Get_L(i - 1) - 1) * (num[l] + Get_R(i + 2) - l - 1) << '\n';
        }
    } cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> op >> t;
    if(op <= 10){
        while(t--) solveA();
        return 0;
    }
    while(t--) solve();
    return 0;
}