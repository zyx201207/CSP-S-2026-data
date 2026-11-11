#include<bits/stdc++.h>
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define ull unsigned long long
#define int long long
#define endl '\n'
using namespace std;
int w[500010];
int k[510];
vector<int>f[510];
int v[501][501];
int a[555555],t[555555];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	IO;
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=500;i++)
	{
		for(int j=1;j<=500;j++)
		{
			if(i==j)
			{
				continue;
			}
			v[i][j]=LLONG_MAX;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin >> w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin >> k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin >> a[j] >> t[j];
		}
		for(int j=1;j<=k[i];j++)
		{
			for(int p=j;p<=k[i];p++)
			{
				v[a[j]][a[p]]=min(v[a[j]][a[p]],t[j]+t[p]);
				f[a[j]].push_back(a[p]);
				f[a[p]].push_back(a[j]);
			}
		}
	}
	return 0;
}

