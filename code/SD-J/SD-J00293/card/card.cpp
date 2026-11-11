#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

const int N=5e5+10;
const int M=2e5+10;
int a[N],bj[M];
struct st{
	int c,d;
}bz[M];
int find(int b,int l,int r);
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n-1;i++)
	{
		scanf("%d",&a[i]);
		a[i]--;
	}
	int ans=0;
	for(int i=0;i<=n-1;i++)
	{
		memset(bz,0,sizeof(bz));
		for(int j=ans;j<=n-1;j++)
		{
			if(bz[a[j]].c==1)
			{
				for(int k=bz[a[j]].d;k<=j-1;k++)
				{
					bz[a[k]].c--;
					bz[a[k]].d=0;
				}
			}
			bz[a[j]].c++;
			bz[a[j]].d=j;
		}
		for(int j=0;j<=m-1;j++)
			if(bz[j].c>0)
				bj[j]++;
		ans++;
	}
	for(int i=0;i<=m-1;i++)
		printf("%d ",bj[i]);
	return 0;
}
int find(int b,int l,int r)
{
	for(int i=l-1;i>=r;i--)
		if(a[i]==b)
			return a[i];
	return 0;
}
