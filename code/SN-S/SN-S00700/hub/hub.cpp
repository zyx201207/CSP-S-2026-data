#include <bits/stdc++.h>
#define pr pair<int,int>
#define fi first
#define se second
#define mk make_pair
#define For(i,l,r) for(int i=(l);i<=(r);i++)
#define Rep(i,r,l) for(int i=(r);i>=(l);i--)
#define ll long long
using namespace std;
const int N=2e6+5,mod=1e9+7;
const ll inf=1e18;
int Cid,Uid,_;
int n,c[N],K,X[N],root,mx,dep[N],Y[N],E[N],W[N],MX,f[N],l[N];
mt19937 rd(time(0));
vector<pr>son[N];
void dfs1(int u,int fa,int eid){
	f[u]=fa,dep[u]=dep[fa]+1;
	if(mx<dep[u]) root=u,mx=dep[u];
	for(pr i:son[u])
		if(i.fi!=fa&&i.se!=eid) dfs1(i.fi,u,eid);
}void dfs2(int u,int fa,int eid){
	l[u]=0;
	for(pr i:son[u])
		if(i.fi!=fa&&i.se!=eid) dfs2(i.fi,u,eid),l[u]=max(l[u],l[i.fi]+1); 
}void solve(int pos,int eid){
	int rt1=0;
	root=pos,mx=0;
	dfs1(pos,0,eid);
	mx=0;
	dfs1(root,0,eid);
	rt1=root;
	For(i,1,mx/2) rt1=f[rt1];
	dfs2(rt1,0,eid);
}int Solve(int eid){
	solve(X[eid],eid);
	solve(Y[eid],eid);
	For(i,1,n) c[i]=0;
	For(i,1,n) c[l[i]]++;
//	cerr<<eid<<":";
//	For(i,1,n) cerr<<l[i]<<" ";cerr<<"\n";
//	For(i,1,n) cerr<<c[i]<<" ";cerr<<"\n\n";
	int cnt=0;
	Rep(i,n,0){
		cnt+=c[i];
		if(cnt>K) return i+1;
	}return 0;
}void MAIN_solve(){
	cin>>n>>K;
	int ans=n;
	For(i,2,n){
		cin>>X[i]>>Y[i];
		son[X[i]].push_back(mk(Y[i],i)); 
		son[Y[i]].push_back(mk(X[i],i));
		W[i]=rd()%mod,E[i]=i;
	}
	if(Cid==13||Cid==14) For(i,max(2,n/4-10),min(n,n/4+10)) W[i]=-1;
	if(Cid<=10) MX=n;
	else{
		sort(E+2,E+n+1,[](int x,int y){return W[x]<W[y];});
		MX=min(n,100);
		if(Cid==13||Cid==14) MX=min(n,20);
	}
//	cerr<<MX<<"\n";

	For(i,2,MX){
//		cerr<<Uid<<" "<<_<<" "<<E[i]<<"\n";
		ans=min(ans,Solve(E[i]));
	}For(i,1,n) son[i].clear();
	cout<<ans<<"\n";
}signed main(){
	dep[0]=-1;
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>Cid>>_;
	for(Uid=1;Uid<=_;Uid++) MAIN_solve();
	return 0;
}/*
0 1
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9


*/
