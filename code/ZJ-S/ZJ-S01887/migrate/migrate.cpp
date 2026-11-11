#include <bits/stdc++.h>
using namespace std;
long long c,t,a[2000005];
long long dist[5005][5005],cnt[5005][5005],sum = 0;
int main () {
	freopen ("migrate.in","r",stdin);
	freopen ("migrate.out","w",stdout);
	cin >> c >> t;
	while (t --) {
		long long n,d;
		cin >> n >> d;
		for (int i = 1;i <= n;i ++)
			cin >> a[i];
		if (c <= 10) {sum = 0;
			for (int i = 1;i <= n;i ++)
				for (int j = 1;j <= n;j ++)
					dist[i][j] = 0x3f3f3f3f,cnt[i][j] = 0;
			for (int i = 1;i <= n;i ++)
				dist[i][i] = 0;
			for (int i = 1;i <= n;i ++)
				for (int j = 1;j < i;j ++) 
					if (abs(a[i] - a[j]) <= d)
						dist[i][j] = dist[j][i] = 1,cnt[i][j] = cnt[j][i] = 1;
			for (int k = n;k >= 1;k --)	{
				for (int i = 1;i < k;i ++) {
					if (dist[i][k] == 0x3f3f3f3f)continue;
					for (int j = k + 1;j <= n;j ++) {
						if (dist[k][j] == 0x3f3f3f3f)continue;
						if (dist[i][k] + dist[k][j] < dist[i][j])
							dist[i][j] = dist[i][k] + dist[k][j],cnt[i][j] = 1;
						else if (dist[i][k] + dist[k][j] == dist[i][j])
							cnt[i][j] ++;
					}
				}		
			}
			for (int i = 1;i <= n;i ++)
				for (int j = 1;j < i;j ++)
					if (cnt[i][j] == 2 || cnt[j][i] == 2)
						sum ++;	
			cout << sum << "\n";
		}
				
	}
	return 0;
}
