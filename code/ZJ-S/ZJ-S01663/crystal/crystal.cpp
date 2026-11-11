#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s,r,p,sum,k,u,q;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	r=m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>2)
		{
			if(a[i]-a[i-1]==a[i-1]-a[i-2]) 
				u++;
		}
	}
	if(u==n-2)
	{
		for(long long i=1;i<=n;i++)
		{
			q=q+i;
			if(m<q*max(a[n]-a[n-1],a[n-1]-a[n]))
			{
			cout<<i;
			return 0;	
			}
		}
		cout<<n;
		return 0;
	}
  	sort(a+1,a+n+1);	
	s=1;
	for(long long i=1;i<n;i++)
	{
		if(s==1){
			p=i;
		}
		if(r-s*(a[i+1]-a[i])<0){
			i=p+1;
			sum=max(sum,s);
			s=1;
			r=m;
		}
		else {
			r=r-s*(a[i+1]-a[i]); 
			s++;
		}
	}
	sum=max(sum,s);
	cout<<sum;
	return 0;
}
