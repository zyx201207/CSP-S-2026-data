#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("subway.in", "r", stdin);
//	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
	long long c, n, m , d, q;
	//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过,以及出行计划数
	cin >> c >> n >> m >> d >> q;
	vector<long long> sta(m);//time
	for(int i = 0; i < m; i++)
		cin >> sta[i];
	long long a[505][300000000000000];
	long long t[505][300000000000000];
	for(int i = 0; i < n; i++)
	{
		long long k1;
		cin >> k1;
		for(int j = 0; j < k1; j++)
			cin >> a[i][j] >> t[i][j];
	}
	long long x[30000000], y[30000000];
	for(int i = 0; i < q; i++)
	{
		cin >> x[i] >> y[i];
	}
	
	for(int i = 0; i < q; i++)
	{
		long long time = 0;
		time += sta[i];
	}
	return 0;
}
