#include<bits/stdc++.h>
using namespace std;
#define int long long
int w[500005];
int a[505][25];
int t[505][25];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c,n,m,d,q;
	for(int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++)
	{
		int k_;
		cin >> k_;
		for(int j = 1;j <= k_;j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	while(q--)
	{
		int x,y,f,e,f_,e_;
		cin >> x >> y;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= d;j++)
			{
				if(a[i][j] == x)
				{
					f = i;
					f_ = j;
					break;
				}
			}
		}
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= d;j++)
			{
				if(a[i][j] == y)
				{
					e = i;
					e_ = j;
					break;
				}
			}
		}
		cout << w[x]+w[y]+t[f][f_]+t[e][e_] << endl;
	}
	return 0;
}
