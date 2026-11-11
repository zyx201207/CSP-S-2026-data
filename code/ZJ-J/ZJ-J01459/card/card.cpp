#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,k,a[500020],f[300020],lst[300020],cnt[300020],tr[1000020];
int lb(int x)
{
	return x&-x;
}
void upd(int x,int y)
{
	while(x<=n)
	{
		tr[x]+=y;
		x+=lb(x);
	}
}
int qry(int x)
{
	int s=0;
	while(x)
	{
		s+=tr[x];
		x-=lb(x);
	}
	return s;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i],upd(i,0);
	for(i=1;i<=n;i++)
		f[a[i]]=i;
	for(i=1;i<=m;i++)lst[i]=f[i];
	//for(i=1;i<=m;i++)cout<<lst[i]<<" ";
	//for(i=1;i<=n;i++)cout<<lst[i]<<" ";
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;)
		{
			cnt[a[j]]++;
			k=lst[a[j]];
			if(k==0)
			{
				upd(j+1,1);
				break;
			} 
			j=k+1;
		}
	}
	for(i=1;i<=n;i++)
		cnt[a[i]]+=qry(i);
	for(i=1;i<=m;i++)cout<<cnt[i]<<" ";
}
