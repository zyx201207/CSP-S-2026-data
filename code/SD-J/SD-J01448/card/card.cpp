#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],b[N],c[N],l,d[N],oo,p;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		p=max(a[i],p);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]]==0) 
			{
				c[++l]=a[j];
				b[a[j]]=l;
				
			}
			else 
			{
				l=b[a[j]];
			}
		}
		for(int k=1;k<=l;k++)
		{
			d[c[k]]++;
		}
		for(int ll=1;ll<=p;ll++)b[ll]=0;
		for(int ll=1;ll<=n;ll++)c[ll]=0;
		l=0;
	}
	for(int i=1;i<=m;i++)cout<<d[i]<<" ";
	return 0;
}

