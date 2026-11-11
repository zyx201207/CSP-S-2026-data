#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],o,p,c[500005];
int main() 
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	//o=1;
	//int p;
	for(int i=1;i<=n;i++)
	{
		o=1;
		for(int j=i;j<=n;j++)
		{
			for(int y=1;y<o;y++)
			{
				if(b[y]==a[j])
				{
					o=y;
					break;
				}
			}
			b[o]=a[j];
			//cout<<o<<" ";
			o++;
		}
		for(int j=1;j<o;j++)
		{
			c[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
}
