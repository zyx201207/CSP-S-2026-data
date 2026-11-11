#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int w[500010],dis[510][510];
vector<pair<int,int>> sta[500010];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++)
	{
		dis[i][i] = 0;
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++)
		{
			int a,b;
			scanf(" %lld %lld ",&a,&b);
			for(int ij = 0;ij < sta[a].size();ij++)
			{
				int y = sta[a][ij].first,z = sta[a][ij].second;
				dis[i][y] = dis[y][i] = min(dis[i][y],z + b);
			}
			sta[a].push_back(make_pair(i,b));
		}
	}
	for(int i = 1;i <= n;i++) for(int j = 1;j < i;j++) for(int k = j + 1;k < i;k++)
	{
		dis[j][k] = dis[k][j] = min(dis[j][k],dis[j][i] + dis[k][i]);
		dis[i][k] = dis[k][i] = min(dis[i][k],dis[j][k] + dis[i][j]);
		dis[i][j] = dis[j][i] = min(dis[i][j],dis[i][k] + dis[k][j]);		
	}
	while(q--)
	{
		int x,y,ans = 100000000000000000;
		scanf(" %lld %lld ",&x,&y);
		for(int i = 0;i < sta[x].size();i++) for(int j = 0;j < sta[y].size();j++)
			ans = min(ans,sta[x][i].second + sta[y][j].second + dis[sta[x][i].first][sta[y][j].first]);
		cout << ans + w[x] + w[y] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
