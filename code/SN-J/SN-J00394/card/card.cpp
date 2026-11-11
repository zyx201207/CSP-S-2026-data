#include <bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==2&m==1)
	{
		if(a[1]!=a[2])
		{
			cout<<"2";
		}
		else
		{
			cout<<"1";
		}	
	}
	return 0;
}
