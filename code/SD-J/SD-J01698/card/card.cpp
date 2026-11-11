#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[500010], b[300010], id[300010], ans[300010];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ll n, m, f = 0;
	cin >> n >> m;
	for (int i = 0;i < n;i++){
		cin >> a[i];
		b[a[i]]++;
	}
	for (int i = 1;i < n;i++){
		if (a[i] < a[i-1]){
			f = 1;
		}
	}
	if (f == 0){
		for (int i = 1;i <= m;i++){
			cout << n << " ";
		}
		return 0;
	}
	for (int k = 0;k < n;k++){
		memset(id, -1, sizeof(id)); 	
		for (int i = k;i < n;i++){
			if (id[a[i]] == -1){
				id[a[i]] = i;
			} else {
				for (int j = id[a[i]];j < i;j++){
					id[a[j]] = -1;
				} id[a[i]] = i;
			}
		}		
		for (int i = 1;i <= m;i++){
			if (id[i] != -1){
				ans[i]++;
			}
		}
	}
	for (int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
