#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[100000000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int S=2^(n+1);
	for(int i=1;i<S;i++)
	{
			int zans=-1,cn=0;
			for(int j=0;j<=n;j++)
			{
				if(i&(1<<j)) 
				{
					if(zans==-1) zans=a[j];
					else zans=zans&a[j];
					cn++;
				}
			}
			if(cn==m) ans=max(ans,zans);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
