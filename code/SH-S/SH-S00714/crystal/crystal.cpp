#include<bits/stdc++.h>
using namespace std;
#define N 500008
long long m,a[N];
struct segment_tree{
	int l,r;
	long long sum,tag;
}tr[N<<2];
void build_tree(int node,int l,int r){
	tr[node].l=l;tr[node].r=r;
	if(l==r) return;
	int mid=(l+r)>>1;
	build_tree(node<<1,l,mid);
	build_tree(node<<1|1,mid+1,r);
}
void pushdown(int node){
	tr[node<<1].tag+=tr[node].tag;
	tr[node<<1|1].tag+=tr[node].tag;
	tr[node<<1].sum+=tr[node].tag*(tr[node<<1].r-tr[node<<1].l+1);
	tr[node<<1|1].sum+=tr[node].tag*(tr[node<<1|1].r-tr[node<<1|1].l+1);
	tr[node].tag=0;
}
void add(int node,int l,int r,long long val){
	if(tr[node].l==l&&tr[node].r==r){
		tr[node].sum+=val*(r-l+1);
		tr[node].tag+=val;
		return;
	}
	pushdown(node);
	int mid=(tr[node].l+tr[node].r)>>1;
	if(r<=mid) add(node<<1,l,r,val);
	else if(l>mid) add(node<<1|1,l,r,val);
	else add(node<<1,l,mid,val),add(node<<1|1,mid+1,r,val);
	tr[node].sum=tr[node<<1].sum+tr[node<<1|1].sum;
}
int search(int node,long long val){
	if(tr[node].l==tr[node].r) return (tr[node].sum<=val?tr[node].l:tr[node].l+1);
	pushdown(node);
	if(tr[node<<1|1].sum>val) return search(node<<1|1,val);
	else return search(node<<1,val-tr[node<<1|1].sum);
}
int n,res;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	build_tree(1,1,n);
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(i>1) add(1,1,i-1,a[i]-a[i-1]);
		res=max(res,i+1-search(1,m));
	}
	cout<<res;
	return 0;
}
