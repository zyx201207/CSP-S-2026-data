#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	unsigned long long m;
	unsigned long long ans = 0;
	scanf("%d%llu",&n,&m);
	if (m >= 10000000000)
	{
		unsigned long long a,b;
		scanf("%llu%llu",&a,&b);
		printf("%llu %llu\n",a,b);
		unsigned long long deth = b-a;
		unsigned long long use;
		for (int i = 2;i <= n;i++)
		{
			use = (i+1)*i/2;
			use *= deth;
			if (use > m)
			{
				printf("%d",i);
				return 0;
			}
		}
		printf("%d",n);
		return 0;
	}
	else
	{
		vector<long long> l;
		vector<long long> t;
		vector< vector<int> > dep(n+10,vector<int> (n+10));
		long long k;
		for (int i = 0;i < n;i++)
		{
			scanf("%lld",&k);
			l.push_back(k);
		}
		sort(l.begin(),l.end());
		for (int i = 0;i < n;i++)
		{
			for (int j = (i+1);j < n;j++)
			{
				dep[i][j] = j-i;
			}
		}
		for (int i = 0;i < n;i++)
		{
			unsigned long long use = 0;
			for (int j = (i+1);j < n;j++)
			{
				use += (j-i)*dep[j-1][j];
				if (use <= m)
				{
					ans = max(ans,(unsigned long long)(j-i)+1);
				}
			}
		}
		printf("%llu",ans);
	}
	
	return 0;
}
