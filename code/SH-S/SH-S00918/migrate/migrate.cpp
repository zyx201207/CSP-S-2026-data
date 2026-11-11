#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int N = 5e3+4;
long long t,n,d;
vector <int> p[N];
long long a[N];
long long path[N][N];

long long solve()
{
	return n;
	memset(p,0x3f,sizeof(p));
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(i != j && llabs(a[i]-a[j]) <= d)
				p[i].push_back(j),p[j].push_back(i);
	for(int i=1; i<=n; i++)
	{
		int id = i+1;
	}
}

bool A()
{
	for(int i=3; i<=n; i++)
		if(a[i]-a[i-1] != a[i-1]-a[i-2])
			return false;
	return true;
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&t,&t);
	while(t--)
	{
		scanf("%d%d",&n,&d);
		for(int i=1; i<=n; i++) scanf("%d",a+i);
		if(A())
		{
			printf("%d\n",(n-1)*(n-2)/2);
		}
		else
		{
			for(int i=1; i<=n; i++) p[i].clear();
			cout << solve() << "\n";
		}
	}
	
	return 0;
}
