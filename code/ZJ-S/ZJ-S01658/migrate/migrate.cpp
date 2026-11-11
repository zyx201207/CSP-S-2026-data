/*
16:07 start
16:20 56pts idea
17:24 56pts
*/

#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 2000005;
int c, t;
int n, d;
int a[N];
void init(int n, int d) {

    return ;
}
int dis[N];
int cnt[N];
queue<int> q[N];
int cc[N];
void CASE_A() {
    for(int i = 0; i <= n; i ++) {
        while(!q[i].empty()) q[i].pop();
        cc[i] = 0;
    }
    q[0].push(n);
    cc[0] = 1;
    dis[n] = 0;
    cnt[n] = 1;
    int now_dis = 0;
    bool fff = 0;
    for(int i = n - 1; i >= 1; i --) {
        while(a[q[now_dis].front()] - a[i] > d) {
            cc[now_dis] -= cnt[q[now_dis].front()];
            q[now_dis].pop();
            if(q[now_dis].empty()) {
                now_dis ++;
                if(q[now_dis].empty()) {
                    fff = 1;
                    break;
                }
            }
        }
        if(fff) break;
        dis[i] = now_dis + 1;
        cnt[i] = cc[now_dis];
        q[dis[i]].push(i);
        cc[dis[i]] += cnt[i];
    }
    int ans = 0;
    for(int i = 1; i < n; i ++) {
        if(cnt[i] == 2) {
            ans += i;
        }
    }
    cout << ans << "\n";
    return ;
}
void CASE_B() {
    if(n <= 3) {
        cout << 0 << "\n";
        return ;
    }
    int far1 = 0, far2 = 0, far3 = 0;
    while(far1 < n && a[far1 + 1] - a[1] <= d) far1 ++;
    far2 = far1 - 1;
    far3 = far2 - 1;
    int farfar1 = n, farfar2;
    while(a[farfar1] - a[far2] > d) {
        farfar1 --;
    }
    int ans = 0;
    if(farfar1 <= far1) {
        cout << ans << "\n";
        return ;
    }
    ans += farfar1;
    farfar2 = farfar1;
    while(a[farfar2] - a[far3] > d) {
        farfar2 --;
    }
    ans -= farfar2;
    for(int i = 2; i <= n; i ++) {
        while(far1 < n && a[far1 + 1] - a[i] <= d) {
            far1 ++;
            far2 ++;
            far3 ++;
        }
        while(farfar1 < n && a[farfar1 + 1] - a[far2] <= d) {
            farfar1 ++;
        }
        if(farfar1 <= far1) {
            cout << ans << "\n";
            return ;
        }
        while(farfar2 < n && a[farfar2 + 1] - a[far3] <= d) {
            farfar2 ++;
        }
        ans += farfar1;
        ans -= farfar2;
    }
    return ;
}
signed Main() {
    cin >> n >> d;
    init(n, d);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    if(11 <= c && c <= 12) {
        CASE_A();
        return 0;
    }
    if(13 <= c && c <= 14) {
        CASE_B();
        return 0;
    }
    
    int ans = 0;
    for(int i = n; i >= 2; i --) {
        for(int j = 0; j < n; j ++) {
            while(!q[j].empty()) q[j].pop();
            cc[j] = 0;
        }
        dis[i] = 0;
        cnt[i] = 1;
        q[0].push(i);
        cc[0] = 1;
        int now_dis = 0;
        bool fff = 0;
        for(int j = i - 1; j >= 1; j --) {
            while(a[q[now_dis].front()] - a[j] > d) {
                cc[now_dis] -= cnt[q[now_dis].front()];
                q[now_dis].pop();
                if(q[now_dis].empty()) {
                    now_dis ++;
                    if(q[now_dis].empty()) {
                        fff = 1;
                        break;
                    }
                }
            }
            if(fff == 1) {
                break;
            }
            dis[j] = now_dis + 1;
            cnt[j] = cc[now_dis];
            q[dis[j]].push(j);
            cc[dis[j]] += cnt[j];
            if(cnt[j] == 2) {
                ans ++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t --) {
        Main();
    }
    // cerr << clock() * 1.0 / CLOCKS_PER_SEC << "\n";
    return 0;
}