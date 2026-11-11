#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,l=0;
    scanf("%lld",&n);
    long long a;
	string c,s="";
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a);
		cin>>c;
		l+=a;
		for(long long j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	long long ans=0;
	for(long long i=0;i<l/2;i++)
	{
		if(s[i]!=s[l-i-1])
		{
			ans++;
		}
	}
	printf("%lld",ans);
    return 0;
}
