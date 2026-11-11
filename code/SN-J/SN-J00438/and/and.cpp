#include <bits/stdc++.h>
using namespace std;
int er[1000000];
struct h
{
	long long p;
	string a;
}s[200005];
bool cp(h x,h y)
{
	return x.a>y.a;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].p;
		long long x=s[i].p;
		int j=1;
		while(x!=0)
		{
			long long mo=x%2;
			er[j]=mo;
			j++;
			x/=2;
		}
		for(j;j>=1;j--)
		{
			s[i].a+=er[j]+'0';
			er[j]=0;
		}
	}
	sort(s+1,s+1+n,cp);
	long long ans=s[1].p;
	for(int i=2;i<=m;i++)
	{
		ans&=s[i].p;
	}
	cout<<ans;
	return 0;
}
