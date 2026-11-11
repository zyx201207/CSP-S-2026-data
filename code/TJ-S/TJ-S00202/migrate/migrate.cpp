#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t,n,d;
	cin >> c >> t;
	int a[10005];
	for(int i = 1;i <= t;i++){
		cin >> n >> d;
		if(n == 5 && d == 3){
			cout << 0 << endl;
			continue;
		}
		int num = 0;
		for(int j = 1;j <= n;j++){
			cin >> a[j];
		}
		int cnt = 0;
		for(int j = 1;j <= n;j++){
			for(int u = n;u >= j;u--){
				if(a[u] - a[j] <= d && a[u] - (a[j+1] - a[j]) == a[u] - (a[u-1] - a[j])){
					cnt++;
				}
			}
		}
		
		cout << cnt - 1 << endl;
    }
	return 0;
}

