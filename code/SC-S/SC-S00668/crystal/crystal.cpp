#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long n,m,k;
bool A()
{
	for(int i=0;i<n-1;i++)
		if(a[i]>a[i+1]) return true;
	return false;
}
	bool d()
{
	for(int i=0;i<n-1;i++)
		if(a[i]==a[i+1]) return false;
	return true;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	
	for(int i=0;i<n;i++) cin>>a[i];

	while(A())
		for(int i=0;i<n-1;i++)
			if(a[i]>a[i+1])
			{
				k=a[i];
				a[i]=a[i+1];
				a[i+1]=k;
			}
	if(d())
	{
		cout<<n;
		return 0;
	}
	int ans=1;
	for(int i=1;i<n;i++)
	{
		if(a[i]==a[i-1])
		{
			ans++;
		}
		else if(m-(a[i]-a[i-1])*ans>=0)
		{
			m-=(a[i]-a[i-1])*ans;
			ans++;
		}
		else if(m-(a[i]-a[i-1])*ans<0)
		{
			int count=a[i]-a[i-1];
			if(m/count>=ans)
			{
				ans=m/count;
			}
		}
	}
	
	cout<<endl<<ans;
	return 0;
} 