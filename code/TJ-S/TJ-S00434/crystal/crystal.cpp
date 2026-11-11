#include <iostream>
#include <algorithm>
#include <cstddef>

int n;
long long m, mi = LLONG_MAX, ma = LLONG_MIN;
long long a[500005], diff[500005]{};

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	std::cin >> n >> m;
	for(int i = 1;i <= n;++i){
		std::cin >> a[i];
		ma = std::max(ma, a[i]);
		mi = std::min(mi, a[i]);
	}
	
	long long fium = 0;
	for(long long i = mi;i <= ma;++i){
		for(int j = 1;j <= n;++j)
			diff[j] = std::abs(a[j] - i);
		std::sort(diff + 1, diff + n + 1);
		long long f_u = m, num = 0;
		for(int j = 1;j <= n;j++){
			++num;
			f_u -= diff[j];
			if(f_u <= 0){
				if(f_u < 0)
					--num;
				break;
			}
		}
		std::cout << '\n';
		fium = std::max(fium, num);
	}
	std::cout << fium;
	return 0;
}
