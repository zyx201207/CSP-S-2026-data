#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m;
long long ans[N], vis[N], desk[N], dl[N], dic[N],
     card[N]; //ans:´ð°¸´¢´æ vis:±ê¼Ç desk:×ÀÃæ dl:×ÀÃæÏÖÓÐ¿¨ÅÆ dic:ÆúÅÆ card:¿¨ÅÆ

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			desk[j - i] = card[j];
			if (vis[desk[j - i]] > 0) {
				for (int p = j - i - 1; p > 0; p--) {
					if (desk[p] = desk[j - i]) {
						for (int x = p; x < j - i ; x++) {
							vis[desk[x]] = 0;
							desk[x] = 0;
						}
						continue;
					}

				}
			}
			desk[j - i] = card[j];
			vis[desk[j - i]]++;
		}
		for (int k = 0; k < n; k++) {
			if (dic[desk[k]] == 0) {
				dic[desk[k]] = desk[k];
			}
		}
		for (int k = 0; k < n; k++) {
			if (dic[k] > 0)
				ans[dic[k]]++;
		}
//		cout << endl;
//		for (int k = 0; k < n; k++) {
//			cout << desk[k] << " ";
//		}
//		cout << endl;
//		for (int k = 0; k < n; k++) {
//			cout << dic[k] << " ";
//		}
//		cout << endl;
		for (int k = 0; k < n; k++)
			desk[k] = 0;
		for (int k = 0; k < n; k++)
			dic[k] = 0;
		for (int k = 0; k < n; k++)
			vis[k] = 0;
	}
	for (int k = 1; k <= m; k++)
		cout << ans[k] << " ";
	return 0;
}

