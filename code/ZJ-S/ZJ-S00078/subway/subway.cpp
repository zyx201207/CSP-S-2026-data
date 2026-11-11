#include<bits/stdc++.h>
using namespace std;
#define int long long
struct te
{
	int a,t;
};
int c,n,m,d,q;
int sta,fis;
int w[500050];
//len[i][j] = len i 's station j 's time
vector<te> len[550];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++)
	{
		int k;cin >> k;
		for(int j = 1;j <= k;j++)
		{
			int a,t;cin >> a >> t;
			len[i].push_back({a,t});
		}
	}
	while(q--)
	{
		cin >> sta >> fis;
		int sum = 0;
		for(int i = 1;i <= n;i++)
		{
			for(auto it:len[i])
			{
				if(it.a == sta) sum += w[sta];
				else if(it.a == fis) sum += w[fis];
			}
		}
		cout << sum << endl;
	}
	return 0;
}
