#include <bits/stdc++.h>
using namespace std;
const int M=2e4+5,N=502;
int w[M];
int E[M][M+N];
int c,n,m,d,q1;
void Dijska(int x)
{
	queue<int> q;
	q.push(x);
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i=1;i<=m+n;i++)
		{
			for (int j=1;j<=m+n;j++)
			{
				if (E[x][j] > E[x][i] + E[i][j])
				{
					E[x][j] = E[j][x] = E[x][i] + E[i][j];
					q.push(j);
				}
			}
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(E,0x3f,sizeof(E));
	cin >> c >> n >> m >> d >> q1;
	for (int i=1;i<=m;i++)
	{
		cin >> w[i];
	}
	for (int i=1;i<=n;i++)
	{
		int k;
		cin >> k;
		for (int j=1;j<=k;j++)
		{
			int a,t;
			cin >> a >> t;
			E[a][m+i] = E[m+i][a] = t;
		}
	}
	for (int i=1;i<=q1;i++)
	{
		int xr,yr;
		cin >> xr >> yr;
		Dijska(xr);
		cout << E[xr][yr] + w[xr] + w[yr] << endl;
	}
	cout << endl;
	for (int i=1;i<=m+n;i++)
	{
		for (int j=1;j<=m+n;j++)
		{
			cout << E[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
