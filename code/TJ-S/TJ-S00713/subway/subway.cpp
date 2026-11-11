#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500015],k[555],a[500015],t[500015];
long long tt[500005],ww[500015],nexx[500015],hh[500015],idx=0;
int add(long long s,long long e,long long www)
{
	idx++;
	tt[idx]=e;
	ww[idx]=www;
	nexx[idx]=hh[s];
	hh[s]=idx;
}
int main()
{
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			scanf("%lld%lld",&a[j],&t[j]);
			if(j>1)
			{
				add(a[j],a[j-1],0);
				add(a[j-1],a[j],0);
			}
		}
	}
	while(q--)
	{
		memset(tt,0,sizeof tt);
		memset(ww,0,sizeof tt);
		memset(nexx,0,sizeof tt);
		memset(hh,0xff,sizeof tt);
		cin>>xr>>yr;
		ans=w[xr]+w[yr];
		cout<<ans<<endl;
	}
	return 0;
}
