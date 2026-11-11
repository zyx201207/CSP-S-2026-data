#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	} 
	long long maxx=-1e9;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;i++)
		{
			if(i==a[i]&&j==a[j]) maxx=max(maxx,i&j);
		}
	}
	cout<<maxx<<endl;
	return 0;
} 
