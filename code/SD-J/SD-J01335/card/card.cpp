#include <iostream>
#include <cstdio>
#include <vector>

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	int n, m;
	
	std::cin >> n >> m; 
	
	std::vector<int> cards(n), table(n), map(m + 1, -1), ans(m + 1, 0);
	for (int i = 0; i < n;i++) {
		std::cin >> cards[i];
	}
	
	for (int i = 0; i < n; i++) {
		int index = 0;
		for (int j = i; j < n; j++) {
			if (map[cards[j]] == -1) {
				map[cards[j]] = index;
				table[index] = cards[j];
				index++;
			}
			else {
				index = map[cards[j]] + 1;
			}
		}
		for (int j = 0; j < index; j++) {
			ans[table[j]]++;
		}
		for (int i = 0; i < m; i++) {
			if (map[i] == -1) continue;
			map[i] = -1;
		}
	}
	
	for (int i = 1; i <= m; i++) {
		if (i != 1) std::cout << ' ';
		std::cout << ans[i];
	}
	
	return 0;
} 
