#include<bits/stdc++.h>
using namespace std;
int c;
int t;
int n;
int x;
int a,b;
int ans[10];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int tu=1;tu<=t;tu++)
	{
		cin>>n>>x;
		for(int i=1;i<x;i++)
		{
			cin>>a>>b;
		}
		if(n/2==(n+1)/2)
		{
			ans[tu]=2;
		}
		else
		{
			ans[tu]=1;
		}
	}
	for(int i=1;i<=t;i++)
	{
		cout<<ans[i]<<endl;
	}
}
