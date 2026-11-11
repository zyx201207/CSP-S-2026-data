#include<bits/stdc++.h>
using namespace std;
long long c,m,n,d,q,ans;
long long w[500005],k[500005],a[505][20005],t[505][20005];
vector<pair<long long,long long> >G[500005];
long long x[100005],y[100005];
bool flag[505][20005]; 
void dfs(long long xianlu,long long zhan,long long target,long long cnt)
{
	if(a[xianlu][zhan] == target) ans = min(ans,cnt);
	else
	{
		flag[xianlu][zhan] = true;
		if(zhan != k[xianlu] && flag[xianlu][zhan + 1] == false) dfs(xianlu,zhan + 1,target,cnt);
		else if(zhan != 1 && flag[xianlu][zhan - 1] == false) dfs(xianlu,zhan - 1,target,cnt);
		else flag[xianlu][zhan] = true;
		int zt = a[xianlu][zhan];
		cnt += t[xianlu][zhan];
		for(long long i = 0;i < G[zt].size();i++)
		{
			pair<long long,long long>num1 = G[zt][i];
			if(flag[num1.first][num1.second] == false) dfs(num1.first,num1.second,target,cnt + t[num1.first][num1.second]);
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++) cin>>w[i];
	for(int i = 1;i <= n;i++)
	{
		cin>>k[i];
		for(int j = 1;j <= k[i];j++) cin>>a[i][j]>>t[i][j];
		for(int j = 1;j <= k[i];j++) G[a[i][j]].push_back({i,j});
	}
	for(int i = 1;i <= q;i++)
	{
		for(int j = 1;j <= m;j++) flag[i][j] = false;
		cin>>x[i]>>y[i];
		
		dfs(G[x[i]][0].first,G[x[i]][0].second,y[i],t[G[x[i]][0].first][G[x[i]][0].second]);
		ans += (w[x[i]] + w[y[i]]);
		//cout<<t[G[x[i]][0].first][G[x[i]][0].second]<<endl;
		cout<<ans<<endl;
	}
	return 0;
}
