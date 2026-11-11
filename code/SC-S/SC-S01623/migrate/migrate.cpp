#include <bits/stdc++.h>
using namespace std;
int c, t;
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for (t = t;t >= 1; t--){
		int cnt = 0;
		long long n, d;
		cin >> n >> d;
		long long x[2000005] = {0};
		long long p[2000005] = {0};
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		for (int i = 3; i <= n; i++){
			if (x[i] - x[i-1] > d)
			continue;
			if (x[i] > d){
				int j = 1;
				while(((i - j) >= 2)&&((x[i] - x[j]) > d))
				if (x[j] - x[j-1] > d){
					j = 0;
					break;	
				}
				if (j){
					p[j]++;
					p[i]--;
				}
			}
		}
		for (int j = 1; j <= n; j++){
		cnt += p[j];
		}
		cout << cnt;
	}
	return 0;
}