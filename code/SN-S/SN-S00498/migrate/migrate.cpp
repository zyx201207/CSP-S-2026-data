//柳奕曦 西安市含光中学 考号SN-S00498
//liuyixi xi an shi han guang zhong xue SN-S00498 
#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000100];	

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int c;
	int T;
	cin >>c;
	if(c == 11 || c == 12)
	{
		cin >> T;
		while(T--)
		{
			memset(a,0,sizeof(a));
			int n,d;
			cin >> n >> d;
			for(int i = 1; i <= n; i++)
			{
				cin >> a[i];
			}
			int gc = a[2]-a[1];
			if(gc >= d)
			{
				cout << 0 << "\n";
				continue;
			}
			else 
			{
				int dd = d/gc;
				dd = dd+dd-1;
				if(n-dd <0) cout << 0 << "\n";
				else cout << n-dd <<'\n';
				continue;
			}
		}
		return 0;
	}
	else if(c >= 1 && c <= 10)
	{
		cin >> T;
		while(T--)
		{
			memset(a,0,sizeof(a));
			int n,d;
			cin >> n >> d;
			for(int i = 1; i <= n; i++)
			{
				cin >> a[i];
			}
			int ans = 0;
			for(int i = 1; i <= n; i++)
			{
				for(int j=i+1; j <= n; j++)
				{
					//i起点
					//j终点
					int cnt = 0;
					for(int ii = i+1;ii <= j-1 ; ii++)
					{
						int dist1 = a[ii]-a[i];
						int dist2 = a[j]-a[ii];
						if(dist1 <= d && dist2 <= d) cnt++;	
					} 
					if(cnt == 2) ans++;
				}
			}
			cout << ans << '\n';
		}
	}
	else if(c == 13 || c == 14)
	{
		cin >> T;
		while(T--)
		{
			memset(a,0,sizeof(a));
			int n,d;
			cin >> n >> d;
			for(int i = 1; i <= n; i++)
			{
				cin >> a[i];
			}
			int ans = 0;
			for(int i = 1; i <= n; i++)
			{
				for(int j=i+1 ; j <= n; j++)
				{
					int dist = a[j]-a[i];
					if((dist == d+d-1) && j-1 >= 3) ans++;
				}
			}
			cout << ans << '\n';
		}
		return 0;
	}
	return 0;
}
//时间18:12 解决两个特殊性质A&B，期望得分16分.
//其他样例预计可得4分.
 
