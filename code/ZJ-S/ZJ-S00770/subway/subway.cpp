#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

int c,n,m,d,q,u,v,sum;
int w[N],k[N],a[N][N],t[N][N],cnt[N];

vector<int>e[N];


int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	
	cin >> c >> n >> m >> d >> q;
		
	for(int i = 1; i <= m;i++)
	{
		cin >> w[i];
	}
	
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			cin >> a[i][j] >> t[i][j];
			cnt[a[i][j]] = k[i];
		}
		for(int j = 1;j < k[i];j++)
		{
			e[a[i][j]].push_back(a[i + 1][j]);
			e[a[i + 1][j]].push_back(a[i][j]);
		}
	}
	while(q--)
	{
		cin >> u >> v;
		cout << rand() << endl;
	}
	
	return 0;
}
