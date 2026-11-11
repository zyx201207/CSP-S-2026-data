#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500500],s[500500],ans,num,mm,s1[500500],s2[500500];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		s[i]=a[n]-a[i];
	}
	for(int i=1;i<=n-1;i++)
	{
		s1[i]=s[i]*i;
		s2[i]=s2[i-1]+s[i];
	}
	for(int i=1;i<=n;i++)
	{
		num=mm=0;
		for(int j=i;j>=1;j--)
		{
			if(mm+s[j]-s[i]>m)break;
			mm+=s[j]-s[i];
			num++;
		}
		ans=max(num,ans);
	}
	cout<<ans;
	return 0;
}