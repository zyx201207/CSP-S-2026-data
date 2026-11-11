#include <bits/stdc++.h>
using namespace std;
string c[1000];
string b[200000];
int main() 
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	int j=0;
	int max0=0;
	int h=0;
	for(int i=0;i<n;i++)
	{
		int k=j;
		if(a[i]>100)
		{
			h=1;
		}
		cin>>a[i]>>c[i];
		if(h==0)
		{
		for(j;j<k+a[i];j++)
		{
			b[j]=c[i];
		}
		}
		max0+=a[i];
	}
	int ans=0;
	if(h==0)
	{
	for(int i=0;i<max0/2+max0%2;i++)
	{
		if(b[i]!=b[max0-i-1])
		{
			ans++;
		}
	}
}
	else
	{
		for(int i=0;i<n/2+n%2;i++)
		{
			if(c[i]!=c[n-i-1])
			{
				ans+=max(a[i],a[n-i-1]);
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
		return 0;
}
