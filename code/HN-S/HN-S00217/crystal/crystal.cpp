//luogu uid:795344

/*
 * last 30min:
 * 1. freopen 
 * 2. long long
 * 3. Memory check
 * 4. Time Limit
 * 5. Array bouns
 * 6. Compile
 * */
 // 100+100+45+x+15=260+x(x>=10) zzz
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,l,r) for(int i=l;i<=r;++i)
#define ROF(i,r,l) for(int i=r;i>=l;--i)
#define FORK(i,l,r,k) for(int i=l;i<=r;i+=k)
#define ROFK(i,r,l,k) for(int i=r;i>=l;i-=k)
#define florrio ios::sync_with_stdio(false),cin.tie(0)
constexpr int N=5e5+5;
int s[N],a[N];
void Init()
{
}
void Solve()
{
	int n,m,ans=0;
	cin>>n>>m;
	FOR(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	FOR(i,1,n)s[i]=s[i-1]+a[i];
	for(int i=1,j=1;i<=n;++i)
	{
		for(;j<=i&&a[i]*(i-j+1)-(s[i]-s[j-1])>m;++j);
		ans=max(ans,i-j+1);
	}
	cout<<ans<<'\n';
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	florrio;
	double _st=clock();
	int T=1;
	//cin>>T;
	FOR(i,1,T)
	{
		Solve();
	}
	cerr<<"used time:"<<(clock()-_st)/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
