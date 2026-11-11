#include <bits/stdc++.h>
using namespace std;
long long a[200005]; 
string c[200005];
string b="";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			b+=c[i];
		}
		sum+=a[i];
	}
	unsigned long long ans=0;
	unsigned long long t;
	if(sum%2==0)
	{
		t=sum/2;
	}
	else
	{
		t=sum/2+1;
	}
	for(unsigned long long i=0;i<t;i++)
	{
		if(b[i]!=b[sum-i-1])
		{
			ans++;
		}
	}
	cout<<ans;
}
