#include<bits/stdc++.h>
using namespace std;
namespace T3{
	const int N=2e6+10,INF=0x3f3f3f3f;
	int C,T,n;
	long long d,x[N],ans;
	struct node{
		int d,t;
	}tr[N<<2];
	node add(node x,node y){
		if(x.d<y.d) return x;
		if(x.d>y.d) return y;
		return node{x.d,x.t+y.t};
	}
	void up(int c){
		tr[c]=add(tr[c<<1],tr[c<<1|1]);
	}
	void build(int c,int l,int r){
		tr[c]=node{INF,0};
		if(l==r) return;
		int mid=(l+r)>>1;
		build(c<<1,l,mid);
		build(c<<1|1,mid+1,r);
	}
	void add(int c,int l,int r,int x,node k){
		if(l==r){tr[c]=k; return;}
		int mid=(l+r)>>1;
		if(x<=mid) add(c<<1,l,mid,x,k);
		else add(c<<1|1,mid+1,r,x,k);
		up(c);
	}
	node query(int c,int l,int r,int a,int b){
		if(a<=l&&r<=b) return tr[c];
		int mid=(l+r)>>1;
		node res=node{INF,0};
		if(a<=mid) res=add(res,query(c<<1,l,mid,a,b));
		if(b>mid) res=add(res,query(c<<1|1,mid+1,r,a,b));
		return res;
	}
	void solve(){
		freopen("migrate.in","r",stdin);
		freopen("migrate.out","w",stdout);
		cin >> C >> T;
		while(T--){
			cin >> n >> d;
			for(int i=1;i<=n;i++) cin >> x[i];
			ans=0;
			for(int s=1;s<=n;s++){
				build(1,1,n);
				add(1,1,n,s,node{0,1});
				for(int i=s+1,j=s;i<=n;i++){
					while(x[i]-x[j]>d && j<i) j++;
					node cnt=query(1,1,n,j,i-1);
					add(1,1,n,i,node{cnt.d+1,cnt.t});
					ans+=(cnt.t==2);
				}
			}
			cout << ans << '\n';
		}
	}
}
//namespace force{
//	const int N=2e6+10,INF=0x3f3f3f3f;
//	int C,T,n;
//	long long d,x[N],ans;
//	struct node{
//		int d,t;
//	}tr[N<<2];
//	node add(node x,node y){
//		if(x.d<y.d) return x;
//		if(x.d>y.d) return y;
//		return node{x.d,x.t+y.t};
//	}
//	void up(int c){
//		tr[c]=add(tr[c<<1],tr[c<<1|1]);
//	}
//	void build(int c,int l,int r){
//		tr[c]=node{INF,0};
//		if(l==r) return;
//		int mid=(l+r)>>1;
//		build(c<<1,l,mid);
//		build(c<<1|1,mid+1,r);
//	}
//	void add(int c,int l,int r,int x,node k){
//		if(l==r){tr[c]=k; return;}
//		int mid=(l+r)>>1;
//		if(x<=mid) add(c<<1,l,mid,x,k);
//		else add(c<<1|1,mid+1,r,x,k);
//		up(c);
//	}
//	node query(int c,int l,int r,int a,int b){
//		if(a<=l&&r<=b) return tr[c];
//		int mid=(l+r)>>1;
//		node res=node{INF,0};
//		if(a<=mid) res=add(res,query(c<<1,l,mid,a,b));
//		if(b>mid) res=add(res,query(c<<1|1,mid+1,r,a,b));
//		return res;
//	}
//	void solve(){
//		freopen("migrate3.in","r",stdin);
////		freopen("migrate.out","w",stdout);
//		cin >> C >> T;
//		while(T--){
//			cin >> n >> d;
//			for(int i=1;i<=n;i++) cin >> x[i];
//			ans=0;
//			for(int s=1;s<=n;s++){
//				build(1,1,n);
//				add(1,1,n,s,node{0,1});
//				for(int i=s+1,j=s;i<=n;i++){
//					while(x[i]-x[j]>d && j<i) j++;
//					node cnt=query(1,1,n,j,i-1);
//					add(1,1,n,i,node{cnt.d+1,cnt.t});
//					ans+=(cnt.t==2);
//				}
//			}
//			cout << ans << '\n';
//		}
//	}
//}
//namespace RAND{
//	mt19937 rng(time(NULL));
//	long long rd(long long l,long long r){return rng()%(r-l+1)+l;}
//	void solve(){
//		freopen("crystal.in","w",stdout);
//		const long long N=8,M=1e12;
//		int n=rd(1,N),m=rd(1,M);
//		cin >> C >> T;
//		cout << C << ' ' << T << '\n';
//		while(T--){
//			cin >> n >> d;
//			for(int i=1;i<=n;i++) cin >> x[i];
//			cout << n << ' ' << d << '\n';
//			for(int i=1;i<=n;i++) cout << x[i] << ' ';
//			cout << '\n';
//		}
//	}
//}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
//	force::solve();
	T3::solve();
	
	
	
	return 0;
}
