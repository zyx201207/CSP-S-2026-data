#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
string s,s1;
int max=0,maxx=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n=1,ans=1,c=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=30;j>=0;j--)
		{
			
		}
	}
	bool t=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=i-1)
		{
			t=0;
			break;
		}
	}
	if(t==0)
	{
		cout<<0;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
	}
	return 0;
}
