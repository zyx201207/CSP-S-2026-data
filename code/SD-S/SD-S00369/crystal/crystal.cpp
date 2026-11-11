#include<bits/stdc++.h> 
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],pre[N]; 
struct T{
	int l,r,sum;
}tr[N*4];
void pushup(int k){
	tr[k].sum=max(tr[k<<1].sum,tr[k<<1|1].sum);
}
void build(int k,int l,int r){
	tr[k]={l,r,0};
	if(l==r){
		tr[k].sum=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	pushup(k);
}
int query(int k,int l,int r){
	if(l<=tr[k].l&&tr[k].r<=r){
		return tr[k].sum;
	}
	int mid=(tr[k].l+tr[k].r)>>1,res=-1e18;
	if(l<=mid) res=max(res,query(k<<1,l,r));
	if(r>mid) res=max(res,query(k<<1|1,l,r));
	return res;
}
bool check(int len){
	for(int i=1;i+len-1<=n;i++){
		int mx=query(1,i,i+len-1),tot=pre[i+len-1]-pre[i-1];
		if(mx*len-tot<=m) return 1;
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	build(1,1,n);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<r;
	return 0;
}
