#include<bits/stdc++.h>
using namespace std;
int er(int a)
{
	string s;
	int b[35];
	int i=0,t,ans=0;
	while(a!=0)
	{
		i++;
		b[i]=a%2;
		a/=2;
	}
	for(int j=1;j<=i;j++)
	{
		t=b[j];
		b[j]=b[i+1-j];
		b[i+1-j]=t;
	}
	for(int j=1;j<=i;j++)
	{
		b[j]*=pow(10,i-j);
		ans+=b[j];
	}
	return ans;
}
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int m,n;
	int k[2005],a[2005];
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>k[i];
		k[i]=er(k[i]);
	}
	sort(k,k+n,cmp);
	if(m==1) cout<<k[0];
	if(m==2)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				a[i]=k[i]&k[j];
			}
		}
		sort(a,a+n,cmp);
		cout<<a[0];
	}
	return 0;
}
