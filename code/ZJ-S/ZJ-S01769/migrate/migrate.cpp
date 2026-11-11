# include <bits/stdc++.h>
# define int long long 

using namespace std ;

const int N = 500 ;
const int M = 20 ;

int x[N + 5] ;

int F[N + 5][M + 5] ;
int G[N + 5][N + 5] ;
//vector<int> v[N + 5] ;
//int mp[N + 5] ;
//int ans[N + 5] ;
//
int solve(int l, int r)
{
	int ans = 0 ;
	
	for(int i = M ; i >= 0 ; i --)
	{
		if(F[l][i] < r)
		{
			l = F[l][i] ;
			ans = ans + (1 << i) ;
		}
	}
	
	l = F[l][0] ;
	ans = ans + 1 ;
	
	if(l < r) return -1 ;
	
	return ans ;
}

signed main()
{
	freopen("migrate.in", "r", stdin) ;
	freopen("migrate.out", "w", stdout) ;
	
	ios::sync_with_stdio(false) ;
	cin.tie(0) ; cout.tie(0) ;
	
	int c, T ;
	cin >> c >> T ;
	
	while(T --)
	{
		int n, d ;
		cin >> n >> d ;
		
		for(int i = 1 ; i <= n ; i ++)
		{
			cin >> x[i] ;
//			v[i].clear() ;
		}
		
		int pos = 1 ;
		
		for(int i = 1 ; i <= n ; i ++)
		{
			while(pos + 1 <= n && x[pos + 1] - x[i] <= d) pos = pos + 1 ;
			F[i][0] = pos ;
//			mp[F[i][0]] = i ;
//			cout << F[i][0] << ' ' ;
		}
//		
//		cout << '\n' ;
//		
//		for(int i = 1 ; i <= n ; i ++)
//		{
//			int pos = F[i][0] ;
//			
//			if(F[pos][0] == pos)
//			{
//				v[i].push_back(pos) ;
//				continue ;
//			}
//			
//			while(pos - 1 > i && F[pos - 1][0] == F[F[i][0]][0]) pos = pos - 1 ;
//			
//			for(int j = pos ; j <= F[i][0] ; j ++)
//			{
//				v[i].push_back(j) ;
//			}
//			
//			cout << i << ' ' << v[i].size() << '\n' ;
//		}
		
//		int ans = 0 ;
//		
//		for(int i = 1 ; i <= n ; i ++)
//		{
//			for(int j = i + 1 ; j <= n ; j ++)
//			{
//				int flag = 1, cnt = 0 ;
//				int x = i ;
//				
//				while(x < j)
//				{
//					if(v[x].size() > 2)
//					{
//						flag = 0 ;
//						break ;
//					}
//					
//					if(v[x].size() == 2)
//					{
//						int y1 = v[x][0], y2 = v[x][1] ;
//						
//						if(F[y1][0] != F[y2][0])
//						{
//							flag = 0 ;
//							break ;
//						}
//						else 
//						{
//							x = F[y1][0] ;
//							cnt = cnt + 1 ;
//						}
//					}
//					
//					if(v[x].size() == 1)
//					{
//						x = F[x][0] ;
//					}
//					
//					cout << i << ' ' << j << ' ' << x << '\n' ;
//				}
//				
//				if(flag && cnt == 1 && x == j) 
//				{
//					cout << i << ' ' << j << '\n' ;
//					ans = ans + 1 ;
//				}
//			}
//		}
		
//		cout << ans << '\n' ;
			
//		cout << '\n' ;
//		
		for(int j = 1 ; j <= M ; j ++)
		{
			for(int i = 1 ; i <= n ; i ++)
			{
				F[i][j] = F[F[i][j - 1]][j - 1] ;
			}
		}
		
		for(int i = 1 ; i <= n ; i ++) G[i][i] = 1 ;		
		
		int ans = 0 ;		
		
		for(int i = 1 ; i <= n ; i ++)
		{
			for(int j = i + 1 ; j <= n ; j ++)
			{
				int flag = 1, cnt = 0 ;
				
				for(int k = i ; k <= j ; k ++)
				{
					if(G[i][k])
					{
						if(solve(F[k][0], j) == -1 || x[j] - x[k] <= d) continue ;
						
						if(F[k][0] - 1 > k && solve(F[k][0], j) == solve(F[k][0] - 1, j)) 
						{
							if(F[k][0] - 2 > i && solve(F[k][0], j) == solve(F[k][0] - 2, j)) flag = 0 ;
							cnt = cnt + 1 ;
						}
					}
				}
				
				if(flag && cnt == 1) ans = ans + 1 ;
				
//				if(solve(F[i][0], j) == -1 || x[j] - x[i] <= d) continue ;
//				
//				if(F[i][0] - 1 > i && solve(F[i][0], j) == solve(F[i][0] - 1, j)) 
//				{
//					if(F[i][0] - 2 > i && solve(F[i][0], j) == solve(F[i][0] - 2, j)) continue ;
//					cout << i << ' ' << j << '\n' ;
//					ans[i] = ans[i] + 1 ;
//				}
			}
		}
		
		cout << ans << '\n' ;
//		
//		for(int i = n ; i >= 1 ; i --)
//		{
//			ans[mp[i]] += ans[i] ;
//		}
//		
//		int sum = 0 ;
//		
//		for(int i = 1 ; i <= n ; i ++) 
//		{
//			sum += ans[i] ;
//			mp[i] = ans[i] = 0 ;
//		}
//		
//		cout << sum << '\n' ;
	}
	
	return 0 ;
}
