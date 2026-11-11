#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int N = 310;

int g[N][N][N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("migrate3.in", "r", stdin);
	freopen("migrate3.out", "w", stdout);
	
	int c, t;
	cin >> c >> t;
	
	while(t --){
		int n;
		LL d;
		cin >> n >> d;
		vector<LL> x(n + 1);
		for(int i = 1;i <= n; i ++)		cin >> x[i];
		
		vector<vector<int>> f(n + 1, vector<int>(n + 1, 2e9));
		
		for(int i = 1;i <= n; i ++)
			f[i][i] = 0;
			
		/*
			0 1
			5 3
			-2 -1 0 1 2
		*/
		
		for(int i = 1;i <= n; i ++)
			for(int j = i + 1;j <= n; j ++)
				f[i][j] = (x[j] - x[i] <= d ? 1 : 2e9);
			
//		for(int i = 1;i <= n; i ++)
//			for(int j = i + 1;j <= n; j ++)
//				for(int k = i + 1;k <= j - 1; k ++)
//					f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
		for(int len = 1;len <= n; len ++){
			for(int l = 1;l + len - 1 <= n; l ++){
				int r = l + len - 1;
				for(int k = l;k <= r; k ++){
					f[l][r] = min(f[l][k] + f[k][r], f[l][r]);
					
				}
			}
		}
		
		
		int ans = 0;
		for(int l = 1;l <= n; l ++){
			for(int r = l + 1;r <= n; r ++){
				int cnt = 0;
				for(int k = l + 1;k <= r - 1; k ++){
					if(f[l][k] + f[k][r] == f[l][r])
						cnt ++;
				}
				ans += (cnt == 2);
			}

		}
		cout << ans << '\n';
	}

	
	
	return 0;
}
