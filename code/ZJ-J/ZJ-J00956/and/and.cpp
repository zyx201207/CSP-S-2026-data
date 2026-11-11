#include<bits/stdc++.h>
using namespace std;
int n,m;
long long get;
long long maxx=-1;
long long s[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&s[i]);
	}
	sort(s+1,s+n+1,greater<int>());
	for(int i=1;i<=n-m;i++)
	{
		get=s[i];
		for(int j=i;j<=i+m-1;j++)
		{
			get&=s[j];
		}
		maxx=max(get,maxx);
	}
	printf("%d",maxx);
	return 0;
}