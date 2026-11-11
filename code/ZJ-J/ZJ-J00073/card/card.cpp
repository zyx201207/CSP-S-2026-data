#include <bits/stdc++.h>
using namespace std;
int n, m, a[500001], b[300001];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	if (m == 1){
		cout << n;
		return 0;
	}for (int i = 1; i <= n; i++){
		cin >> a[i];
	}for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			if (a[j] == a[j - 1]){
				b[a[j]]--;
			}else{
				b[a[j]]++;
			}
		}
	}for (int i = 1; i <= m; i++){
		cout << b[i] << " ";
	}
	return 0;
}
