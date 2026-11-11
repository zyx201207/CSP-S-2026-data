#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],s[500005];
long long m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=1;
	}
	sort(a+1,a+n+1);
	for(long long i=n;i>=1;i--)
	{
		long long cnt=m;
		int t=i-1;
		while(t>0)
		{
			cnt=cnt-(a[i]-a[t]);
			if(cnt<0)break;
			s[i]++;
			t--;
		}
	}
	long long maxn=-1;
	for(long long i=1;i<=n;i++)
	{
		maxn=max(maxn,s[i]);
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
