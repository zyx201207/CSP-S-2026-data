#include<bits/stdc++.h>
using namespace std;
	long long n,m,l,r,ans,ans1=1,s1;
	long long a[500005];
	long long b[500005];
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
	b[i]=a[i]-a[i-1];
	}
	for(int i=2;i<=n;i++)
	{
		l=2;
		r=i;
		ans=0;
		int k=1;
			for(int j=l;j<=r;j++)
			{
				ans+=b[j]*k;
				k++;
			}
		if(ans<=m)
		{
		ans1=max(ans1,r-l+2);
		}
		else{
			while(ans>m)
			{
				l++;
				k=1;
				ans=0;
				for(int j=l;j<=r;j++)
				{
					ans+=b[l]*k;
					k++;
				}
			}	
		}
	}
	cout<<ans1;
	
	return 0;
 } 