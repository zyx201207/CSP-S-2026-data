#include<bits/stdc++.h>
using namespace std;
int n,T,c,a[2000005],d,ans,f[2000005];
int main()
{
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	scanf("%d%d",&c,&T);
	while(T--)
	{
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;++i)scanf("%d",a+i);
		ans=0;
		for(int i=1;i<n;++i)
		{
			memset(f,0,sizeof(f));
			f[i]=1;
			for(int j=i+1,k=i;j<=n;++j)
			{
				while(a[j]-a[k]>d)++k;if(k==j)break;
				for(int l=k;l<j;++l)f[j]+=f[l];
				if(f[j]==2)++ans;
				if(f[j]>2)break;
			}
		}
		printf("%d\n",ans);
	}
}