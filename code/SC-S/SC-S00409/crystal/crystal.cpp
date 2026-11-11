#include <iostream>
#include <algorithm>

const int N = 5e5 + 99;

int n;
long long a[N], m;

namespace for_n_small{
	
	int ans = 0;
	void dfs( int i, long long mx, int k, long long cnt) {
		
		if(i > n) {
			
			if(mx*k - cnt <= m) {
				ans = std::max( ans, k);
			}
			return ;
			
		}
		
		if(mx*k - cnt > m) {
			return ;
		}
		
		dfs( i+1, mx, k, cnt);
		dfs( i+1, std::max( mx, a[i]), k+1, cnt + a[i]);
		
	}
	
}

namespace A_and_B{
	
	int ans = 0;
	bool is_this() {
		
		long long c = a[2] - a[1];
		for(int i = 2; i < n; i++)
			if(a[i+1] - a[i] != c)
				return false;
		return true;
		
	}
	
	void solve() {
		
		long long p = a[2] - a[1];
		
		int l = 1, r = n;
		
		while(l <= r) {
			
			int mid = (l+r) >> 1;
			if(mid*mid*p-(p-2)*mid <= 2*m)
				ans = mid, l = mid + 1;
			else
				r = mid - 1;
			
		}
		
	}
	
}

int main() {
	
	freopen( "crystal.in", "r", stdin);
	freopen( "crystal.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	std::cin >> n >> m;
	for(int i = 1; i <= n; i++)
		std::cin >> a[i];
	std::sort( a+1, a+1+n);
	
	if(A_and_B::is_this()) {
		A_and_B::solve();
		std::cout << A_and_B::ans+1;
	}
	else {
		for_n_small::dfs( 1, 0, 0, 0);
		std::cout << for_n_small::ans;
	}
	
	return 0;
	
}