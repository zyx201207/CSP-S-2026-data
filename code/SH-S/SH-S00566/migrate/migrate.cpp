#include<bits/stdc++.h>
using namespace std;
long long d, x[5005];
int f[5005][5005];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t;
	cin >> c >> t;
	
	while(t--){
		int n;
		memset(x, 0, sizeof(x));
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> x[i];
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++)
				f[i][j] = 0;
		}
		for(int i = 1; i < n; i++){
			for(int j = i + 1; j <= n; j++){
				for(int k = i; k < j; k++){
					if(x[j] - x[k] <= d)
						f[i][j] = f[i][k] + 1;
				}
			}
		}
		long long ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(f[i][j] == 2)
					ans++; 
			}
		}
		cout << ans-1 << "\n";
	}
	
	return 0;
} 
