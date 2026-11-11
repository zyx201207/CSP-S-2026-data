#include<bits/stdc++.h>
using namespace std;
long long int a[500005],b[500005],f[500005];
long long cnt;
int check(int x)
{
	if(cnt<=0) return 0;
	int l,r,mid;
	l=1;
	r=cnt;
	while(l<r)
	{
		mid=(l+r)/2;
		if(b[mid]>=x) r=mid;
		else l=mid+1;
	}
	if(l==x) return 1;
	else return 0;
}
int find(int x)
{
	int l,r,mid;
	l=1;
	r=cnt;
	while(l<r)
	{
		mid=(l+r)/2;
		if(b[mid]>=x) r=mid;
		else l=mid+1;
	}
	return l;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,i,j,k,x;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			if(check(a[j])==0)
			{
				b[++cnt]=a[j];
			}
			else
			{
				x=find(a[j]);
				for(k=x+1;k<=cnt;k++)
				{
					b[k]=0;
				}
				cnt=x;
			}
		}
		for(k=1;k<=cnt;k++)
		{
			f[b[k]]++;
		}
	}
	for(i=1;i<=m;i++)
	{
		cout<<f[i]<<" ";
	}
	return 0;
}