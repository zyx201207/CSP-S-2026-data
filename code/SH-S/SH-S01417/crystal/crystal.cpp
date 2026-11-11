#include <bits/stdc++.h>
using namespace std;
using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,l,r) for(int i=(l);i>=(r);--i)
#define repn(i,n)  for(int i=0;i<(n);++i)
#define sizc(x) (int((x).size()))
#define allc(x) (x).begin(),(x).end()
#define fir first
#define sec second

constexpr int N=5e5+5;

int n;
ll m,a[N],s[N];

bool chk(int k){
	rep(i,k,n){
		ll d=a[i]*k-(s[i]-s[i-k]);
		if(d<=m)return 1;
	}
	return 0;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m;
	rep(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	rep(i,1,n)s[i]=s[i-1]+a[i];
	int l=0,r=n;while(l<r){
		int mid=l+r+1>>1;
		if(chk(mid))l=mid;
		else r=mid-1;
	}
	cout<<l<<'\n';
}
