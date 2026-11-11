#include <iostream>
using namespace std;
int card_pos[13];
int cnt[13];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	int card[13], table[13];
	for (int i = 1; i <= n; i++) {
		cin >> card[i];
	}
	for (int k = 1; k <= n; k++) {
		int pos = 1;
		memset(card_pos, 0, sizeof(card_pos));
		memset(table, 0, sizeof(table));
		for (int i = k; i <= n; i++) {
			if (card_pos[card[i]] == 0) {
				card_pos[card[i]] = pos;
				table[pos] = card[i];
				pos++;
			}
			else {
				for (int j = card_pos[card[i]] + 1; j <= pos; j++) {
					table[j] = 0;
					card_pos[table[j]] = 0;
				}
				pos = card_pos[card[i]] + 1;
			}
				
				
		
		}
		
		for (int i = 1; i <= pos; i++) {
			cnt[table[i]]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << cnt[i] << ' ';
	}
	return 0;
}