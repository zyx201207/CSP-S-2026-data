#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200005;
vector<int> adj[N];
struct node{
	int l,r,sum;
	int lz;
	int mul;
}tree[N];
void build(int i,int l,int r){
	tree[i].l=l;
	tree[i].r=r;
	tree[i].lz=0;
	tree[i].mul=1;
	tree[i].sum=(tree[i*2].sum+tree[i*2+1].sum);
	int mid=(l+r)>>1;
	build(i*2,mid,r);
	build(i*2+1,l,mid+1);
	return ;
}
void push_down(int i){
	if(tree[i].mul==1&&tree[i].lz==0) return ;
	int lc=i*2;
	int rc=i*2+1;
	tree[lc].sum=(tree[lc].sum*tree[i].mul+tree[i].lz*(tree[lc].r-tree[lc].l+1));
	tree[lc].lz=(tree[lc].lz*tree[i].mul+tree[i].lz);
	tree[lc].mul=(tree[lc].mul*tree[i].mul);
	tree[rc].sum=(tree[rc].sum*tree[i].mul+tree[i].lz*(tree[rc].r-tree[rc].l+1));
	tree[rc].lz=(tree[rc].lz*tree[i].mul+tree[i].lz);
	tree[rc].mul=(tree[rc].mul*tree[i].mul);
	tree[i].mul=1;
	tree[i].lz=0;
}
int search(int i,int l,int r){
	if(tree[i].l>=l&&tree[i].r<=r){
		return tree[i].sum;
	}
	if(tree[i].l>r||tree[i].r<l){
		return 0;
	}
	int s=0;
	push_down(i);
	if(tree[i*2].r>=l){
		s=(s+search(i*2,l,r));
	}
	if(tree[i*2+1].l<=r){
		s=(s+search(i*2+1,l,r));
	}
	return s;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}
	for(int i=1;i<=t;i++){
		cout<<search(1,i,t)<<"\n";
	}
	return 0;
}