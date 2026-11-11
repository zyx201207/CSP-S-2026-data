#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","l",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[50005]={0};
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=m;i>=1;i--)
	{
		cout<<i+(n-m)<<" ";
	}
	return 0;	
} 