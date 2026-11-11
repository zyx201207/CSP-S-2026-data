#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;
int n, m, cnt[MAXN];
int a[MAXN];
int fi[MAXN], fil = 0; // 已经出过的牌 
void game(int pos) { // 进行到了第 pos 局
	// 第 i 轮出的牌应该是 a[pos + i - 1] 
	for(int i = 1; i <= n - pos + 1; i++) {
		int card = a[pos + i - 1]; // 出牌 card 
		fi[++fil] = card;
		if(fil != 1) {
			for(int j = 1; j <= fil - 1; j++) {
				bool flag = false;
				if(fi[j] == card) {
					for(int k = fil; k >= j + 1; k--) {
						fi[k] = -1;
						fil--;
					}
					flag = true; // 找到重复的牌，拿走 
				}
				if(flag == true) break;
			}
		}
	}
	for(int j = 1; j <= fil; j++) {
		if(fi[j] >= 0) {
			cnt[fi[j]]++;
		}
	}
}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) game(i);
	for(int i = 1; i <= m; i++) cout << cnt[i] << " ";
	cout << "\n";
	return 0;
} 
