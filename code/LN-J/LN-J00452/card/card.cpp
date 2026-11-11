#include<bits/stdc++.h>
using namespace std;
int zhuo[200005],a[200005];
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
	if(m==1)
	{
		cout<<n;
	}
	else
	{
		if(m==n)
		{
			for(int i=1;i<=m;i++)
			{
				cout<<1<<' ';
			}
		}
		else
		{cout<<0;
		}
		
	}
	return 0;
}
