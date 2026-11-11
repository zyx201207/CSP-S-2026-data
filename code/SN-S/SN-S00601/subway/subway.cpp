#include<stdio.h>
#include<cstdio>
using namespace std;
int c,n,m,d,q;
int w[10005];
int cj[101][101],ct[101][101],k[10005];
int rx[10005],ry[10005];
int ans[10005];
int map[101][101];
int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=0;i<m;i++) scanf("%d",&w[i]);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=0;j<k[i];j++) scanf("%d%d",&cj[i][j],&ct[i][j]);
	}
	for(int i=0;i<q;i++) scanf("%d%d",&rx[i],&ry[i]);
	if(n==2)
	{
		
		int zdt;
	
		for(int ii=0;ii<q;ii++)
		{	
			ans[ii]=w[rx[ii]]+w[ry[ii]];
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<k[i];j++)
				{
					if(rx[ii]==cj[i][j]) 
					{
						ans[ii]=ans[ii]+ct[i][j];
						zdt=k[i];
					}
					if(ry[ii]==cj[i][j]) ans[ii]=ans[ii]+ct[i][j];
				}
			}
			
			int tong[10005];int op[100];int zz=0;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<k[i];j++)
				{
					tong[cj[i][j]]++;
					if(tong[cj[i][j]]>=2)
					{
						op[zz]=ct[1][j];
						for(int jj=0;jj<k[0];jj++)
						{
							if(cj[0][jj]==cj[i][j]) op[zz]=op[zz]+ct[0][jj];
						}
						zz++;
					}
				}
			}
			int min;
			for(int i=0;i<zz-1;i++)
			{
				if(op[zz]<op[zz+1]) min=op[zz];
				else min=op[zz+1];
			}
			printf("%d",min+ans[ii]);
		}
		return 0;
	}
	
	return 0;
}
