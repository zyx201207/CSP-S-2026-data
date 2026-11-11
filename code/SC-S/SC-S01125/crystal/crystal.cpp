#include <bits/stdc++.h> 
#define int long long
using namespace std ;

const int N=5e5+10 ;
int a[N],pre[N],ppre[N],n,m ;

int getcost(int l,int r) {
	return a[r]*(r-l)-(pre[r-1]-pre[l-1]) ;
}
bool check(int len) {
	for(int l=1;l+len-1<=n;l++) {
		int r=l+len-1 ;
		if(getcost(l,r)<=m) return 1 ;
	}
	return 0 ;
}

signed main() {
	freopen("crystal.in","r",stdin) ;
	freopen("crystal.out","w",stdout) ;
	ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
	
	cin>>n>>m ;
	for(int i=1;i<=n;i++) cin>>a[i] ;
	sort(a+1,a+1+n) ;
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i] ;
	int l=2,r=n,ans=0 ;
	while(l<=r) {
		int mid=(l+r)>>1 ;
		if(check(mid)) {l=mid+1 ; ans=mid ;}
		else r=mid-1 ;
	}
	cout<<ans ;
	
	return 0 ;
}
/*
5 8
-3 -1 2 2 7

5 0
1 2 4 8 9

6 0
1 1 1 1 1 1
*/