#include <bits/stdc++.h>
#define PII pair<long,long>
#define ll long long
using namespace std;
const int N = 5e5 + 10;
const ll inf = 1e18;
unordered_map<int,int> s;
ll c[N];
PII g2[N];
PII p[N];
int dp[N];
int cntg;
int n;
ll m;
ll ans2;
void dfs(int x,ll val,ll step,ll mid) {
    if (val > m) return;
    if (x == -1) {
        // cout << mid << ' ' << val << ' ' << step << '\n';
        ans2 = max(ans2,step);
        return;
    }
    dfs(x - 1,val,step,mid);
    if (mid == inf) dfs(x - 1,val,step + g2[x].second,g2[x].first);
    dfs(x - 1,val + (mid - g2[x].first) * g2[x].second,step + g2[x].second,mid);
}
bool check(int mid) {
    ll cnt = 0;
    for (int i=1;i<=mid;++i) cnt += (c[mid] - c[i]);
    return cnt <= m;
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    bool flag = 1,flag2 = 1;
    for (int i=1;i<=n;++i) {
        cin >> c[i];
        if (c[i] != i) flag = 0;
        if (i >= 2 && c[i] - c[i - 1] != c[i - 1] - c[i - 2]) flag2 = 0;
        s[c[i]]++;
    }
    if (flag) {
        ll cnt = 0;
        ll ans = 1;
        for (int i=2;i<=n;++i) {
            cnt += i - 1;
            if (cnt <= m) ans++;
            else break;
        }
        cout << ans;
        return 0;
    }
    else if (flag2) {
        sort(c+1,c+1+n);
        ll cnt = 0;
        ll d = c[2] - c[1];
        ll ans = 1;
        for (int i=2;i<=n;++i) {
            cnt += d * (i - 1);
            if (cnt <= m) ans++;
            else break;
        }
        cout << ans;
        return 0;
    }
    else if (s.size() <= 25){
        for (auto i : s) {
            g2[++cntg] = {i.first,i.second};
            // cout << i.first << ' ' << i.second << '\n';
        }
        sort(g2+1,g2+1+cntg);
        dfs(cntg,0,0,inf);
        cout << ans2;
    }
    else {
        for (auto i : s) g2[++cntg] = {i.first,i.second};
        sort(g2+1,g2+1+cntg);
        dp[1] = g2[1].second;
        p[1] = {0,1};
        int l = 1;
        for (int i=2;i<=cntg;++i) {
            dp[i] = dp[i - 1];
            int cnt = dp[i - 1] * (g2[i].first - g2[p[i - 1].second].first) + p[i - 1].first;
            if (cnt <= m) dp[i] += g2[i].second,p[i] = {cnt,i};
            else {
                int t = l,w = 0;
                while (t <= i) {
                    w -= g2[t].second;
                    cnt -= g2[t].second * (g2[i].first - g2[t].first);
                    t++;
                    if (cnt <= m) break;
                }
                if (t > i) {
                    p[i] = p[i - 1];
                    continue;
                }
                w += g2[i].second;
                if (w < 0) p[i] = p[i - 1];
                else p[i] = {cnt,i},l = t;
            }
        }
        cout << dp[cntg];
    }
    return 0;
}
