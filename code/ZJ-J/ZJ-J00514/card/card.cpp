#include<bits/stdc++.h>
using namespace std;
struct card
{
	int d,n;
};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n],x[m+1]={0};
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)
	{
		card c[n-i];
		c[0].d=a[i];
		c[0].n=-1;
		for(int j=i;j<n;j++)
		{
			int a1=a[j],b=0;
			if(c[0].d==a1)continue;
			card c1;
			for(c1=c[0];c1.n!=-1;c1=c[c1.n])
			{
				if(c[c1.n].d==a1)
				{
					c1.n=j;
					c[c1.n].d=a1;
					c[c1.n].n=-1;
					b=1;
					break;
				}
			}
			if(b==0)
			{
				c1.n=j;
				c[c1.n].d=a1;
				c[c1.n].n=-1;
			}
		}
		card c2;
		for(c2=c[0];c2.n!=-1;c2=c[c2.n])x[c2.d]++;
		x[c2.d]++;
	}
	for(int i=1;i<=m;i++)cout<<x[i]<<" ";
	return 0;
}