#include<bits/stdc++.h>
using namespace std;
const long long N=1145141919810114514;
long long s=2,d;
long long m,n;
long long b[100010]={0},mnb=9999999,c[100010]={0};
long long a[100010],ans=0,mxans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		if(i>=2)
			if(a[i]-a[i-1]==a[i-1]-a[i-2])
			{
				s=2;
				d=a[i]-a[i-1];
			}
			else
				s=0;
	}
	if(m==0)
	{
		long long mx=0,mxx=0;
		for(int i=0;i<n;i++)
		{
			b[a[i]]++;
			if(a[i]>mx)
				mx=a[i];
		}
		for(int i=0;i<mx;i++)
			if(b[i]>mxx)
				mxx=b[i];
		cout<<mxx;
		return 0;
	}
	if(s==2)
	{
		long long i=d,d1=d;
		while(m>=i&&ans<n-1)
		{
			m-=i;
			ans++;
			i+=d1;
		}
		cout<<ans+1;
	}
	bool cont=1;
	while(m>0)
	{
		mnb=9999999;
		for(int i=0;i<n-1;i++)
		{
			b[i]=abs(a[i]-a[i+1]);
			if(b[i]<mnb&&b[i]!=0)
				mnb=b[i];
		}
		for(int i=0;i<n-1;i++)
		{
			if(b[i]==mnb)
			{
				a[i]+=b[i];
				m-=b[i];
				b[i]=0;
				break;
			}
		}
	}
			long long mx=0,mxx=0;
	for(int i=0;i<n;i++)
		{
			c[a[i]]++;
			if(a[i]>mx)
				mx=a[i];
		}
	for(int i=0;i<mx;i++)
			if(c[i]>mxx)
				mxx=c[i];
		cout<<mxx;
	return 0;
 } 
