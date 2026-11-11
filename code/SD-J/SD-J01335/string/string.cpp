#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

struct Substr {
	long long times;
	char c;
};

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	int n;
	std::cin >> n;
	std::vector<Substr> S(n);
	
	for (int i = 0; i < n; i++) {
		std::cin >> S[i].times >> S[i].c;
	} 
	
	int l = 0, r = n - 1;
	long long ans = 0;
	
	while (l < r) {
		long long tmp = std::min(S[l].times, S[r].times);
		
		S[l].times -= tmp;
		S[r].times -= tmp;
		if (S[l].c != S[r].c) ans += tmp;
		
		if (S[l].times == 0) l++;
		if (S[r].times == 0) r--; 
	}
	
	std::cout << ans;
	
	return 0;
}
