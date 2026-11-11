#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000006],b[2000005],e[2000005];
bool check(int p,int q)
{
	int l=p,r=q,mid,ll,rr;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(a[mid]<=a[p]+d)l=mid+1;
		else r=mid-1;
	}
	rr=r;
	l=p,r=q;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(a[mid]<a[q]-d)l=mid+1;
		else r=mid-1;
	}
//	cout<<p<<" "<<q<<" "<<l<<" "<<rr<<endl;
	return rr-l+1==2;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		a[n+1]=a[n]+d+1;
		a[0]=a[1]-d-1;
		b[1]=1;
		e[n]=n;
		for(int i=2;i<=n;i++)
		{
			if(a[i]-d>a[i-2] && a[i]-d<=a[i-1] &&a[i+1]-d>a[i-1])
				b[i]=b[i-1];
			else b[i]=i;
		}
		for(int i=n-1;i>=1;i--)
		{
			if(a[i]+d>=a[i+1] && a[i]+d<a[i+2] && a[i-1]+d<a[i+1])
				e[i]=e[i+1];
			else e[i]=i;
		}
//		for(int i=1;i<=n;i++)cout<<b[i]<<" "<<e[i]<<endl;
		for(int i=1;i<=n-3;i++)
		{
			for(int j=i+3;j<=n;j++)
			{
				if(check(i,j))
				ans+=(i-b[i]+1)*(e[j]-j+1);
			}
		}
			
		cout<<ans<<endl;
		
	}
	return 0;
}

