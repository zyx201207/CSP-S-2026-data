#include<bits/stdc++.h>
using namespace std;
int ans[300010],lst[300010],a[500010],f[500010],n,m;
bool exists[300010];
int low_bit(int x) { return x&-x; }
void add(int x,int val)
{
	while(x<=n+1)
	{
		f[x]+=val;
		x+=low_bit(x);
	}
}
int query(int x)
{
	int res=0;
	while(x)
	{
		res+=f[x];
		x-=low_bit(x);        
	}
	return res;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n+1;i++)
		scanf("%d",a+i);
	for(int i=2;i<=n+1;i++)
	{
		memset(lst,0,sizeof(lst));
		memset(f,0,sizeof(f));
		for(int j=i;j<=n+1;j++)
		{
			if(query(j)) continue;
			if(lst[a[j]]!=0&&!query(lst[a[j]]))
			{
				add(lst[a[j]],1);
				add(j,-1);
			}
			lst[a[j]]=j;
		}
		for(int j=i;j<=n+1;j++)
			if(query(j)==0)
				exists[a[j]]=1;
		for(int j=1;j<=m;j++)
		{
			if(exists[j]) ans[j]++;
			exists[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	return 0;
}
