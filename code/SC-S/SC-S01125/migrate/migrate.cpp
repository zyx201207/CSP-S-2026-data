#include <bits/stdc++.h> 
#define int long long
using namespace std ;

const int N=2e6+10 ;
int n,d,cnt=0 ; bool flag=0 ;
int a[N],mincost=2e6,tot=0 ; unordered_map<int,bool> hav ;
int T,type1 ; 

inline void dfs2(int l,int r,int now,int cost) {
	if(flag||now>a[r]) return ;
	if(now==a[r]) {
		if(cost==mincost) tot++ ;
		if(tot>2) flag=1 ;
		return ;
	}
	for(int k=1;k<=d;k++) if(hav.count(now+k)!=0) {
		dfs2(l,r,now+k,cost+1) ;
	}
}
inline void dfs1(int l,int r,int now,int cost) {
	if(cost>mincost||now>a[r]) return ;
	if(now==a[r]) mincost=min(mincost,cost) ;
	for(int k=1;k<=d;k++) {
		dfs1(l,r,now+k,cost+1) ;
	}
}
inline void solve() {
	hav.clear() ;
	cin>>n>>d ;
	for(int i=1;i<=n;i++) {cin>>a[i] ; hav[a[i]]=1 ;}
	if(type1==11||type1==12) {
		int dif=a[2]-a[1] ;
		if(d<=dif) cout<<"0\n" ;
		else cout<<max(0ll,n-(d/dif)*2+1)<<"\n" ;
		return ;
	}
	int ans=0 ;
	for(int l=1;l<=n;l++) for(int r=l+1;r<=n;r++) {
		flag=0 ; tot=0 ; mincost=2e6 ;
		dfs1(l,r,a[l],0) ;
		dfs2(l,r,a[l],0) ;
		if(tot==2) ans++ ;
	}
	cout<<ans<<"\n" ;
}

signed main() {
	freopen("migrate.in","r",stdin) ;
	freopen("migrate.out","w",stdout) ;
	ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
	
	cin>>type1>>T ; while(T--)
		solve() ;
	
	return 0 ;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
1
2

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6


10 3
0 3 6 7 8 9 10 13 16 19

10 22
0 7 14 21 28 35 42 49 56 63
*/