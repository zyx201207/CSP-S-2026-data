#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[50005],qian[50005]={0},chu[50001],qqian[50001],h[50001];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool f1=true;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(i>1&&a[i]-a[i-1]!=a[i-1]-a[i-2])f1=false;
	}
	sort(a,a+n);
	qian[0]=a[1]-a[0];
	for(int i=2;i<n;i++)
		qian[i-1]=a[i]-a[i-1];
	qqian[0]=qian[0];
	for(int i=1;i<n-1;i++)
		qqian[i]=qian[i]+qqian[i-1];
	if(f1)
	{
		int k=1,p=a[1]-a[0];
		for(k=1;k<n;k++)
		{
			if(k*p*(k+1)/2>=m)break;
		}
		return 0;
	}
	int ans=0;
	chu[0]=qian[0];
	for(int i=1;i<n;i++)
	{
		chu[i]=chu[i-1]+(i+1)*qian[i];
	}
	for(int i=0;i<n;i++)
	{
		h[i]=a[n-1]-a[i];
	}
	for(int i=0;i<n;i++)
	{
		if(chu[i]>m)
		{
			ans=i+1;
			break;
		}
	}
	for(int i=1;i<n-ans;i++)
	{
		if(chu[ans-2+i]-(h[i-1]-h[ans])<=m)
		{
			for(int j=i;i<n;i++)
			{
				if(chu[j]>m)
				{
					ans=max(ans,j-i+1);
					break;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
