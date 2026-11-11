#include<bits/stdc++.h>
using namespace std;
long long int f,h=1,n,i,k,m,a[900005],b[900005],c[900005],d[900005],e[900005],j;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	cin>>a[i];
	for(i=1;i<=n;i++)
	{
		k=1;
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		for(j=i;j<=n;j++)
		{
			if(c[a[j]]==0)
			{
				b[j]=a[j];
				c[b[j]]=1;
				d[b[j]]=k;
				k++;
			}
			else
			{
				for(f=b[d[b[k]]];f<=n;f++)
				{
					b[f]=0;
					c[b[f]]=0;
					d[b[f]]=0;
				}
				k=b[d[b[k]]];
			}
		}
		for(h=1;h<=n;h++)
		e[b[h]]++;
	}
	for(i=1;i<=m;i++)
	cout<<e[i]<<' ';
	return 0;
}