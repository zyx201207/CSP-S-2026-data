#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, M = 3e5 + 10;
int m, n, a[N], times[M], loc[M], des[N], len;
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n > 500){
		for (int i = 1; i <= n; i++){
			memset(loc, 0, sizeof loc);
			len = 0;
			for (int j = i; j <= n; j++){
				des[++len] = a[j];
				if (des[len] == des[len - 1]) len--;	
			}
			for (int i = 1; i <= len; i++) times[des[i]]++;
		}
		for (int i = 1; i <= m; i++) cout << times[i] << " ";
		return 0;
	}
	for (int i = 1; i <= n; i++){
		memset(loc, 0, sizeof loc);
		len = 0;
		for (int j = i; j <= n; j++){
			if (loc[a[j]] == 0){
				des[++len] = a[j];
				loc[a[j]] = len;
			}
			else {		
				for (int k = 1; k <= m; k++){
					if (loc[k] > loc[a[j]]) loc[k] = 0;
				}
				len = loc[a[j]];
			}
		}
		for (int i = 1; i <= len; i++) times[des[i]]++;
	}
	for (int i = 1; i <= m; i++) cout << times[i] << " ";
	return 0;
} 
