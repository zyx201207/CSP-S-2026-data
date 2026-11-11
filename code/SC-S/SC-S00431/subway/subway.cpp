#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010],k[510],cz[505][21],t[505][21];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p,ans=LLONG_MAX;//测试点编号、地铁线路数、地铁站数
	//每个地铁站最多被几条线路经过，计划数，答案 
	int yx=0,yy=0,x,y,yt=0,xt=0;
	scanf("%lld%lld",&n,&m);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&p);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&a[i]);//出站时间 
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j+=2)
		{
			scanf("%lld",&cz[i][j]);//地铁路线 
		}
		for(int j=2;j<=k[i];j+=2)
		{
			scanf("%lld",&t[i][j]);//地铁到站台的时间 
		}
	}
	for(int i=1;i<=p;i++);
	{
		scanf("%lld%lld",&x,&y);//测试点 
		ans=a[x]+a[y]+t[1][x]+t[1][y]; 
	}
	cout<<ans;
	return 0;//骗分 
}