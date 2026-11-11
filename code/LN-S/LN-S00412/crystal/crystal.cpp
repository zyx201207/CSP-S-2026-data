#include<bits/stdc++.h>
using namespace std;
long long a[600000],f[600000];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,cus=0;
	scanf("%lld%lld",&n,&m);
	//cout<<"sssssssssss";
	for(int i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	//int d=-2;
	//cout<<d<<" "<<abs(d);
	for(long long k=a[1];k<=a[n];k++)
	{
		long long x=m,y=0;
		for(int i=1;i<=n;i++)
		f[i]=abs(a[i]-k);
		sort(f+1,f+1+n);
		for(int i=1;i<=n;i++)
		{
			x-=f[i];
			if(x<0)break;
			y++;
		}
		cus=max(cus,y);
	}
	cout<<cus;
	return 0;
}
