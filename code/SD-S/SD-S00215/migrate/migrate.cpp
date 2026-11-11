#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

const int N=1e6+10;
long long a[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	for(int iii=0;iii<=t-1;iii++)
	{
		int n,d;
		scanf("%d%d",&n,&d);
		for(int i=0;i<=n-1;i++)
			scanf("%lld",&a[i]);
		int num=0;
		int gx=a[1]-a[0];
		for(int i=0;i<=n-1-(d+1)*gx;i++)
		{
			int bj=(i+d+1)*gx,js=0;
			for(int j=i+1;j<=i+(d+1)*gx-1;j++)
				if(a[i]+d>=a[j]||a[j]+d>=a[bj])
					js++;
			if(js==2)
				num++;
		}
		printf("%d\n",num);
	}
	return 0;
}
