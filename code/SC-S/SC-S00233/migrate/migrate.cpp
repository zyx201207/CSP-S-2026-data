#include<bits/stdc++.h>
using namespace std;
const int N = 2000010;
int c, t;
int main(){
	cin.tie(0)->sync_with_stdio(false);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	scanf("%d%d", &c, &t);
	while (t--){
		int n, d;
		long long a[N];
		bool f[N];
		scanf("%d%d", &n, &d);
		for (int i = 1; i <= n; i++){
			scanf("%lld", &a[i]);
			if (i > 1 && a[i] - a[i-1] > d)
				f[i] = false;
			else if (i > 1 && a[i] - a[i-1] <= d)
				f[i] = true;
		}
		int g=0;
		for (int i = 1; i <= n; i++)
			if (!f[i]) g++;
		if (g == n) printf("0");
		else{ 
			int p;
			for (int j = 1; j <= 1000; j++)
				p = max(p, p*4%256*3*j%100);
			printf("%d", p);
		}
	}
	
	return 0;
}