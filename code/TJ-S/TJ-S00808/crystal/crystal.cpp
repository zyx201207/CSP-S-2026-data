#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
long long n,m;
int flag2=1;
long long f[N];
long long ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int c=a[2]-a[1];
	for(int i=3;i<=n;i++)
	{
		if(a[i]-a[i-1]!=c)
		{
			flag2=0;
			break;
		}
	}
	sort(a+1,a+1+n);
	if(flag2==1)
	{
		for(int i=1;;i++)
		{
			if(m-(i*c)<0) break;
			m-=(i*c);
			ans++;
		}
		cout<<ans+1;
		return 0;
	}
	long long l=1,r=n;
	while(l<=r)
	{
		long long mid=(l+r)/2;
	//	cout<<mid<<" "<<l<<" "<<r<<" "<<endl;
		int flag=1;
		long long m2=m;
		for(int i=1;i<=mid;i++)
		{
			if(m2-abs(a[mid]-a[i])<0) 
			{
				flag=0;
				break;
			}
			m2-=abs(a[mid]-a[i]);
	//		cout<<m2<<" ";
		}
	//	cout<<endl;
		if(flag==0)
		{
			r=mid-1;
		}
		else
		{
			ans=mid;
			l=mid+1;
		}
		
	}
	long long ans2=ans;
	for(int i=ans2+1;i<=n;i++)
	{
		if(a[i]==a[ans2]) ans++;
		else break;
	}
	cout<<ans;
	return 0;
}

