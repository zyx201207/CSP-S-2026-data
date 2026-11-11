#include <bits/stdc++.h>
using namespace std;

const int N=2e5+7;

int n,m;
int a[N];
int maxa;

namespace _25pts{
	int ans=0;
	void dfs(int pos,int cnt,int adh){
		if(pos==n+1){
			if(cnt==m)ans=max(ans,adh);
			return;
		}
		dfs(pos+1,cnt,adh);
		dfs(pos+1,cnt+1,adh&a[pos]);
	}
}
struct SegmentTree{
	struct sgtr{
		int l,r;
		int sum;
	};
	vector<sgtr> sgt;
	int lfs(int p){
		return p<<1;
	}
	int rfs(int p){
		return p<<1|1;
	}
	bool inr(int p,int l,int r){
		return (l<=sgt[p].l&&sgt[p].r<=r);
	}
	void pushup(int p){
		sgt[p].sum=sgt[lfs(p)].sum&sgt[rfs(p)].sum;
	}
	void build(int p,int l,int r){
		sgt[p].l=l;
		sgt[p].r=r;
		if(l==r){
			sgt[p].sum=a[l];
			return ;
		}
		int mid=(l+r)>>1;
		build(lfs(p),l,mid);
		build(rfs(p),mid+1,r);
		pushup(p);
	}
	int query(int p,int l,int r){
		if(inr(p,l,r)){
			return sgt[p].sum;
		}
		int mid=(sgt[p].l+sgt[p].r)>>1;
		int res=(1ll<<31)-1;
		if(l<=mid){
			res&=query(lfs(p),l,r);
		}
		if(mid<r){
			res&=query(rfs(p),l,r);
		}
		return res;
	}
}wky;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];maxa=max(maxa,a[i]);
	}
	
	if(n<=20){
		_25pts::dfs(1,0,(1ll<<31)-1);
		cout<<_25pts::ans;
		return 0;
	}
	if(n<=2000){
		if(m==1){
			int ans=0;
			for(int i=1;i<=n;i++){
				ans=max(ans,a[i]);
			}
			cout<<ans;
			return 0;
		}
		if(m==n){
			int ans=(1ll<<31)-1;
			for(int i=1;i<=n;i++){
				ans&=a[i];
			}
			cout<<ans;
			return 0;
		}
		if(m==2){
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					ans=max(ans,a[i]&a[j]);
				}
			}
			cout<<ans;
			return 0;
		}
		cout<<0;
		return 0;
	}
	if(m==n-1){
		wky.sgt.resize(4*n+7);
		wky.build(1,1,n);
		int ans=wky.query(1,2,n);
		for(int i=2;i<n;i++){
			ans=max(ans,wky.query(1,1,i-1)&wky.query(1,i+1,n));
			
		}
		ans=max(ans,wky.query(1,1,n-1));
		cout<<ans;
		return 0;
	}
	if(maxa<=4){
		vector<int> t(5,0);
		for(int i=1;i<=n;i++){
			t[a[i]]++;
		}
		if(t[4]>=m){
			cout<<4;
			return 0;
		}
		if(t[3]+t[2]>=m){
			cout<<2;
			return 0;
		}
		if(t[3]+t[1]>=m){
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	cout<<0;
	return 0;
}