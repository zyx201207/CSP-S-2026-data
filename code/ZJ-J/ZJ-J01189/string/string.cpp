#include<bits/stdc++.h>
using namespace std;
long long a[200100],ans,n;
char c[200100],b[200100];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long len=0,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		len+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			cnt++;
			c[cnt]=b[i];
		}
	}
	
	long long mid=0,jo=-1;
	if(len%2==0)
	{
		mid=len/2;
		jo=2;
	}
	else
	{
		mid=len/2+1;
		jo=1;
	}
	if(jo==2)
	{
		for(int i=1;i<=mid;i++)
		{
			if(c[i]!=c[cnt-i+1])
				ans++;
		}
		
	}
	if(jo==1)
	{
		for(int i=1;i<mid;i++)
		{
			if(c[i]!=c[cnt-i+1])
				ans++;
		}
		
	}
	cout<<ans;
	return 0;
}