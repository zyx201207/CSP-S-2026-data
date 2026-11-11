#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,t[N],a[N],last[N],tong[N],cnt[N];
int lowbit(int x)
{
	return x&(-x);
}
void update(int k,int x)
{
	while(k<=n)
	{
		t[k]+=x;
		k+=lowbit(k);
	}
}
int query(int k)
{
	int sum=0;
	while(k)
	{
		sum+=t[k];
		k-=lowbit(k);
	}
	return sum;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		last[i]=tong[a[i]];
		tong[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			t[j]=0;
		}
		for(int j=i;j<=n;j++)
		{
			if(last[j]&&query(last[j])==0&&last[j]>=i)
			{
				update(last[j],1);
				update(j,-1);
			}
		}
		for(int j=i;j<=n;j++)
		{
			if(query(j)==0)
			{
				cnt[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",cnt[i]);
	}
	return 0;
}

