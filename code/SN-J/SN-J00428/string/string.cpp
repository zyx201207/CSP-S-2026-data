#include<bits/stdc++.h>
using namespace std;
long long n,a[300005];
char s[500005];
long long com=1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld %c",&a[i],&s[i]);
		if(s[i]==s[i-1] && i>1) com++;
	}
	if(n<2) printf("0");
	else if(com==n) printf("0");
	else if(n==2)
	{
		if(a[1]==a[2])  printf("0");
		else printf("%lld",min(a[1],a[2]));
	}
	
	return 0;
}
