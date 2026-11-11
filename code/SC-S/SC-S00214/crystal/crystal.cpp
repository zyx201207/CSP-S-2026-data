#include<bits/stdc++.h>
#define ll long long
#define ls rt<<1
#define rs rt<<1|1
using namespace std;
const int N=5e5+5;
int n,ans=1;
ll m,b[N];
struct node{
	ll sum,add;
} a[N<<2];
void pushup(int rt){
	a[rt].sum=a[ls].sum+a[rs].sum;
}
void pushdown(int rt,int l,int r){
	if(a[rt].add){
		a[ls].add+=a[rt].add,a[rs].add+=a[rt].add;
		int mid=(l+r)>>1;
		a[ls].sum+=a[rt].add*(mid-l+1);
		a[rs].sum+=a[rt].add*(r-mid);
		a[rt].add=0; 
	}
}
void update(int L,int R,int l,int r,ll x,int rt){
	if(L<=l&&r<=R){
		a[rt].add+=x,a[rt].sum+=(r-l+1)*x;
		return;
	}
	pushdown(rt,l,r);
	int mid=(l+r)>>1;
	if(L<=mid) update(L,R,l,mid,x,ls);
	if(R>mid) update(L,R,mid+1,r,x,rs);
	pushup(rt);
}
ll query(int L,int R,int l,int r,int rt){
	if(L<=l&&r<=R) return a[rt].sum;
	pushdown(rt,l,r);
	int mid=(l+r)>>1;
	ll res=0;
	if(L<=mid) res+=query(L,R,l,mid,ls);
	if(R>mid) res+=query(L,R,mid+1,r,rs);
	return res;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	sort(b+1,b+n+1);
	for(int i=2;i<=n;i++){
		update(1,i-1,1,n,b[i]-b[i-1],1);
		int l=1,r=i,res=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(query(mid,i,1,n,1)<=m){
				res=mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9*/