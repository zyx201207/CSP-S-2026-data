#include <iostream>
#include <algorithm>
using i64 = long long;
const int maxn = 5e5 + 5;

int a[maxn];
i64 pre[maxn];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, m;
    std::cin >> n >> m;
    for(int i = 1; i <= n; ++i) std::cin >> a[i];

    std::sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + a[i];

    i64 ans = 0;
    int left = 1;
    for(int i = 1; i <= n; ++i)
    {
        if((i - left + 1) * a[i] - (pre[i] - pre[left - 1]) > m) left++;

        ans = ans > i - left + 1 ? ans : i - left + 1;
    }
    std::cout << ans;        
}
