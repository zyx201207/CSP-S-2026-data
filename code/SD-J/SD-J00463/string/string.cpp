#include <iostream>
#include <cstdio>
using namespace std;
char b[400000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[200010];
	char c[200010];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int t=1;
	int k;
	for(int i=1;i<=n;i++)
	{
		k=t;
		for(int j=k;j<=k+a[i];j++)
		{
			b[t]=c[i];
			t++;
		}
	}
	long long s;
	s=0;
	for(int i=1;i<=n;i++)
	{
		s=s+a[i];
	}
	int ans;
	ans=0;
	for(int i=1;i<=s;i++)
	{
		if(b[i]!=b[s-i])
		{
			ans++;
		}
	}
	cout<<ans-1;
	return 0;
}
