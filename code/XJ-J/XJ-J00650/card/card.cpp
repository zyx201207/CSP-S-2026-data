#include<bits/stdc++.h>
using namespace std;
int n,m,a[510000],la[310000],k,c[510000],flag[310000],ans[310000];
struct node
{
	int l,r;
}q[510000];
bool cmp(node x,node y)
{
	if(x.r<y.r) return true;
	else return false;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(la[a[i]]!=0)
		{
			k++;
			q[k].l=la[a[i]];
			q[k].r=i;
		}
		la[a[i]]=i;
	}
	sort(q+1,q+1+k,cmp);
	for(int i=1;i<=n;i++)
	{
		int j=1,now=i;
		while(j<=k)
		{
			while(q[j].l<now&&j<=k) j++;
			if(q[j].l<now) continue;
			c[q[j].l]++;
			c[q[j].r]--;
			now=q[j].r;
		}
		int sum=0;
		for(int ii=1;ii<=n;ii++)
		{
			
			sum+=c[ii];
			if(sum==0) flag[a[ii]]=1;
			c[ii]=0;
		}
		for(int ii=1;ii<=m;ii++)
		{
			if(flag[ii]==1&&la[ii]>=i) ans[ii]++;
			flag[ii]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}