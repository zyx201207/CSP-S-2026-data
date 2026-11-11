#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q;

int main ()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;//c测试点编号 n地铁线数 m地铁站数 d最多 q计划数 
	vector<int> a(n);
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	vector<int> d(n);
	for (int i=1;i<=n;i++)
	{
		int k;
		cin >> k;
		vector<vector<int> >  b[k][n];
		vector<vector<int> >  c[k][n];
		for (int j=1;j<=k;j++)
		{
			cin >> b[j][i] >> c[j][i];
		}
	}
	for (int i=1;i<=q;i++)
	{
		int xr,yr;
		cin >> xr >> yr;
		d(i)=a[i]+b[1][i]+
	}
	for (int i=1;i<=n;i++)
	{
		cout << d(i) << "\n";
	}
	return 0;
} 
