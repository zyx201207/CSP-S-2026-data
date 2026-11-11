#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, m;
int tot;
int a;
int mx;
int ans;
int val[N];
int cnt[N];
int trie[N][2];
string s[N];
void dfs(int x, int fa, int f){
    val[x] = val[fa] * 2 + f;
    if (trie[x][1])
        dfs(trie[x][1], x, 1);
    cnt[x] += cnt[trie[x][1]];
    if (trie[x][0])
        dfs(trie[x][0], x, 0);
    cnt[x] += cnt[trie[x][0]];
    if (cnt[x] >= m) {
        ans = max(ans, val[x]);
    }
}
signed main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a;
        while (a) {
            int r = a % 2;
            s[i].insert(0, to_string(r));
            a /= 2;
        }
        if(s[i].size() > mx)
            mx = s[i].size();
    }
    for (int i = 1; i <= n; i++) {
        int nw = 0;
        for(int j = 0; j < s[i].size(); j++) {
            int v = s[i][j] - '0';
            if (trie[nw][v] == 0) {
                trie[nw][v] = ++tot;
            }
            nw = trie[nw][v];
        }
        cnt[nw]++;
    }
    dfs(0, 0, 0);
    cout << ans;
    return 0;
}
