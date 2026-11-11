#include<bits/stdc++.h>
using namespace std;
int z[2000005];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t --){
		for (int i = 1;i < 2000001;i ++){
			z[i] = 0;
		}
		int n, d;
		cin >> n >> d;
		for (int i = 1;i <= n;i ++){
			cin >> z[i];
		}
		int cnt = 0;
		for (int i = 1;i <= n;i ++){
			for (int j = i + 1;j <= n;j ++){
				if ((z[j] - z[i] <= d && j == i + 2)){
					cnt ++;
				}
			}
		}
		cout << cnt;
	}
	
}
