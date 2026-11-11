#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 25,M = 1e4 + 10;

int c,n,m,q,d,t_sum = 0;
int w[N],k[N],a[M][M],t[M][M];
bool liant[M][M];

bool cmp1(int a,int b)
{
	return a < b;
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++)
	{
		cin >> w[i];
	}
	for(int i = 1;i <= n;i ++)
	{
		cin >> k[i];
		for(int j = 1;j <= k[i];j ++)
		{
			cin >> a[i][j] ;
			cin >> t[i][a[i][j]];
		}
	}
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 1;j <= m;j ++)
		{
			if(t[i][j] != 0) liant[i][j] = true;
		}
		cout << endl;
	}
	while(q --)
	{
		t_sum = 0;
		int x,y;
		cin >> x >> y;
		t_sum += w[x] + w[y];
		bool flag = false;
		int l = 1,r = 1;
		for(int i = 1;i <= n;i ++)
		{
			if(liant[i][x] == true && liant[i][y] == true)
			{
				t_sum += t[i][x] + t[i][y];
				break;
			} 
		}
		cout << t_sum << endl;
	}
	return 0;
}
