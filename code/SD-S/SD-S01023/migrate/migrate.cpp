#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;
long long c,t;
long long x[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		long long n,d;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&x[i]);
		}
		if(d>2*(x[2]-x[1]) && d<3*(x[2]-x[1]))
		{
			cout<<n-3;
		}
		else
		{
			cout<<"0";
		}
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
