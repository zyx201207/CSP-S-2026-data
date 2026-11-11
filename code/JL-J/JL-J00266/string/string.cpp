#include<bits/stdc++.h>
using namespace std;
#define N 1110000
long long a[N],e[N];
char b[N],c[N];
char d[N];
int main()
{
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long cnt=0;
	long long sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		e[i]=a[i];
	}
	for(int i=0;i<n;i++)
	{
		if(i>0)
		{
		a[i]+=a[i-1];
		}
		if(i>0)
		{
			for(int j=a[i-1];j<a[i];j++)
		{
		c[j]=b[i];
		}
	}
	else
	{
	for(int k=0;k<a[i];k++)
	{
		c[k]=b[i];
	}
	}
	}
	for(int i=a[n-1]-1;i>=0;i--)
	{
	d[cnt++]=c[i];
	}
	for(int i=0;i<a[n-1];i++)
	{
	if(d[i]!=c[i])
	{
	sum++;
	}
	}
   if(sum==0)
   {
	  cout<<sum<<endl;
  }
  else if(a[n-1]%2!=0)
  {
	 cout<<(strlen(c)-1)/2;
  }
  else if(a[n-1]%2==0)
  {
	 cout<<strlen(c)/2<<endl;
  }
 return 0;
}
