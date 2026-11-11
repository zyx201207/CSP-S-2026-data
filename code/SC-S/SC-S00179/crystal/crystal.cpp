#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[1005],ans=1,j=0;
	cin >>n >>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i+=j)
	{
		j=0;
		while(a[i]!=a[i+1])
		{			
			a[i]++;
		}
		ans++;
	}cout <<ans;
	return 0; 
}