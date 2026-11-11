#include <bits/stdc++.h>
using namespace std;
long long cst[500010];
long long n,m;
long long preee[500010];
bool cmpp(int x,int y)
{
	return x<y;
}
long long cooost(int a,int b)
{
	return preee[a-1]-(b-a+1)*preee[b-1]+(b-a)*preee[b];
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>cst[i];
	}
	sort(cst+1,cst+n+1,cmpp);
	if(cst[1]<0)
	{
		int addd=abs(cst[1])+1;
		for(int i=1;i<=n;i++)
		{
			cst[i]+=addd;
		}
	}
	preee[1]=cst[1];
	for(int k=2;k<=n;k++)
	{
		preee[k]=preee[k-1]+cst[k];
	}
//	for(int i=1;i<=n;i++)
//	{
//		cout<<cst[i]<<' ';
//	}
	int fret=0;
	for(int i=1;i<=n;i++)
	{
		int rettt=1;
		int rsst=n-i;
		int lfft=i,rggt=n;
		if(cooost(i,i+rsst)<=m)
		{
			rettt=rsst+1;
			fret=max(fret,rettt);
			continue;
		}
		int mdmd=(lfft+rggt)>>1;
		while(1)
		{
			int mdmd=(lfft+rggt)>>1;
			if(cooost(i,mdmd)<=m && cooost(i,mdmd+1)>m)
			{
				rettt=mdmd-i+1;
				break;
			}
			if(cooost(i,mdmd)>m)
			{
				rggt=mdmd-1;
				continue;
			}
			else
			{
				lfft=mdmd+1;
				continue;
			}
		}
		fret=max(fret,rettt);
	}
	cout<<fret;
	return 0;
}
