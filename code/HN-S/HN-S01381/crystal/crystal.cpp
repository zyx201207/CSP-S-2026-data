#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,b;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
								
	}
	b=a[2]-a[1]+a[2]-a[0];
	if(b<=m)
	{
		cout<<3;
	}
	else
	{
		cout<<2;
	}
	
	
	return 0;
}
