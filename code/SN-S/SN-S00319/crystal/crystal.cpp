#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
#define fi first
#define se second

const int N=5e5+5;
int a[N],sum[N];

int check(int l,int r) {
	const int target=a[r];
	const int len=r-l+1;
	const int delta=sum[r]-sum[l-1];
	const int need=-delta+len*target; // up to 1e17
	return need;
}

int erfenl(int L,int R,const int r,const int m) {
	if(L==R) return r-R+1; // return length
	int mid=(L+R)>>1;
	if(check(mid,r)<=m) return erfenl(L,mid,r,m);
	else return erfenl(mid+1,R,r,m);
}

signed main() {
	#ifndef dbg
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	#endif
	
	int n,m,mx=0; cin >> n >> m;
	rep(i,1,n) 
		cin >> a[i];	
	sort(a+1,a+n+1);
	rep(i,1,n) sum[i]=sum[i-1]+a[i];
	rep(r,1,n) { // numbers to be topped up
		mx=max(mx,erfenl(1,r,r,m));
	}
	cout << mx << '\n';
}
