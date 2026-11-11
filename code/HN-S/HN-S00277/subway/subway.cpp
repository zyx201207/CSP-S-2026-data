#include<iostream>
#include<vector>
using namespace std;//¼ÇµÃ¿ªlonglong!!! 
const long long INF = 1e18;
long long c , n , m , d , q;
long long w[500010];
long long k[510];
long long dis[510][510];
vector<pair<int,int> > sta[500010];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;++i)
	{
		cin >> w[i];
	}
	for(int i = 1;i <= n;++i)
	{
		cin >> k[i];
		for(int j = 1;j <= k[i];++j)
		{
			int x , s;
			cin >> x >> s;
			sta[x].push_back({i,s});
		}
	}
	for(int i = 1;i <= n;++i)
	{
		for(int j = 1;j <= n;++j)
		{
			dis[i][j] = INF;
		}
//		dis[i][i] = 0;
	}
	for(int i = 1;i <= m;++i)
	{
		for(pair<int,int> pr1 : sta[i])
		{
			for(pair<int,int> pr2 : sta[i])
			{
				if(pr1.first == pr2.second)
				{
					continue; 
				}
				dis[pr2.first][pr1.first] = dis[pr1.first][pr2.first] = pr1.second+pr2.second;
			}
		}
	}
	//floyd
	for(int i = 1;i <= n;++i)
	{
		for(int j = 1;j <= n;++j)
		{
			for(int k = 1;k <= n;++k)
			{
				dis[j][i] = dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	//out
	for(int i = 1;i <= n;++i)
	{
		dis[i][i] = 0;
	}
	for(int i = 1;i <= q;++i)
	{
		int x , y;
		cin >> x >> y;
		long long minn = INF;
		for(pair<int,int> pr1 : sta[x])
		{
			for(pair<int,int> pr2 : sta[y])
			{
				minn = min(minn , dis[pr1.first][pr2.first]+pr1.second+pr2.second);
			}
		}
//		cout << minn << endl;
		long long ans = w[x]+w[y]+minn;
		cout << ans << '\n';
	}
	
	
	return 0;
}
