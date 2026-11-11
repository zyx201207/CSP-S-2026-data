#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10; 
int n,m,a[N],s[N]; 
struct node{
	int l,r;
	int maxn=-1e18;  	
}tr[N<<2];
void pushup(int u){
	tr[u].maxn=max(tr[u<<1].maxn,tr[u<<1|1].maxn); 
}
void build(int u,int l,int r){
	tr[u].l=l,tr[u].r=r;
	if(l==r){
		tr[u].maxn=a[l]; 
		return;
	}
	int mid=l+r>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r); 
	pushup(u); 
} 
int query(int u,int l,int r){
	if(l<=tr[u].l&&tr[u].r<=r)return tr[u].maxn; 
	int ans=-1e18;
	int mid=tr[u].l+tr[u].r>>1;
	if(l<=mid)ans=max(ans,query(u<<1,l,r));
	if(r>mid)ans=max(ans,query(u<<1|1,l,r));
	return ans; 
}
bool check(int mid){ 
	for(int l=1;l+mid-1<=n;l++){
		int r=l+mid-1; 
		int mx=query(1,l,r),ans=0; 
		ans=mx*mid-(s[r]-s[l-1]); 
		if(ans<=m)return true; 
	}
	return false; 
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);  
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i]; 
	build(1,1,n);
	int l=0,r=n;
	while(l<r){
		int mid=l+r+1>>1;
		if(check(mid))l=mid;
		else r=mid-1; 
	}
	cout<<l; 
	return 0; 
}
