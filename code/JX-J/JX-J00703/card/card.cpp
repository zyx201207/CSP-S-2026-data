#include<bits/stdc++.h>
using namespace std;
int a[500500];
int pai[500500];
int now[500500];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,t;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		t=0;
		for(int x=i;x<=n;x++)
		{
			t++;
			for(int j=1;j<t;j++)
			{
				if(a[x]==now[j])
				{
					t=j;
					break;
				}
			}
			now[t]=a[x];
		}
		for(int i=1;i<=t;i++)
		{
			pai[now[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<pai[i]<<" ";
	}
	return 0;
}
