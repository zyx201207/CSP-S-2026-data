#include<bits/stdc++.h>
#define int __int128
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int b[N];
inline int read( ){
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
#define rd read()
inline void write(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>10)write(x/10);
	putchar(x%10+'0');
}
int tree[N<<2],lazy[N<<2];
#define ls p<<1
#define rs p<<1|1
#define mid (l+((r-l)>>1))
const int INF=1e18+5;
/*inline void build(int l,int r,int p){
	tree[p]=INF;
	if(l==r)return;
	build(l,mid,ls);build(mid+1,r,rs);
}*/
inline void down(int l,int r,int p){
	if(!lazy[p])return;
	int &_=lazy[p];
	tree[ls]+=_*(mid-l+1);tree[rs]+=_*(r-mid);
	lazy[ls]+=_;lazy[rs]+=_;
	_=0;
}
inline void update(int l,int r,int p,int L,int R,int val){
	if(L<=l&&r<=R){
		tree[p]+=val*(r-l+1);lazy[p]+=val;return;
	}
	down(l,r,p);
	if(mid>=L)update(l,mid,ls,L,R,val);
	if(mid<R)update(mid+1,r,rs,L,R,val);
	tree[p]=tree[ls]+tree[rs];
}
inline int query(int l,int r,int p,int m){
	if(l==r)return (tree[p]<=m);
	down(l,r,p);
	if(tree[rs]>m)return query(mid+1,r,rs,m);
	else return (r-mid)+query(l,mid,ls,m-tree[rs]);
}
inline int miku(int x,int y){
	if(x>=y)return x;
	else return y;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=rd;m=rd;
	for(int i=1;i<=n;i++)a[i]=rd;
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)b[i]=a[i+1]-a[i];
	//build(1,n,1);
	int ans=1;
	for(int i=1;i<n;i++){
	    //update(1,n,1,i,i,-INF);
	    update(1,n,1,1,i,b[i]);
	    ans=miku(ans,query(1,n,1,m)-(n-i-1));
	    //write(i);putchar(' ');write(query(1,n,1,m)-(n-i-1));putchar(' ');write(ans);putchar('\n');
	}
	write(ans);putchar('\n');
	return 0;
}
/*

*/