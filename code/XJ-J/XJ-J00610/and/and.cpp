#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int a[1005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	if(n%2==0)
	{
		cout<<n*(m+1);
	}
	else
	{
		cout<<n+(m-1);
	}
	return 0;
}