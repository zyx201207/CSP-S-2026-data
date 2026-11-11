#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0;
	cin>>n;
	long long c[100000005];
	int a[n];
	char b[n];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		sum+=a[i];
		
	}
	int k=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			c[k]=b[j];
			k++;
		}
	}
	if(n==1)
	{
		cout<<"0";
	}
	if(n==2)
	{
		cout<<min(a[1],a[2]);
	}
	long long lst=sum/2+1,nxt=0;
	if(sum%2) nxt=sum/2+1;
	else nxt=sum/2;
	long long cn=0,nu=0;
	for(int i=1;i<=sum/2;i++)
	{
		if(c[lst]!=c[nxt])cn++;
		if(c[nxt]!=c[lst])nu++;
		lst-=i;
		nxt+=i;
	}
	cout<<min(cn,nu);
	
	return 0;

	
} 
