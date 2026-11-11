#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], use[100], eend[100], end[100]; 
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	if ((n > 5) || (m > 2)) return 0;
	for (int i = 1; i <= n; i ++){
		int id = 1;
		for (int j = 1; j <= 9; j ++) use[i] = 0;
		for (int j = i; j <= n; j ++){
			use[id] = a[j];
			if (eend[a[j]] == 0){
				eend[a[j]] ++;
			}
			else{
				int k = id - 1;
				while (true){
					if (use[k] == use[id]){
						break;
					}
					else{
						eend[use[k]] --;
					}
					k --;
				}
			}
			id ++;
		}
		for (int i = 1; i <= m; i ++){
			if (eend[i] != 0) end[i] ++;
			eend[i] = 0;
		}
	}
	for (int i = 1; i <= m; i ++){
		cout << end[i] << " ";
	}
	return 0;
} 
