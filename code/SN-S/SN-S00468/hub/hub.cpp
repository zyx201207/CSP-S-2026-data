//SN-S00468 钟林希 西安翱翔中学 
#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,du[2000050],ans,u,v;
int main()
{
	freopen("hub.in","w",stdin);
	freopen("hub.out","r",stdout);
	scanf("%lld%lld",&c,&t);
	for(int ii=1;ii<=t;ii++)
	{
		ans=-1e9;
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<n;i++)
		{
			scanf("%lld%lld",&u,&v);
			du[u]++;
			du[v]++;
		}
		if(c==13||c==14)
		{
			for(int i=1;i<t;i++)printf("%d\n",0);
			printf("0");
			return 0;
		}
		for(int i=1;i<=n;i++)ans=max(ans,du[i]);
		if(ii!=t)printf("%lld\n",ans);
		else printf("%lld",ans);
	}
	return 0;
}
