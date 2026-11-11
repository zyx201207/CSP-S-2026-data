#include <iostream>
#include <vector>
#include <bitset>

constexpr int maxn=2e5+10;

std::bitset<maxn> s[40];
int popc[40];

int n, m;

int a[maxn];

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    for(int i=1; i<=n; i++) std::cin >> a[i];
    for(int j=0; j<32; j++) {
        for(int i=1; i<=n; i++) if((a[i]>>j)&1) s[j].set(i), popc[j]++;
    }
    int ans=0;
    std::bitset<maxn> cur;
    for(int i=1; i<=n; i++) cur.set(i);
    for(int j=32; j>=0; --j) {
        // std::cerr << j << ' ' << cur << '\n';
        if((cur&s[j]).count() >= m) {
            ans |= 1<<j;
            cur &= s[j];
        }
    }
    std::cout << ans;
}
