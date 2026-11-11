#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w[500005],k[500005];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out","w", stdout);
	int c,n,m,d,q;
	vector<ll> a[500];
	vector<ll> t[500];
	vector<ll> x2[5005];
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i=1;i<=m;i++)scanf("%lld", &w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d", &k[i]);
		for(int j=1;j<=k[i];j++)
		{
			int ai,ti;
			scanf("%d%d", &ai, &ti);
			a[i].push_back(ai);
			t[i].push_back(ti);
			x2[ai].push_back(i);
		}
	}
	while(q--)
	{
		int x,y,ans=0;
		scanf("%d%d", &x, &y);
		int xt=0,yt=0;
		for(int i=1;i<=k[1];i++)
		{
			if(a[1][i]==x)xt=t[1][i];
			if(a[1][i]==y)yt=t[1][i];
		}
		ans=xt+yt+w[x]+w[y];
		printf("%d", ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
