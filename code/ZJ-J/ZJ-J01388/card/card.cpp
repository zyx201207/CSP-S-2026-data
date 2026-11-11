#include <bits/stdc++.h>
using namespace std;
int card[5010];
int cnt[3010];
vector<int> desk;
int indesk(int n){
	for (int i = 0; i < desk.size(); i++){
		if (desk[i] == n) return i;
	}
	return -1;
}
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> card[i];
	for (int t = 1; t <= n; t++){
		desk.clear();
		for (int i = t; i <= n; i++){
			int in = indesk(card[i]);
			if (in != -1){
				for (int j = in; j <= desk.size(); j++){
					desk.pop_back();
				}
			}
			desk.push_back(card[i]);
		}
		for (int i = 0; i < desk.size(); i++){
			cnt[desk[i]]++;
		}
	}
	for (int i = 1; i <= m; i++){
		cout << cnt[i] << ' ';
	}
	return 0;
}