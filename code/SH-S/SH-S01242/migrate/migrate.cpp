#include<bits/stdc++.h>
using namespace std;
#define int long long
namespace IO
{
	char buf[1<<16],*p1,*p2,ibuf;
	#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,sizeof(buf),stdin)),p1==p2?EOF:*p1++)
	int rd(int x=0,int f=1)
	{
		for(;!isdigit(ibuf);ibuf=getchar())if(ibuf=='-')f=-1;
		for(;isdigit(ibuf);ibuf=getchar())x=x*10+(ibuf^48);
			return x*f;
	}
}
using IO::rd;
#define pii pair<int,int>
#define a first
#define b second
int a[2000200];
int ne[2000200],pr[2000200];
int pc[2000200],sc[2000200];
int bonus[2000200];
int calc(int lx,int rx,int ly,int ry,int i,int d)
{
	// cerr<<"CALC: "<<lx<<' '<<rx<<' '<<ly<<' '<<ry<<' '<<i<<' '<<d<<endl;
	while(lx<rx&&a[lx]<a[i]-d)lx++;
	while(lx<rx&&a[rx-1]>=a[i-1])rx--;
	while(ly<ry&&a[ly]<a[i]+1)ly++;
	while(ly<ry&&a[ry-1]>=a[i-1]+d+1)ry--;
	// cerr<<lx<<' '<<rx<<' '<<ly<<' '<<ry<<endl;
	if(lx>=rx||ly>=ry)return 0;
	if(pr[i-1]<i-1&&ne[pr[i-1]]==i)bonus[pr[i-1]]=pc[pr[i-1]];
	if(ne[i]>i&&pr[ne[i]]==i-1)bonus[ne[i]]=sc[ne[i]];
	int x=lx;int sum=0;
	int res=0;
	for(int y=ly;y<ry;y++)
	{
		while(x<rx&&a[x]<a[y]-d)sum+=1+bonus[x++];
		res+=(1+bonus[y])*sum;
	}
	if(pr[i-1]<i-1&&ne[pr[i-1]]==i)bonus[pr[i-1]]=0;
	if(ne[i]>i&&pr[ne[i]]==i-1)bonus[ne[i]]=0;
	return res;
}
int slv()
{
	int n=rd(),d=rd(),p;
	for(int i=0;i<n;i++)a[i]=rd();
	// double las=-1e300,pre=-1e300;
	// int ip=0;
	// a[n]=9e18;
	// for(int i=0;i<=n;i++)
	// {
	// 	double now=double(a[i])/d;if(i==0)pre=now;
	// 	if(now-pre>0.1)cerr<<'['<<ip<<','<<i-1<<']'<<pre<<' ',pre=now,ip=i;
	// 	las=now;
	// }
	p=pr[0]=0;for(int i=1;i<n;i++){while(a[i]-a[p]>d)p++;pr[i]=p;}
	p=ne[n-1]=n-1;for(int i=n-2;i>=0;i--){while(a[p]-a[i]>d)p--;ne[i]=p;}
	// for(int i=0;i<n;i++)cerr<<pr[i]<<','<<ne[i]<<' ';cerr<<endl;
	for(int i=0;i<n;i++)pc[i]=sc[i]=0;
	for(int i=0;i<n;i++)
	{
		if(pr[i]<i)sc[pr[i]]++;
		if(ne[i]>i)pc[ne[i]]++;
	}
	for(int i=0;i<n;i++)if(pr[i]<i&&ne[pr[i]]==i)pc[i]+=pc[pr[i]];
	for(int i=n-1;i>=0;i--)if(ne[i]>i&&pr[ne[i]]==i)sc[i]+=sc[ne[i]];
	int ans=0;
	int lx=0,rx=0,ly=0,ry=0;
	for(int i=2;i<n-1;i++)
	{
		while(lx<n&&a[lx]<a[i]-d)lx++;
		while(rx<n&&a[rx]<a[i+1]-d)rx++;
		while(ly<n&&a[ly]<a[i-2]+d+1)ly++;
		while(ry<n&&a[ry]<a[i-1]+d+1)ry++;
		ans+=calc(lx,rx,ly,ry,i,d);
	}
	return ans;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cout.tie(0);
	int c=rd(),T=rd();
	while(T--)cout<<slv()<<'\n';
}