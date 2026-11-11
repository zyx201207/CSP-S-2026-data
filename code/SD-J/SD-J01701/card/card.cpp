#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], c[300005], d[300005];// b现数组 a替换数组 
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int j = 1; j <= n; j++){
		int sum = 0;
		for(int i = j; i <= n; i++){
			if(d[a[i]] != 0){
				for(int k = d[a[i]]; k <= i; k++)
					d[a[k]] = 0;
				d[a[i]] = i;
			}
			else
				d[a[i]] = i;
		}
		for(int i = 1; i <= m; i++){
			if(d[i] != 0)
				c[i]++;
			d[i] = 0;
		}
	}
	for(int i = 1; i <= m; i++)
		cout << c[i] << " ";
 	return 0;
}
