#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[2000010];
string s1;
string s2;
long long sum[2000005];
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>s1[i];
		sum[i]=a[i]+sum[i-1];
		//cout<<sum[i];
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=sum[i-1]+1;j<=sum[i];j++)
		{
			s2[j]=s1[i];
		}
	}
	long long mid=sum[n]/2;
	for(long long i=1;i<=mid;i++)
	{
		if(s2[i]!=s2[sum[n]-i+1]) ans++;
	}
	cout<<ans;
	return 0;
}
