#include <bits/stdc++.h>
#define pr pair<int,int>
#define fi first
#define se second
#define mk make_pair
#define For(i,l,r) for(int i=(l);i<=(r);i++)
#define Rep(i,r,l) for(int i=(r);i>=(l);i--)
#define ll long long
using namespace std;
const int N=2e6+5;
const ll inf=1e18;
int Cid,Uid,_;
int n,ne[N],la[N],sl[N],ansl[N],ansr[N];
ll an,a[N],D;
void chkmn(int &x,int y){x=min(x,y);}
void chkmx(int &x,int y){x=max(x,y);}
void solve(int *ans){
	int j=1;
	For(i,1,n){
		while(a[j]+D<a[i]) ++j;
		la[i]=j;
	}j=1;
	For(i,1,n){
		while(j<n&&a[i]+D>=a[j+1]) ++j;
		ne[i]=j;
	}For(i,1,n-1){
		sl[i]=min(i,la[i+1])-la[i]+1;
		if(la[i]<i&&ne[la[i]]==i) sl[i]+=sl[la[i]]-1;
	}
	int x;
	For(now,3,n-1){
		ans[now]=0;
		x=la[now-1];
		if(x<now-1&&ne[x]==now) ans[now]=sl[x]-1;
		ans[now]+=max(0,min(la[now+1],now-1)-la[now]);
	}
	
}void MAIN_solve(){
	cin>>n>>D;
	For(i,1,n) cin>>a[i];
	solve(ansl);
	For(i,1,n) a[i]=a[n]-a[i]+1;
	for(int l=1,r=n;l<r;++l,--r) swap(a[l],a[r]);
	solve(ansr);
	an=0;
	For(i,3,n-1) an+=1ll*ansl[i]*ansr[n+1-(i-1)];
	cout<<an<<"\n";
}signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>Cid>>_;
	for(Uid=1;Uid<=_;Uid++) MAIN_solve();
	return 0;
}/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
4 2
1 2 3 4

0 1
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
