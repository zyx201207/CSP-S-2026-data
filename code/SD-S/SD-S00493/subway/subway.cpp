#include <bits/stdc++.h>
using namespace std;
int c , n , m , d , q , e;
int a[100001] , t[1001][1001] , w[1001][1001];
bool flag = true , fa = false;
int main()
{
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++){
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++){
		cin >> e;
		for (int j = 1;j <= e;j++){
			cin >> w[i][j] >> t[i][j];
		}
	}
	int sum = 0;
	int l , r;
	for (int i = 1;i <= q;i++){
		int s , g;
		int p = s;
		cin >> s >> g;
		sum += s;
		for (int j = 1;j <= n;j++){
			for (int v = 1;v <= e;v++){
				if (!flag){
				    sum += t[j][v];
				}
				if (w[j][v] == p){
					sum += t[j][v];
					if (p == g){
					    fa = true;
					    break;
					}
					p = g;
					flag = false;
				}
			}
			if (fa){
				break;
			}
		}
		cout << sum << '\n';
		sum = 0;
	}
	return 0;
}

