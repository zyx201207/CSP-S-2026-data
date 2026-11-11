#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

constexpr int maxn=5e5+10, maxm=3e5+10;

int cost[maxn], lst[maxn], nxt[maxn], born[maxn], ans[maxm], vis[maxm];

int n, m;

int c[maxn];

#define lowbit(x) (x&-(x))

void update(int p, int x) {
    for(; p<=n+5; p+=lowbit(x)) c[p]=x;
}

int max(int p) {
    int ans=0;
    for(; p; p-=lowbit(p)) ans=std::max(c[p], ans);
    return ans;
}

void solve(int start) {
    std::vector<int> where(m+1, -1);
    for(int i=start; i<=n; i++) {
        if(~where[cost[i]]) {
            int fr=where[cost[i]];
            for(int j=1; j<=m; j++) if(fr <= where[j]) where[j]=-1;
        }
        where[cost[i]]=i;
    }
    for(int j=1; j<=m; j++) if(~where[j]) ans[j]++;
}

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    for(int i=1; i<=n; i++) std::cin >> cost[i];
    for(int i=1; i<=n; i++) solve(i);
    for(int i=1; i<=m; i++) std::cout << ans[i] << ' ';
}
