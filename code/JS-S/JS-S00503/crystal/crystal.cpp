#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],num,sum,t,k,kk,s;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==2)
			s=a[2]-a[1];
		if(i>=3&&a[i]-a[i-1]!=s)
			kk=1;
		if(a[i]!=i)
			k=1;
	}
	if(kk==0)
	{
		m=m/s;
		k=0;
	}
	if(k==0)
	{
		for(int i=0;i<n;i++)
		{
			if(m-i>=0)
			{
				m=m-i;
				num++;
			}
			else
			{
				cout<<num;
				return 0;
			}
			if(m==0)
			{
				cout<<num;
				return 0;
			}
		}
		cout<<num;
		return 0;
	}
	sort(a,a+n+1);
	for(int i=1;i<=n;i++)
	{
		t=m;
		sum=0;
		for(int j=i;j>=1;j--)
		{
			if(t-(a[i]-a[j])>=0)
			{
				t=t-(a[i]-a[j]);
				sum++;
			}
			else
				break;
			if(t==0)
				break;
		}
		num=max(num,sum);
	}
	cout<<num;
	return 0;
}