#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	vector<long long>a(n+1);
	vector<char>c(n+1);
	for(long long i=1;i<=n;i++)cin>>a[i]>>c[i];
	string s1;
	for(long long j=1;j<=n;j++)
	{ 
		for(long long z=1;z<=a[j];z++)s1+=c[j];
	}
	long long sum=s1.size();
	 long long zw=sum/2;
	 long long ans=0;
	 string q,h;
	 if(sum%2==0)
	{
		for(long long j=1;j<=zw;j++)q+=s1[j];
		for(long long z=sum+1;z>zw;z--)h+=s1[z];
	}
	else 
	{
		for(long long j=1;j<=zw;j++)q+=s1[j];
		for(long long z=sum+1;z>zw+1;z--)h+=s1[z];
	}
	for(long long i=1;i<=zw;i++)
	{
		if(q[i]!=h[i])ans++;
	}
	cout<<ans;
	 return 0;
}
