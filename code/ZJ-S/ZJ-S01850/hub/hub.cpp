#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],he=0,mm=0,ji,we=0,tong[500005];
int ans=1;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i) mm=1;
		if(i==2) ji=a[i]-a[i-1];
		if(i>2&&ji!=a[i]-a[i-1]) we=1;
	}
	if(mm==0)
	{
		long long y=sqrt(m*2);
		while(y*(y+1)/2<=m) y++;
		cout<<y;
		return 0;
	}
	if(we==0)
	{
		long long y=sqrt(m*2/ji);
		while(y*y*ji/2<=m) y++;
		cout<<y;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		he=a[i]+he;
		tong[i]=a[i]*i-he;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(tong[j]-tong[i]-(a[j]-a[i])*(i-1)<=m) ans=max(j-i+1,ans);
			else j=n;
		}
	}
	cout<<ans;
	return 0;
}