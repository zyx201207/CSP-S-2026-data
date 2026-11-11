#include <bits/stdc++.h>
using namespace std;
int a[50005],c[50005];
string b="";
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			b[i]=a[i];
			if(a[i]==b[j])
			{
				b="";
				b+=a[i];
				break;
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(b[j]==i)
				c[i]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
