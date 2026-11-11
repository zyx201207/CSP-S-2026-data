#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5050;
struct Data{
	int f;
	ll g;
	Data operator + (const Data &o) const{
		if(f==o.f)return {f,g+o.g};
		return (f<o.f)?*this:o;
	}
	Data (){
		f=1e9,g=0;
	}
	Data (int F,ll G){
		f=F,g=G;
	}
};
int pre[N];
ll x[N],d;
int n;
struct SegmentTree{
	Data sum[N<<2];
	void pushup(int u){
		sum[u]=sum[u<<1]+sum[u<<1|1];
	}
	void build(int u,int l,int r){
		if(l==r){
			sum[u]=Data();
			return ;
		}
		int mid=(l+r)>>1;
		build(u<<1,l,mid);
		build(u<<1|1,mid+1,r);
		pushup(u);
	}
	Data query(int u,int l,int r,int ql,int qr){
		if(ql<=l && r<=qr)return sum[u];
		int mid=(l+r)>>1;
		Data res;
		if(ql<=mid)res=res+query(u<<1,l,mid,ql,qr);
		if(qr>mid)res=res+query(u<<1|1,mid+1,r,ql,qr);
		return res;
	}
	void update(int u,int l,int r,int pos,Data f){
		if(l==r){
			sum[u]=f;
			return ;
		}
		int mid=(l+r)>>1;
		if(pos<=mid)update(u<<1,l,mid,pos,f);
		else update(u<<1|1,mid+1,r,pos,f);
		pushup(u);
	}
	Data qry(int l,int r){
		if(l>r)return Data();
		return query(1,1,n,l,r);
	}
	void upd(int pos,Data c){
		update(1,1,n,pos,c);
	}
}seg;
void solve(){
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;++i)scanf("%lld",&x[i]);
	pre[1]=1;
	for(int i=2;i<=n;++i){
		pre[i]=pre[i-1];
		while(x[i]-x[pre[i]]>d)++pre[i];
	}
	int ans=0;
	for(int u=1;u<=n;++u){
		seg.build(1,1,n);
		seg.upd(u,{1,1});
		for(int v=u+1;v<=n;++v){
			Data s=seg.qry(pre[v],v-1);
			++s.f;
			if(s.g==2)++ans;
			seg.upd(v,s);
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	scanf("%d%d",&c,&T);
	while(T--)solve();
	return 0;
}

