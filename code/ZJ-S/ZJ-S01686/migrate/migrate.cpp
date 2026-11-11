#include <bits/stdc++.h>
#define int long long
using namespace std;
namespace solve1{
	const int N=5010;
	const int INF=1e18;
	struct node{
		int mi;int cnt;
		node operator+(const node &b)const{
			if(mi<b.mi) return {mi,cnt};
			else if(mi>b.mi) return b;
			else return {mi,cnt+b.cnt};
		}	
	};
	struct seg{
		int l,r;
		node x,lazy;
	}sg[N<<2];
	void pushup(int u){
		sg[u].x=sg[u<<1].x+sg[u<<1|1].x;
	}
	void upd(int u,node x){
		sg[u].x=sg[u].x+x;
		sg[u].lazy=sg[u].lazy+x;
	}
	void pushdown(int u){
		if(sg[u].lazy.mi==INF&&sg[u].lazy.cnt==0) return;
		upd(u<<1,sg[u].lazy);
		upd(u<<1|1,sg[u].lazy);
		sg[u].lazy={INF,0};
	}
	void build(int u,int l,int r){
		sg[u]={l,r,{INF,0},{INF,0}};
		if(l==r){
			return;
		}
		int mid=l+r>>1;
		build(u<<1,l,mid);build(u<<1|1,mid+1,r);
		pushup(u);
	}
	void modify(int u,int l,int r,node x){
		if(l>r) return;
		if(l<=sg[u].l&&sg[u].r<=r){
			upd(u,x);return;
		}
		pushdown(u);
		int mid=sg[u].l+sg[u].r>>1;
		if(l<=mid) modify(u<<1,l,r,x);
		if(r>mid) modify(u<<1|1,l,r,x);
		pushup(u);
	}
	node query(int u,int pos){
		if(sg[u].l==sg[u].r&&sg[u].l==pos){
			return sg[u].x;
		}
		pushdown(u);
		int mid=sg[u].l+sg[u].r>>1;
		if(pos<=mid) return query(u<<1,pos);
		else return query(u<<1|1,pos);
	}
	void solve(){
		int n,d;cin>>n>>d;
		vector<int>a(n+3),L(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n==1){
			cout<<"0\n";return;
		}
		int pos=1;
		for(int i=1;i<=n;i++){
			while(pos<=n&&a[pos]-a[i]<=d) pos++;
			pos--;
			L[i]=pos;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			build(1,1,n);
			modify(1,i,i,{0,1});
			for(int j=i;j<n;j++){
				auto xx=query(1,j);
				modify(1,j+1,L[j],{xx.mi+1,xx.cnt});
			}
			for(int j=i+1;j<=n;j++){
				if(query(1,j).cnt==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
}
namespace solve2{
	void solve(){
		int n,d;cin>>n>>d;
		vector<int>a(n+3),L(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n==1){
			cout<<"0\n";return;
		}
		int de=a[2]-a[1];
		int k=d/de;k=min(k,n-1);
		if(k<=1){
			cout<<"0\n";return;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(i+2*k-1<=n) ans++;
		}
		cout<<ans<<'\n';
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	int cid,T;cin>>cid>>T;
	while(T--){
		if(cid==11||cid==12) solve2::solve();
		else solve1::solve();
	}
	return 0;
}
