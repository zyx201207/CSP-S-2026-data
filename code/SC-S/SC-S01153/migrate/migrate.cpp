#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long
#define endl '\n'
using namespace std;
const int maxn=2e6+5;
int n,d,a[maxn],dp1[maxn],dp2[maxn],ans;
void init()
{
	for(int i=1;i<=n;i++) dp1[i]=inf,dp2[i]=0;
}
void f(int s)
{
	init();
	dp1[s]=0,dp2[s]=1;
	set<pair<int,int> > ss;
	ss.insert({0,1});
	for(int i=s+1,l=s;i<=n;i++)
	{
		while(a[i]-a[l]>d)
		{
			auto it=ss.lower_bound({dp1[l],0});
			int x=it->first,y=it->second;
			ss.erase(it);
			y-=dp2[l];
			if(y) ss.insert({x,y});
			l++;
		}
		dp1[i]=ss.begin()->first+1;
		dp2[i]=ss.begin()->second;
		auto it=ss.lower_bound({dp1[i],0});
		if(it==ss.end()||it->first!=dp1[i]) ss.insert({dp1[i],dp2[i]});
		else
		{
			int x=it->first,y=it->second;
			ss.erase(it);
			y+=dp2[i];
			ss.insert({x,y});
		}
		if(dp2[i]==2) ans++;
	}
}
void solve()
{
	cin>>n>>d,ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) f(i);
	cout<<ans<<endl;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int _,t;cin>>_>>t;
	while(t--) solve();
	return 0;
}
/*
1 1
10 285714285714285708
-1000000000000000000 -714285714285714292 -428571428571428584 -238095238095238112 -142857142857142876 -47619047619047640 142857142857142832 428571428571428540 714285714285714248 999999999999999956
out:7
*/
/*
Êý×é´óÐ¡¿´ÁËÂð£¿ok
²¿·Ö·ÖÄÃÁËÂð£¿ok
ÄÚ´æËãÁËÂð£¿ok
*/
