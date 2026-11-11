#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
int const MAXN = 2e5 + 5;
int n, trie[MAXN][2], cnt[MAXN], idx, a[MAXN], pre[40], tot, ans, m, suf[MAXN];
vector<pair<int, int>> e;
void modify(int x) {
    int u = 0;
    while(x > 0) {
        int d = x % 2;
        if(trie[u][d] == 0) trie[u][d] = ++idx;
        u = trie[u][d];
        x = x / 2;
    }
    cnt[u]++;
}
int cdd(string x) {
    int len = x.length();
    int sum = 0;
    for(int i = 0; i < len; i++) {
        sum += (x[i] - '0') * pre[len - i + 1];
    }
    return sum;
}
int dfs(int x, int s, string sum, int last ) {
    if(trie[x][0] == 0 && trie[x][1] == 0) {
        e.push_back({cdd(sum), cnt[x]});
        return cnt[x];
    }
    char hh;
    if(last == 1) hh = '1';
    else hh = '0';
    string c = sum + hh;
    int g = cdd(c), d = 0;
    if(trie[x][0] != 0 && trie[x][1] != 0) {
        d = dfs(trie[x][0], s + 1, c, 0) + dfs(trie[x][1], s + 1, c, 1) + cnt[x];
        e.push_back({g, d});
        //cout << s << '\n';
    }
    else if(trie[x][1] != 0){
        d = dfs(trie[x][1], s + 1, c, 1) + cnt[x];
        e.push_back({g, d});
        //cout << s << '\n';
    }
    else if(trie[x][0] != 0) {
        d = dfs(trie[x][0], s + 1, c, 0) +cnt[x];
        e.push_back({g, d});
        //cout << s << '\n';
    }
    return d;
}

// void dfs(int x, int s, ll sum) {
//     if(trie[x][0] == 0 && trie[x][1] == 0) return;
//     int c = sum, d = 0;
//     if(trie[x][0] != 0 && trie[x][1] != 0) {
//         dfs(trie[x][0], s + 1, c) , dfs(trie[x][1], s + 1, c);
//         cout << s << ' ';
//     }
//     else if(trie[x][1] != 0){
//         dfs(trie[x][1], s + 1, c);
//         cout << s << ' ';
//     }
//     else if(trie[x][0] != 0) {
//         dfs(trie[x][0], s + 1, c);
//         cout << s << ' ';
//     }
// }
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    //ios::sync_stdio(0);                                                       
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    pre[0] = 1;
    for(int i = 1; i <= 30; i++) {
        pre[i] = pre[i - 1] * 2;
    }
    for(int i = 1; i<= n; i++) {
        cin >> a[i];
        modify(a[i]);
    }
    dfs(0, 0, "", 0);
    for(pair<int, int> d : e) {
        if(d.se >= m) 
            ans= max(ans, d.fi);
        //cout << d.fi << ' ' <<d.se << '\n';
    }
    cout << ans << '\n';
    return 0;
}


