#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k;//分别表示测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过、出行计划数、第i条线路经过的地铁站数
long long s,f;
int w[100000],a[10000][10000],t[10000][10000];
int main()
{
	//==================================================== 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)
	{
		cin >> w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin >> k;
		for(int j=1;j<=k;j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin >> s >> f;
		cout << w[s]+w[f] << endl;
	}
	return 0;
} 
