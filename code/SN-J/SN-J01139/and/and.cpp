#include<bits/stdc++.h>
using namespace std;
#define int long long

const int M = 2005;

int n,m;
int a[M];
int f[M][M][2];



namespace ljn
{
	void solve()
	{
		freopen("and.in","r",stdin);
		freopen("and.out","w",stdout);
		ios::sync_with_stdio(false);
		cin.tie(0);
		memset(f,0,sizeof(f));
		
		cin >> n >> m;
		int mx = 0;
		int cnt = 0;
		int mn = 0;
		for(int i = 1 ; i <= n ; i++)
		{
			cin >> a[i];
			mx = max(mx,a[i]);
			cnt++;
		} 
		if(cnt == 1)
		{
			for(int i = 1 ; i <= n ; i++)
			{
				if(a[i] != mx)
				{
					mn = max(mn,a[i]);
				 } 
			} 
		 } 
		else
		{
			cout << mx << '\n';
			return ;
		}
		for(int i = 1 ; i <= m ; i++)
		{
			f[i][1][1] = a[i];
		}
		sort(a + 1,a + n + 1);
		if(n >= 2005)
		{
			cout << a[m];
			return ;
		} 
		if(m == 1)
		{
			cout << mx;
			return ;
		}
		if(m == 2)
		{
			cout << (mx & mn) << '\n';
			return ;
		}
		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = 1 ; j <= min(i,m) ; j++)
			{
				f[i][j][0] = max(f[i][j][0],max(f[i - 1][j][1],f[i - 1][j][0]));
				f[i][j][1] = max(f[i][j][1],max(f[i - 1][j - 1][0] & a[i],f[i - 1][j - 1][1] & a[i]));
			}
		}
		cout << max(f[n][m][0],f[n][m][1]);
		
		return ;
	}
}
signed main()
{
	ljn::solve();
	return 0;
}
/*
5 3
31 3 1 15 7
*/
