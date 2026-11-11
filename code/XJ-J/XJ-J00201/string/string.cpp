#include <bits/stdc++.h> 
using namespace std;
long long n,a[20005],ans=0,n1,c=0,x,y;
char b[20005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n; 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	n1=n;
	for(int i=1;i<=(n+1)/2;i++)
	{
		if(a[i]<=a[n1] && b[n1]!=b[i])
		{
			a[n1]-=a[i];
			ans+=a[i];
			a[i]=0;
		}
		else if(a[i]>a[n1] && b[n1]!=b[i])
		{
			a[i]-=a[n1];
			ans+=a[n1];
			a[n1]=0;
			i--;
			n1--;
		}
		if(a[i]<=a[n1] && b[n1]==b[i])
		{
			a[n1]-=a[i];
			a[i]=0;
		}
		else if(a[i]>a[n1] && b[n1]==b[i])
		{
			a[i]-=a[n1];
			a[n1]=0;
			n1--;
		}
	}
	if(n==1)
	{
		cout<<0;
	}
	else
	{
		cout<<ans;
	}
	return 0;
}
