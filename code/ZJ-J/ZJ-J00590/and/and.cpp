#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,m;
long long a[N];
int f[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= n;i++)
	{
		scanf("%lld",&a[i]);
	}
	long long res = 0;
	for(int i = 29;i >= 0;i--)
	{
		int c = 0;
		for(int j = 1;j <= n;j++)
		{
			if(f[j]) continue;
			if(a[j] & (1LL << i)) c++;
		}
		if(c >= m)
		{
			res = (res | (1LL << i));
			for(int j = 1;j <= n;j++)
			{
				if(f[j]) continue;
				if(!(a[j] & (1LL << i))) f[j] = 1;
			}
		}
	}
	printf("%lld",res);
	return 0;
}
