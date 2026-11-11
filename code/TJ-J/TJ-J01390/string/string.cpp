#include <bits/stdc++.h>
using namespace std;
long long a[200010];
char b[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.in","w",stdout);
	long long n,sum=0,l=1,r,num=0;
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		sum+=a[i];
	}
	sum/=2;
	while(sum>0)
	{
		if(b[l]!=b[r])
		{
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				sum-=a[r];
				num+=a[r];
				r-=1;
			}
			if(a[l]==a[r])
			{
				
				sum-=a[l];
				num+=a[r];
				l+=1;
				r-=1;
			}
			if(a[l]<a[r])
			{
				a[r]-=a[l];
				sum-=a[l];
				num+=a[l];
				l+=1;
			}
			
		}
		else
		{
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				sum-=a[r];
				r-=1;
			}
			if(a[l]==a[r])
			{
				
				sum-=a[l];
				l+=1;
				r-=1;
			}
			if(a[l]<a[r])
			{
				a[r]-=a[l];
				sum-=a[l];
				l+=1;
			}
		}
	}
	cout<<num;
	return 0;
}

