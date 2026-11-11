#include<bits/stdc++.h>
using namespace std;
long long a[100001],b[100001],c[100001],n,m,Min=INT_MAX,ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	double x=0;
	x*=1.0;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		x+=a[i]; 
	}	
	sort(a+1,a+1+n);
	x/=n*1.0;
	for(int i=1;i<=n;++i)
	{
		b[i]=abs(a[i]-x);
		Min=min(Min,b[i]);
	}
	for(int i=1;i<=n;++i) if(b[i]==Min) ans=a[i];
	for(int i=1;i<=n;++i) c[i]=abs(a[i]-ans);
	sort(c+1,c+n+1);
	long long num=0,num1=0;
	for(int i=2;i<=n;i++)
	{
		if(num>m) break;
		num+=c[i];
		num1+=1;
	}
	cout<<num1;
	return 0;
}