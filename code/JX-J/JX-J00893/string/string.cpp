#include<bits/stdc++.h>
using namespace std;
long long n,ans=0,l=0,s[200000001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		long long a;
		char c;
		cin>>a>>c;
		for(long long i=1;i<=a;i++)
		{
			l++;
			s[l]=c-'a';
		}
	}
	for(long long i=1;i<=l/2;i++)if(s[i]!=s[l+1-i])ans++;
	cout<<ans;
	return 0;
}
