#include <bits/stdc++.h>
using namespace std;
long long c , d , n , m , sum = 0, a[100001];
int main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	cin >> c >> d;
	for (int i = 1;i <= d;i++){
		scanf("%d%d" , &n , &m);
		for (int j = 1;j <= n;j++){
			cin >> a[j];
		}
		for (int j = 1;j <= n;j++){
			for (int k = j + 1;k <= n;k++){
				if (abs(a[k] - a[j]) == m * 2 - 1 && k - j > 2){
					sum++;
				}
			}
		}
		cout << sum << '\n';
		sum = 0;
	}
	return 0;
}
