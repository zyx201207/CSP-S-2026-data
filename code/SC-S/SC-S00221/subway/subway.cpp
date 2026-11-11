#include <cstdio>
#include <iostream>
#include <algorithm>

#include <vector>

using namespace std;

const long long MAX = 505,MAX1 = 5 * 1e5 + 5,INF = 0x3f3f3f3f;

struct s{
	long long a,t;
	s(long long _a,long long _t){ a = _a;t = _t; }
};

long long c,n,m,d,p;
vector<s> f[MAX1];
long long dp[MAX][MAX],w[MAX1];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	for(long long i = 1;i <= n;++i)
		for(long long j = 1;j <= n;++j)
			if(i != j)	dp[i][j] = INF;
	
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&p);
	for(long long i = 1;i <= m;++i)	scanf("%d",&w[i]);
	
	for(long long i = 1;i <= n;++i){
		long long k;scanf("%d",&k);
		
		for(long long j = 1;j <= k;++j){
			long long a,t;scanf("%d%d",&a,&t);
			f[a].push_back(s(i,t));
		}
	}
	
	for(long long k = 1;k <= m;++k)
		for(long long i = 0;i < f[k].size();++i)
			for(long long j = 0;j < f[k].size();++j)
				if(f[k][i].a != f[k][j].a)	dp[f[k][i].a][f[k][j].a] = dp[f[k][j].a][f[k][i].a] = f[k][i].t + f[k][j].t;
	
	for(long long k = 1;k <= n;++k)
		for(long long i = 1;i <= n;++i)
			for(long long j = 1;j <= n;++j)
				dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j]);
	
	while(p--){
		long long x,y;scanf("%d%d",&x,&y);
		
		long long ans = -1;
		for(long long i = 0;i < f[x].size();++i)
			for(long long j = 0;j < f[y].size();++j)
				if(ans != -1)	ans = min(ans,dp[f[x][i].a][f[y][j].a] + f[x][i].t + f[y][j].t);
				else	ans = dp[f[x][i].a][f[y][j].a] + f[x][i].t + f[y][j].t;
		
		cout << ans + w[x] + w[y] << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}