#include<bits/stdc++.h>
using namespace std;
long long n,t,ans,cnt[200005],sum=1e9,gcd;
char l;
string s,ns;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%lld %c",&n,&l);
		gcd=__gcd(n,gcd);
		cnt[i]=n;
		s+=l;
	}
	
	for(int i=0;i<t;i++)
	{
		for(int j=0;j<cnt[i];j+=gcd)
		ns+=s[i];
	}
	sum=ns.size();
	for(int i=0;i<sum/2;i++)
	{
		if(ns[i]!=ns[sum-i-1])ans+=gcd;
	}
	printf("%lld",ans);
	return 0;
 } 
