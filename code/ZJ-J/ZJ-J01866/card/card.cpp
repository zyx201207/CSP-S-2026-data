// Pass 40
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, a[500005], b[505], ans[505], h[300005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	//
	bool flagA = 1, flagB = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		h[a[i]] = i;
		if (a[i] < a[i-1]) flagA = 0;
	}
	
	//
	if (flagA){
		for (int i = 1; i <= m; i++){
			cout << h[i];
			if (i != m) cout << ' ';
		}
		return 0;
	}
	for (int i = 1; i <= n; i++){
		memset(b, 0, sizeof(b));
		for (int j = i; j <= n; j++){
			bool flag = 0;
			for (int k = 1; k <= n; k++){
				if (flag) b[k] = 0;
				else if (b[k] == a[j]){
					flag = 1;
					b[k] = a[j];
				}
				else if (b[k] == 0){
					b[k] = a[j];
					break;
				}
			}
		}
		for (int k = 1; k <= n; k++){
			if (b[k] == 0) break;
			ans[b[k]]++;
		}
	}
	
	//
	for (int i = 1; i <= m; i++){
		cout << ans[i];
		if (i != m) cout << ' ';
	}
	
	return 0;
}