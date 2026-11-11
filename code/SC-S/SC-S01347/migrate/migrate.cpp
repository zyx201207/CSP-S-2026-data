#include<bits/stdc++.h>
#define LL long long
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define dow(i,j,k) for(int i=j;i>=k;i++)
using namespace std;
const int N=2e6+5;
const LL inf=1e18;
int c,T,n;
LL x[N],d,ans;
struct node{
	int min,cnt;
}a[5005][5005];
void insert(int i,int j,node gg)
{
	if(gg.min<a[i][j].min) a[i][j].min=gg.min,a[i][j].cnt=0;
	if(gg.min==a[i][j].min) a[i][j].cnt+=gg.cnt;
}
void solve1()
{
	ans=0;
	rep(i,1,n) rep(j,i+1,n) a[i][j].min=n+1,a[i][j].cnt=0;
	rep(i,1,n) a[i][i].cnt=1;
	rep(i,1,n)
	  rep(j,i+1,n)
	  {
	  	rep(k,i,j)
	      if(x[j]-x[k]<=d)
			insert(i,j,{a[i][k].min+1,a[i][k].cnt});
		if(a[i][j].cnt==2) ans++;
	  }
	printf("%lld\n",ans);
}
void solve2()
{
	if(n==1)
	{
		puts("0");
		return;
	}
	LL tt=d/(x[2]-x[1]);
	if(tt<=1)
	{
		puts("0");
		return;
	}
	tt=tt*2-1;
	printf("%lld\n",max(0ll,n-tt));
}
void solve()
{
	scanf("%d%lld",&n,&d);
	rep(i,1,n) scanf("%lld",&x[i]);
	if(c<=6) solve1();
	if(c==11||c==12) solve2();
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--) solve();
	return 0;
}