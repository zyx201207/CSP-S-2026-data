#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
long long a[303], d[305][305], cnt[305][305];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--){
		long long n, dis;
		cin >> n >> dis;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		int l = 0, r = 0;
		a[0] = -1e18-1;
		memset(d, 0x3f, sizeof d);
		memset(cnt, 0 , sizeof cnt);
		for(int i = 1; i <= n; i++){
			while(a[i]-a[l]>dis&&l<n){
				l++;
			}
			while(a[r]-a[i]<dis&&r<n)r++;
			for(int j = l; j <= r; j++){
				d[j][i] = 1;
				cnt[j][i] = 1;
			}
		}
		for(int i = 1; i <= n; i++)d[i][i] = 0;
		for(int k = 1; k <= n; k++){
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					if(i!=j&&j!=k&&k!=i)
					if(d[i][j]>d[i][k]+d[k][j]){
						d[i][j] = d[i][k]+d[k][j];
						cnt[i][j] = cnt[k][j]*cnt[i][k];
					}else if(d[i][j]==d[i][k]+d[k][j]){
						cnt[i][j] += cnt[k][j]*cnt[i][k];
					}
				}
			}
		}
		int res = 0;
		for(int i = 1; i <= n; i++){
			for(int j = i; j <= n; j++){
				if(cnt[i][j]==2)res++;
			}
		}
		cout << res <<endl;
	}
	return 0;
}
