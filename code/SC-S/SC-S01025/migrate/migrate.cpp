#include<bits/stdc++.h>
using namespace std;
long long c, t, n, a[100010], vis[100010], cnt[100010];
unsigned long long d, dis[100010];
queue<long long> q;
bool check(long long x, long long y){
    if(x >= 0 && y >= 0)return abs(x - y) <= d;
    else if(x <= 0 && y <= 0)return abs(x - y) <= d;
    else if(x >= 0 && y <= 0) return x - d <= y;
    else return abs(x - y) <= d;
}int bfs(int s) {
    for(int i = 1; i <= n; i ++) {
        vis[i] = 0;
        dis[i] = 3e18;
        cnt[i] = 0;
    }q.push(s);
    vis[s] = 1;
    dis[s] = 0;
    cnt[s] = 1;
    while(q.size()) {
        int x = q.front();
        q.pop();
        for(int i = x + 1; i <= n; i ++) {
            if(vis[i] <= 0 && check(a[i], a[x])) {
                q.push(i);
                vis[i] = 1;
                dis[i] = dis[x] + 1;
                cnt[i] = 1;
            }else if(check(a[i], a[x])) {
                if(dis[x] + 1 == dis[i]){
                	cnt[i] ++;
				}
            }
        }
    }int sum = 0;
    for(int i = s; i <= n; i ++) {
        if(cnt[i] == 2) sum ++;
    }return sum;
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t --) {
        cin >> n >> d;
        for(int i = 1; i <= n; i ++) cin >> a[i];
        sort(a + 1, a + 1 + n);
        long long ans = 0;
        for(int i = 1; i <= n; i ++) {
            ans += bfs(i);
        }cout << ans << "\n";
    }return 0;
}