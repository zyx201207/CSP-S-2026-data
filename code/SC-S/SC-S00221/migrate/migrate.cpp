#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 5005,INF = 2 * 1e6 + 1;

int c,t;
long long n,d,a[MAX],dp[MAX][MAX],cnt[MAX][MAX],ans = 0;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1;i <= n;++i)	cin >> a[i];
		
		ans = 0;
		for(int i = 1;i <= n;++i)
			for(int j = 1;j <= n;++j){
				if(i != j)	dp[i][j] = (abs(a[i] - a[j]) <= d) ? 1 : INF;
				cnt[i][j] = 1;
			}
		
		for(int k = 1;k <= n;++k)
			for(int i = 1;i <= n;++i)
				for(int j = 1;j <= n;++j){
					if(dp[i][j] == dp[i][k] + dp[k][j])	++cnt[i][j];
					if(dp[i][j] > dp[i][k] + dp[k][j]){ dp[i][j] = dp[i][k] + dp[k][j];cnt[i][j] = 1; }
				}
		
		for(int i = 1;i <= n;++i){
			for(int j = i + 1;j <= n;++j)
				if(cnt[i][j] == 2)	++ans;
				//cout << cnt[i][j] << " ";
			//cout << endl;
		}
		cout << ans << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}