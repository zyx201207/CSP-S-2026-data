#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(n) for(int i=1;i<=(n);i++)
#define V vector
#define pb push_back
#define endl '\n'
#define sc if(debug)cerr
constexpr bool debug=0;
constexpr int _=1000005,mod=998244353,INF=1000000000000000009ll;
const string FLNM="crystal";
int n,m;
int a[_],sm[_];
bool check(int o){
	for(int i=o;i<=n;i++){
		//a[i]~a[i-o+1]
		if(a[i]*o-(sm[i]-sm[i-o])<=m)return 1;
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	(void)!freopen((FLNM+".in").c_str(),"r",stdin);
	(void)!freopen((FLNM+".out").c_str(),"w",stdout);
	if(debug)(void)!freopen((FLNM+".err").c_str(),"w",stderr);
	cin>>n>>m;
	FOR(n)cin>>a[i];
	sort(a+1,a+n+1);
	FOR(n)sm[i]=sm[i-1]+a[i];
	int L=1,R=n+1;
	while(L+1<R){
		int mid=(L+R)/2;
		if(check(mid))L=mid;
		else R=mid;
	}
	cout<<L<<endl;
}
