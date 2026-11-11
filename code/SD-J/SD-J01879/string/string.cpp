#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;	
long long a[10000001],b[10000001],c[10000001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	char s[1000001];
	long long ans=0;
	cin>>n;
	a[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
		a[i]=a[i-1]+a[i];
	} 
	for(int i=1;i<=(1+a[n])/2;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i>a[j-1]&&i<=a[j])
			{
				b[i]=s[j];
			}
			if((a[n]+1-i)>a[j-1]&&(a[n]+1-i)<=a[j])
			{
				c[n+1-i]=s[j];
			}
		}
		if(b[i]!=c[n+1-i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}



