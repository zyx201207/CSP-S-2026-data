#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

const int N = 500005;
int c,n,m,d,q;
int w[505];
int k[N],x,y;
int a[505][N],t[505][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> c >> n >> m >> d >> q; 
	for(int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for(int j = 1;j <= k[i];j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	while(q--)
	{
		sum = 0;
		cin >> x >> y;
		long long sum = w[x] + w[y];
		sum += t[1][x];
		sum += t[2][y];
		cout << sum << endl;
	}
	
	return 0;
} 
