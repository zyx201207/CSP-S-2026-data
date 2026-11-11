#include<bits/stdc++.h>
using namespace std;
//bool MS;
const int N=5e5+5;
typedef long long ll;
const ll Inf=0x3f3f3f3f3f3f3f3f;
int n;ll m,a[N];
namespace sgt{
	ll sum[N<<2],add[N<<2];
	int ls(int x){return x<<1;}
	int rs(int x){return x<<1|1;}
	void push_up(int x){
		sum[x]=sum[ls(x)]+sum[rs(x)];
		return;
	}
	void push_down_add(int x,int l,int r,ll k){
		sum[x]+=1ll*(r-l+1)*k;
		add[x]+=k;
		return;
	}
	void push_down(int x,int l,int r){
		if(!add[x])return;
		int mid=l+r>>1;
		push_down_add(ls(x),l,mid,add[x]);
		push_down_add(rs(x),mid+1,r,add[x]);
		add[x]=0;
		return;
	}
	void update(int l,int r,ll k,int x=1,int nowl=0,int nowr=n){
 		if(l<=nowl&&nowr<=r)return void(push_down_add(x,nowl,nowr,k));
		int mid=nowl+nowr>>1;
		push_down(x,nowl,nowr);
		if(l<=mid)update(l,r,k,ls(x),nowl,mid);
		if(mid<r)update(l,r,k,rs(x),mid+1,nowr);
		push_up(x);
		return;
	}
	int query(ll k,int x=1,int l=0,int r=n){
		if(l==r)return l;
		push_down(x,l,r);
		int mid=l+r>>1;
		return sum[rs(x)]>k?query(k,rs(x),mid+1,r):query(k-sum[rs(x)],ls(x),l,mid);
	}
	ll query_sum(int l,int r,int x=1,int nowl=0,int nowr=n){
		if(l<=nowl&&nowr<=r)return sum[x];
		int mid=nowl+nowr>>1;
		push_down(x,nowl,nowr);
		if(l>mid)return query_sum(l,r,rs(x),mid+1,nowr);
		if(mid>=r)return query_sum(l,r,ls(x),nowl,mid);
		return query_sum(l,r,ls(x),nowl,mid)+query_sum(l,r,rs(x),mid+1,nowr);
	}
}
//bool MT;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	int res=1;
	sgt::update(0,0,Inf);
	for(int i=2;i<=n;++i){
		sgt::update(1,i-1,a[i]-a[i-1]);
		res=max(res,i-sgt::query(m));
//		cout<<sgt::query(m)+1<<' '<<i<<' '<<(sgt::query_sum(sgt::query(m)+1,n)<=m)<<'\n';
//		for(int j=1;j<=n;++j)cout<<sgt::query_sum(j,n)<<' ';cout<<'\n';
	}
	cout<<res<<'\n';
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	int cl=clock();
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int _=1;
	while(_--)solve();
//	cerr<<fixed<<setprecision(2)<<1.0*(clock()-cl)/CLOCKS_PER_SEC<<"s\n";
//	cerr<<1.0*(&MT-&MS)/1024.0/1024.0<<"MB\n";
	return 0;
}
/*
华风夏韵，洛水天依！
//freopen("crystal.in","r",stdin);
关注洛天依谢谢喵~
luogu1040109 
/bx Pyrf_uqcat
%%% orz
2026 CSP-S rp++
T1 应该不会挂 
*/ 
