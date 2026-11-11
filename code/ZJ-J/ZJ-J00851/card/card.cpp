#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,m,a[N],num[N];
void solve1()
{
	int las[n+10];
	bitset<5010> bs;
	for(int i=1;i<=n;i++)
	{
		memset(las,0,sizeof las);
		bs.reset();
		for(int j=i;j<=n;j++)
		{
			if(las[a[j]]&&(!bs[las[a[j]]]))
				for(int k=las[a[j]];k<j;k++)
					bs.set(k);
			las[a[j]]=j;
		}
		for(int j=i;j<=n;j++)
			if(!bs[j]) num[a[j]]++;
	}
	for(int i=1;i<=m;i++) printf("%d ",num[i]);
}
void solve2()
{
	for(int i=1;i<=n;i++) num[a[i]]=i;
	for(int i=1;i<=m;i++) printf("%d ",num[i]);
}
void solve3()
{
	int na[5010],len[5010]={0},las[5010],nn=1;
	bitset<5010> bs;
	na[1]=a[1],len[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]==a[i-1]) len[nn]++;
		else na[++nn]=a[i],len[nn]=1;
	}
	for(int i=1;i<=nn;i++)
	{
		memset(las,0,sizeof las);
		bs.reset();
		for(int j=i;j<=nn;j++)
		{
			if(las[na[j]]&&(!bs[las[na[j]]]))
				for(int k=las[na[j]];k<j;k++)
					bs.set(k);
			las[na[j]]=j;
		}
		for(int j=i;j<=nn;j++)
			if(!bs[j])
				num[na[j]]+=len[i];
	}
	for(int i=1;i<=m;i++) printf("%d ",num[i]);
}
void solve4()
{
	int na[N],len[N]={0},las[N],nn=1;
	bitset<N> bs;
	na[1]=a[1],len[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]==a[i-1]) len[nn]++;
		else na[++nn]=a[i],len[nn]=1;
	}
	for(int i=1;i<=nn;i++)
	{
		memset(las,0,sizeof las);
		bs.reset();
		for(int j=i;j<=nn;j++)
		{
			if(las[na[j]]&&(!bs[las[na[j]]]))
				for(int k=las[na[j]];k<j;k++)
					bs.set(k);
			las[na[j]]=j;
		}
		for(int j=i;j<=nn;j++)
			if(!bs[j])
				num[na[j]]+=len[i];
	}
	for(int i=1;i<=m;i++) printf("%d ",num[i]);
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==1)
	{
		printf("%d",n);
		return 0;
	}
	bool b1=1;
	int block=0;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=2;i<=n;i++) if(a[i]<a[i-1]) b1=0;
	for(int i=2;i<=n;i++) if(a[i]!=a[i-1]) block++;
	if(b1) solve2();
	else if(block<=4999) solve3();
	else if(n<=5000) solve1();
	else if(m<=2) solve4();
	return 0;
}

