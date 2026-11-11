#include <iostream>
#include <algorithm>

int n, m;
int a[200005];

bool cmp(int x, int y){
	if(x == y) return true;
	return !((x > y) * (x & y > x - y) || (y > x) * (x & y > y - x));
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	std::cin >> n >> m;
	for(int i = 0;i < n;++i)
		std::cin >> a[i];
	std::sort(a, a + n, cmp);
	int ans = a[0];
	for(int i = 1;i < m;++i){
		ans &= a[i];
	}
	std::cout << ans;
	return 0;
}
