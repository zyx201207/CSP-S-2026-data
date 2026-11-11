#include<bits/stdc++.h>
using namespace std;
long long int n,a[105],b[105];
char s[105],l[105];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	if(n==1)
	{
		scanf("%lld %c",&a[1],&s[1]);
		printf("0");
		return 0;
	}
	if(n==2)
	{
		scanf("%lld %c",&a[1],&s[1]);
		scanf("%lld %c",&b[1],&l[1]);
		if(s[1]==l[1])
		{
			printf("0");
			return 0;
		}
		else
		if(a[1]>b[1])
		{
			printf("%lld",b[1]);
			return 0;
		}
		else
		{
			printf("%lld",a[1]);
			return 0;
		}
	}
	return 0;
}