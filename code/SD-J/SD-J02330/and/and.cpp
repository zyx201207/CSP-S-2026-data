#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000001],q,w[100010],e,sum,r[1000101],cnt=1,ans,t,x[1001],o=1,u;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		q=max(a[i],q);
		w[i]=a[i];
	}
	sort(w+1,w+n+1);
	t=a[1];
	for(int i=2;i<=n;i++)
	t=t&a[i];
	if(n==m)
	{
		cout<<t;
		return 0;
	}
	if(m==1)
	{
	cout<<q;
	return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			r[cnt]=a[i]&a[j];
			ans=max(ans,r[cnt]);
			cnt++;
		}
		cout<<ans;
		return 0;
	 } 
	 int p=w[n];
	 if(p>1)
	 {
	 	
	while(p!=0)
	{
		x[o]==p%2;
		p/=2;
		o++;
	}
	for(int i=1;i<=o;i++)
	{
		if(x[i]==1)
		u++;
		
	}
	if(u!=1)
	{
	sum=w[n];
	for(int i=2;i<=m;i++)
	{
		e=n-i+1;
		sum=sum&w[e];
	}	
	}
	else
	{
		sum=w[n-1];
	for(int i=3;i<=m;i++)
	{
		e=n-i+1;
		sum=sum&w[e];
	}	
	 } 
}
else
{
	sum=w[n];
	for(int i=2;i<=m;i++)
	{
		e=n-i+1;
		sum=sum&w[e];
	}	
}
	cout<<sum;
	return 0;
} 
