#include<bits/stdc++.h>
using namespace std;
long long ans=0,qwq=0;
int n,m,q,tong[300005],jishu[5005][3005];
long long a[500005];
void dg(int x)
{
	if(x<=n) tong[a[x]]++;
	if(x>=n) return ;
	if(jishu[x][a[x]]==1)
	{
		dg(x+1);
		return ;
	 } 
	 else
	 {
	 	for(int d=n;d>=x;d--)
	 	{
	 		if(a[d]==a[x]) 
			 {
			 	dg(d+1);
			 	break;
			 }
		}
	 }
	 return ;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	a[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1]) qwq=1;
		for(int j=1;j<=i;j++) jishu[j][a[i]]++;
	}
	if(qwq==0)
	{
		for(int i=n;i>=1;i--)
		{
			tong[a[i]]=max(i,tong[a[i]]);
		}
		for(int i=1;i<=m;i++)
		{
			cout<<tong[i]<<' ';
		}
		return 0;
	}
	if(m<=2)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==a[n]) tong[a[n]]++;
			else tong[a[i]]++,tong[a[n]]++;
		}
		for(int i=1;i<=m;i++)
		{
			cout<<tong[i]<<' ';
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		dg(i);
	}
	for(int i=1;i<=m;i++)
	{
		cout<<tong[i]<<' ';
	}
	return 0;
}