#include<bits/stdc++.h>
#define int long long
#define si signed
#define endl '\n'
#define fst ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fp(s) string ssss=s;freopen((ssss+".in").c_str(),"r",stdin);freopen((ssss+".out").c_str(),"w",stdout);
#define rep(i,x,y) for(int i=x;i<=(y);++i)
#define per(i,x,y) for(int i=x;i>=(y);--i)
#define inl inline
#define INF 1e18
#define eb emplace_back
using namespace std;
const int N=2e6+5;
int a[N],nxt[N],lst[N],suml[N],sumr[N],lenl[N],lenr[N],topl[N],topr[N];
inl void solve(){
	int n,d,r=0,l=1,ans=0;
	cin>>n>>d;
	rep(i,1,n) cin>>a[i];
	rep(i,1,n){
		while(r<n&&a[r+1]-a[i]<=d) ++r;
		nxt[i]=r;
	}
	rep(i,1,n){
		while(l<n&&a[i]-a[l]>d) ++l;
		lst[i]=l;
	}
	rep(i,1,n)
		if(lst[i]!=i){
			suml[i]=i+suml[lst[i]];
			lenl[i]=1+lenl[lst[i]];
			topl[i]=topl[lst[i]];
		}else{
			suml[i]=i;
			lenl[i]=0;
			topl[i]=i;
		}
	per(i,n,1)
		if(nxt[i]!=i){
			sumr[i]=i+sumr[nxt[i]];
			lenr[i]=1+lenr[nxt[i]];
			topr[i]=topr[nxt[i]];
		}else{
			sumr[i]=i;
			lenr[i]=0;
			topr[i]=i;
		}
	rep(i,2,n)
		if(a[i]-a[i-1]<=d&&lst[i]!=i-1&&nxt[i-1]!=i&&lst[nxt[i-1]]==i-1&&nxt[lst[i]]==i){
			int cntl=1,cntr=1;
			if(lst[i]==lst[i-1])
				if(!lenl[i-1]) cntl=0;
				else if(lenl[i-1]==lenl[i-2]) cntl=lst[i+1]-topl[i-1]+1-(suml[i-1]-suml[i-2]);
				else cntl=suml[i-1]-suml[i-2]-topl[i-1];
			if(nxt[i]==nxt[i-1])
				if(!lenr[i]) cntr=0;
				else if(lenr[i]==lenr[i+1]) cntr=topr[i]-nxt[i-2]+1-(sumr[i+1]-sumr[i]);
				else cntr=sumr[i+1]-sumr[i]+topr[i];
			ans+=cntl*cntr;
//			cout<<i<<' '<<cntl<<' '<<cntr<<endl; 
		}
	cout<<ans<<endl;
}
si main(){
	fp("migrate");
	fst;
	int c,t;
	cin>>c>>t;
	while(t--) solve();
	return 0;
} 
/*
0 1
5 3
-3 0 2 3 4

0 1
6 4
-3 0 1 2 3 4

0 1
6 1200000000000000000
-1000000000000000000 -600000000000000000 -200000000000000000 200000000000000000 600000000000000000 1000000000000000000
*/
