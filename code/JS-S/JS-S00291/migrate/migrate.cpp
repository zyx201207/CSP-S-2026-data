// x x xxx

#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5000+5;
const int tN = 10*N;

struct SegTree{
	ll mi[tN];

	void build(int p,int l,int r){
		mi[p]=0x3f3f3f3f3f3f3f3f;
		if(l==r)
			return;
		int mid=(l+r)>>1;
		build(p*2,l,mid);
		build(p*2+1,mid+1,r);
	}

	void upd(int k,ll to,int p,int l,int r){
		if(l==r){
			mi[p]=to;
			return;
		}
		int mid=(l+r)>>1;
		if(k<=mid)
			upd(k,to,p*2,l,mid);
		else
			upd(k,to,p*2+1,mid+1,r);
		mi[p]=min(mi[p*2],mi[p*2+1]);
	}

	ll query(int L,int R,int p,int l,int r){
		if(L<=l&&r<=R)
			return mi[p];
		int mid=(l+r)>>1;
		ll res=0x3f3f3f3f3f3f3f3f;
		if(L<=mid)
			res=min(res,query(L,R,p*2,l,mid));
		if(R>mid)
			res=min(res,query(L,R,p*2+1,mid+1,r));
		return res;
	}

	int bin(ll v,int p,int l,int r){
		if(mi[p]>v)
			return -1;
		if(l==r)
			return l;
		int mid=(l+r)>>1;
		int tmp=bin(v,p*2+1,mid+1,r);
		if(tmp!=-1)
			return tmp;
		return bin(v,p*2,l,mid);
	}
};

struct BIT{
	ll c[N];
	void upd(int k,int x){
		for(;k<N;k+=(k&-k))
			c[k]+=x;
	}
	ll query(int k){
		ll res=0;
		for(;k;k-=(k&-k))
			res+=c[k];
		return res;
	}
};

int n;
ll x[N],d;
SegTree tree;
BIT bit;

void _main(int __ID__){
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++)
		scanf("%lld",&x[i]);
	int cnt=0;
	for(int i=1;i<=n;i++){
		tree.build(1,i,n);
		tree.upd(i,0,1,i,n);
		for(int j=i+1;j<=n;j++){
			int L=upper_bound(x+i,x+n+1,x[j]-d-1)-x;
			ll dis=tree.query(L,j-1,1,i,n)+1;
			tree.upd(j,dis,1,i,n);
		}
		for(int j=1;j<=n;j++)
			bit.c[j]=0;
		bit.upd(i,+1);
		for(int j=i+1;j<=n;j++){
			ll dis=tree.query(j,j,1,i,n);
			int R=tree.bin(dis-1,1,i,n);
			int L=tree.bin(dis-2,1,i,n)+1;
			if(dis==1)
				L=i;
			int L2=upper_bound(x+i,x+n+1,x[j]-d-1)-x;
			L=max(L,L2);
			// L<=R
			bit.upd(j,bit.query(R)-bit.query(L-1));
		}
		for(int j=i;j<=n;j++){
		// 	printf("%lld ",bit.query(j)-bit.query(j-1));
			if(bit.query(j)-bit.query(j-1)==2)
				++cnt;
		}
		// printf("\n");
	}
	printf("%d\n",cnt);
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)
		_main(c);
	return 0;
}