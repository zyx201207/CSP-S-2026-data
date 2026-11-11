#include<bits/stdc++.h>
using namespace std;
long long c, t, n, d, a[2000005], f[10000][10000];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for (int T = 1; T <= t; T++){
		int ans = 0;
		memset(f, 0x3f3f3f, sizeof(f));
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i < n; i++){
			if (a[i + 1] - a[i] < d)
				f[i][i + 1] = 1; 
		}
		for (int l = 3; l <= n; l++){
			for (int i = 1; i <= n; i++){
				int j = i + l - 1;
				if (a[j] - a[i] <= d)
					f[i][j] = 1;
				else{
					long long lmin = 9999999999, rmin = 9999999999, sum = 0;
					for (int k = i; k < j; k++){
						if (f[i][k] < lmin && f[k][j] < rmin){
							sum = f[i][k] * f[k][j];
							lmin = f[i][k]; rmin = f[k][j];
						}
						else if (f[i][k] < rmin && f[k][j] < lmin){
							sum = f[i][k] * f[k][j];
							lmin = f[i][k]; rmin = f[k][j];
						}
						else if (f[i][k] < lmin && f[k][j] == rmin){
							sum = f[i][k] * f[k][j];
							lmin = f[i][k]; rmin = f[k][j];
						}
						else if (f[i][k] < rmin && f[k][j] == lmin){
							sum = f[i][k] * f[k][j];
							lmin = f[i][k]; rmin = f[k][j];
						}
						else if (f[i][k] == lmin && f[k][j] < rmin){
							sum = f[i][k] * f[k][j];
							lmin = f[i][k]; rmin = f[k][j];
						}
						else if (f[i][k] == rmin && f[k][j] < lmin){
							sum = f[i][k] * f[k][j];
							lmin = f[i][k]; rmin = f[k][j];
						}
						else if (f[i][k] == rmin && f[k][j] == lmin)
							sum += f[i][k] * f[k][j];
						else if (f[i][k] == lmin && f[k][j] == rmin)
							sum += f[i][k] * f[k][j];
					}
					f[i][j] = min(f[i][j], sum);
					if (f[i][j] == 2){
						ans++;
					}
				}
			}
		}
		cout << ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//1 2 3 4 5 6 7 -> 4
//1,6
