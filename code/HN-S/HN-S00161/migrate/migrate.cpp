#include<bits/stdc++.h>
using namespace std;

int c, t;
bool y_n = true;
int a[2000005];

void check_dc(int k){
	int d[2000005];
	for (int i = 1; i <= k; i ++){
		d[i] = a[i] - a[i - 1];
	}
	for (int i = 2; i < k; i ++)
		if (d[i] != d[i + 1])
		    y_n = false;
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio;
	cin.tie(0), cout.tie(0);
	
	cin >> c >> t;
	for (int i = 1; i <= t; i ++){
		int n, d, sum;
		memset(a, 0, sizeof(a));
		cin >> n >> d;
		for (int j = 1; j <= n; j ++){
			cin >> a[i];
		}
		check_dc(n);
		if (y_n){
			for (int i = n - 2; i >= n - 2 - d; i ++){
			    sum += i;
		    }
		}
		if (a[(n + 1) / 2] - a[1] <= d && a[n] - a[(n + 1) / 2] <= d)
		    sum += n - 1;
		cout << sum;
	}
	
	return 0;
} 
