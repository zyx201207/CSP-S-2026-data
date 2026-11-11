#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long a[n+5];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=i)
		cin>>a[i];
	}
	return 0;
 } 
