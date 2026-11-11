#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define mid (l+r>>1)
#define PII pair<int,int>
#define ll long long
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define per(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define lbt(x) ((x)&(-x))
#define pb push_back

const int N = 2e6 + 10;

int n,L[N],R[N],f[N],g[N];
ll a[N],d,ans;
vector<int>pl[N],pr[N];
void solve(){
	cin>>n>>d;
	rep(i,1,n) cin>>a[i];
	int ps=1;
	rep(i,1,n)f[i]=g[i]=0,pl[i].clear(),pr[i].clear();
	rep(i,1,n){
		while(ps<i&&a[i]-a[ps]>d)ps++;
		L[i]=ps;pr[L[i]].pb(i);
	}ps=n;
	per(i,n,1){
		while(ps>i&&a[ps]-a[i]>d)ps--;
		R[i]=ps;pl[R[i]].pb(i);
	}
	ans=0;
	rep(i,1,n){
		if(R[L[i]]==i)f[i]=f[L[i]]+1;
		for(auto x : pl[i])if(x>L[i])f[i]++;
	}
	per(i,n,1){
		if(L[R[i]]==i)g[i]=g[R[i]]+1;
		for(auto x : pr[i])if(x<R[i]) g[i]++;
	}
//	rep(i,1,n) cout<<L[i]<<' '<<R[i]<<" "<<f[i]<<' '<<g[i]<<"\n";
	rep(i,2,n-2){   //枚举中间点 
		int l=0,r=0;
		if(R[L[i]]==i+1)l=f[L[i]];
		if(L[R[i+1]]==i)r=g[R[i+1]];
		for(auto x : pl[i+1])if(x<i&&x>=L[i])l++;
		for(auto x : pr[i])if(i+1<x&&x<=R[i+1])r++;
//		cout<<i<<" "<<l<<" "<<r<<" "<<l*r<<"\n";
		ans+=(ll)l*r;
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,T=1;
	cin >>c>> T;
	while (T--){
		solve();
	}
	return 0;
}
/*
检查空间，UB，未初始化变量，数组下标
别急

考虑枚举那个中间点，然后做一些分讨即可 
具体的，求出每个点向左一步到哪，向右一步到哪
特判起点的情况 
O(n)
0 1
10 3
0 3 6 7 8 9 10 13 16 19
*/

