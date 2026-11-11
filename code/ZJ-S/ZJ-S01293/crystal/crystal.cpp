#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;

int n,ans;
long long m,a[N];

struct Segment{
	long long val[N<<2],lazy[N<<2];
	
	void push_up(int u){
		val[u]=val[u<<1]+val[u<<1|1];
	}
	
	void push_down(int l,int r,int u){
		if (lazy[u]!=0){
			int mid=(l+r)>>1;
			val[u<<1]+=lazy[u]*(mid-l+1);
			lazy[u<<1]+=lazy[u];
			val[u<<1|1]+=lazy[u]*(r-mid);
			lazy[u<<1|1]+=lazy[u];
			lazy[u]=0;
		}
	}
	
	void upd(int L,int R,long long x,int l,int r,int u){
		if (L<=l && r<=R){
			val[u]+=x*(r-l+1);
			lazy[u]+=x;
			return;
		}
		push_down(l,r,u);
		int mid=(l+r)>>1;
		if (L<=mid)  upd(L,R,x,l,mid,u<<1);
		if (R>mid)  upd(L,R,x,mid+1,r,u<<1|1);
		push_up(u);
	}
	
	int query(long long x,int l,int r,int u){
		if (l==r){
			if (x>=val[u])  return 1;
			else  return 0;
		}
		push_down(l,r,u);
		int mid=(l+r)>>1;
		long long tmp=val[u<<1|1];
		if (x<tmp)
			return query(x,mid+1,r,u<<1|1);
		else  return query(x-tmp,l,mid,u<<1)+r-mid;
	}
}seg;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		if (i>1)  seg.upd(1,i-1,a[i]-a[i-1],1,n,1);
		ans=max(ans,seg.query(m,1,n,1)-(n-i));
	}
	cout<<ans;
	return 0;
}