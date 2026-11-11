#include <bits/stdc++.h>
using namespace std;
long long n,a;
char c;
string s="";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(long long j=1;j<=a;j++)s+=c;
	}
	long long ans=0;
	for(long long i=0;i<=s.length()/2-1;i++)
	{
		if(s[i]!=s[s.length()-1-i])ans++;
	}
	printf("%lld",ans);
}
