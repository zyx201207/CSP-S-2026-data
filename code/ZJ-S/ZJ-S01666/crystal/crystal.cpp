#include<bits/stdc++.h>
using namespace std;
int a[500010],qian[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	long long n,m,ans=-0x3f3f3f3f;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++)
	{
		qian[i]=qian[i-1]+a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		long long l=1,r=i;
		long long mid=(l+r)/2;
	//	cout<<i<<endl;
		while(l<r)
		{
			
			long long mid=(l+r)/2;
			 
			if(qian[i-1]-qian[mid-1]+m>=a[i]*(i-mid))
			{
				r=mid;
			}
			else l=mid+1;
	//		cout<<l<<" "<<r<<" "<<mid<<endl;
		}
	//	cout<<"jieshu "<<l<<" "<<r<<" "<<mid<<endl;
	//	cout<<i-r<<endl;
		ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;	
} 
/*
5 5
1 2 4 8 9
*/
