#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050],k,k2,bj=0,ls1,ls2;
double p=0;
long long bs()
{
	long long l=1,r=n,mid;
	while(l<r)
	{
		mid=l+(r-l)/2;
		if(a[mid]<k)l=mid+1;
		else if(a[mid]>k)r=mid-1;
		else break;
	}
	return mid;
}
long long ans()
{
	long long cnt=0,ans[500020],sum=0,an=1,cn=1;
	for(long long i=max(1LL,ls1-20000);i<=min(n,ls2+20000);i++)
	{
		cnt++;
		ans[cnt]=abs(a[k]-a[i]);
	}
	sort(ans+1,ans+cnt+1);
	sum=ans[1];
	while(sum<m)
	{
		cn++;
		sum+=ans[cn];
		an++;
	}
	for(int i=1;i<=cnt;i++)cout<<ans[i]<<"\n";
	return an;
}
int main()
{
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool o=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>2)
		{
			if(a[i]-a[i-1]!=a[2]-a[1])o=1;
		}
		p+=1.0*(a[i]-p)/i;
	}
	
	if(o==0)
	{
		long long gc=a[2]-a[1],summ=gc,anss=1;
		while(summ<=m)
		{
			gc*=2;
			summ=summ+gc;
			anss++;
		}
		cout<<anss;
		return 0;
	}
	sort(a+1,a+n+1);
	k=*lower_bound(a+1,a+n+1,p);
	if(p-a[bs()-1]<k-p)k2=bs()-1;
	else k2=bs();
	ls1=k2;ls2=k2;
	while(a[ls1]==a[k2])ls1--;
	ls1++;
	while(a[ls2]==a[k2])ls2++;
	ls2--;
	k=k2;
	cout<<ans();//zjnb 
	return 0;
}
