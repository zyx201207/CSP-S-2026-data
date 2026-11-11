#include<bits/stdc++.h>
using namespace std;
const int N = 5010;
typedef long long LL;
LL a[N];
LL f[N][N],g[N][N];
int main()
{
	freopen("migrate3.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int id,t;
	cin>>id>>t;
	while(t --)
	{
		LL n,m;
		cin>>n>>m;
		for(int i = 1; i <= n; i ++) cin>>a[i];
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++) f[i][j] = 1e18,g[i][j] = 0;
		for(int i = 1; i <= n; i ++)
		{
			f[i][i] = 0,g[i][i] = 1;
			for(int j = i + 1; j <= n; j ++)
				for(int t = max(lower_bound(a + i,a + n + 1,a[j] - m) - a,1ll); t < j; t ++)
				{
					if(a[t] + m < a[j]) break;
					if(f[i][j] > f[i][t] + 1) f[i][j] = f[i][t] + 1,g[i][j] = g[i][t];
					else if(f[i][j] == f[i][t] + 1) g[i][j] += g[i][t];
				}
		}
		int cnt = 0;
		for(int i = 1; i <= n; i ++)
			for(int j = i; j <= n; j ++)
				if(g[i][j] == 2) cerr<<f[i][j]<<' ',cnt ++;
		cout<<cnt<<'\n';
	}
	return 0;
}
//bf
//f[i][j]表示i到j最短路径长度，辅助g[i][j]记录条数
//i,j中存在一个k，满足 
