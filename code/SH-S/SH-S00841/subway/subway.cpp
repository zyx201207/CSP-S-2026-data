#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[10005],k,a[1005][1005],t[1005][1005],x,y,solve[1005][1005];
vector<int> e[1005];
int main()
{
	cin >>c >>n >> m >> d >> q;
	for (int i = 1;i <= m;i++)
	{
		cin >> w[i]; 
	}
	for (int i = 1;i = n;i++)
	{
		cin >> k;
		for (int j = 1;j <= k;j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	while(q--)
	{
		cin >> x >>y;
		long long ans = w[x]+w[y];
		
	}
}
