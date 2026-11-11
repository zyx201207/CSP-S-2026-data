#include<bits/stdc++.h>
using namespace std;
string x;
string y;
string z;
int ax[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	int cnta=0;
	int cntb=0;
	int n;
	cin>>n;
	if(n==1)
	{
		cout<<0;
	}
	
		for(int i=0;i<n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		ax[i]=a;
		x[i]=c;
	}
	for(int i=x.size();i>0;i--)
	{
		z[i]=x[cnta++];
	}
	int ans=0;
	for(int i=0;i<x.size();i++)
	{
		if(x[i]!=z[i])
		{
			ans++;
		}
	}
	cout<<ans;
if(x==y)
{
	cout<<0;
}
	return 0;
}
