#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
int c,n,m,d,q,xx,yy;
int w[500005],a1[505][26],a2[505][26],sm[505][26];
long long ans;
bool c20_1(int g)
{
	int pd=0,zb1,zb2;
	for(int i=1;i<=a1[g][0];i++)
	{
		if(a1[g][i]==xx)
			pd++,zb1=i;
		if(a1[g][i]==yy)
			pd++,zb2=i;
	}
	if(pd==2) 
	{
		ans=w[zb1]+a2[g][zb1]+w[zb2]+a2[g][zb2];
		printf("%lld\n",ans);
		return true;
	}
	return false;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a1[i][0]); a2[i][0]=a1[i][0];
		for(int j=2;j<=a1[i][0]*2+1;j++)
		{
			if(j&1) scanf("%d",&a2[i][j/2]);
			else scanf("%d",&a1[i][j/2]);
		}
	}
	if(c>=12&&c<=19)
	{
		
		for(int i=1;i<=a1[i][0];i++)
			for(int j=1;j<=a1[2][0];j++)
				if(a1[1][i]==a1[2][j])
				{
					sm[1][0]++;
					sm[1][sm[1][0]]=a1[1][i];
				}
	}
	if(c==20||c==21||d<=2)
	{
		while(q--)
		{
			ans=1e18;
			scanf("%d%d",&xx,&yy);
			bool p1=c20_1(1);
			if(p1) continue;
			p1=c20_1(2);
			if(p1) continue;
			for(int i=1;i<=a1[1][0];i++)
				for(int j=1;j<=a1[2][0];j++)
					if(a1[1][i]==a1[2][j])
					{
						sm[1][0]++;
						sm[1][sm[1][0]]=a1[1][i];
					}
			for(int i=1;i<=sm[1][0];i++)
			ans=min(ans,(long long)w[sm[1][i]]+(long long)a2[sm[1][i]]);
			printf("%lld\n",ans);
			continue;
		}
	}
	
	return 0;
}

