#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt,a[100005],bi,si=100000000,b[30],sum;
int main()
{
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	cin>>n>>m;
	b[0]=1;
	for(int i=1;i<30;i++)
	{
		b[i]=b[i-1]*2;
	}
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		bi=max(a[i],bi);
		si=min(a[i],si);
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		for(int ii=0;ii<i;ii++)
		{
			if(a[i]==b[ii]-1)
			{
				sum=1;
			}
		}
		if(sum!=1)
		{
			cnt=1;
		}
	}
	if(cnt==0)
	{
		cout<<a[n-m];
		return 0;
	}
	if(m==1)
	{
		cout<<bi;
		return 0;
	}if(m==n)
	{
		cout<<0;
		return 0;	
	}
	cout<<0;
    return 0; 
}
