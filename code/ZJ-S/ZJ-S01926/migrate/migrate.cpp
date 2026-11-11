#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2e6+5;
const int maxm=5e3+5;
const int inf=0x3f3f3f3f;
ll read(){
	ll x=0;int w=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return w?-x:x;
}
int Typ,_;
int n;
ll d;
ll a[maxn];
int t[maxn];
struct Data{
	int mn,cnt;
	Data(){}
	Data(int Mn,int Cnt){mn=Mn,cnt=Cnt;}
};
Data merge(Data x,Data y){
	Data z=Data(inf,0);
	z.mn=min(x.mn,y.mn);
	if(z.mn==x.mn) z.cnt+=x.cnt;
	if(z.mn==y.mn) z.cnt+=y.cnt;
	z.cnt=min(z.cnt,3);
	return z;
}
struct Segment_Tree{
#define ls (o<<1)
#define rs (o<<1|1)
	Data tr[maxm<<2];
	void build(int o,int l,int r){
		tr[o]=Data(inf,0);
		if(l==r) return;
		int mid=(l+r)>>1;
		build(ls,l,mid),build(rs,mid+1,r);
	}
	void modify(int o,int l,int r,int x,Data k){
		if(l==r) return tr[o]=k,void();
		int mid=(l+r)>>1;
		if(x<=mid) modify(ls,l,mid,x,k);
		else modify(rs,mid+1,r,x,k);
		tr[o]=merge(tr[ls],tr[rs]);
	}
	Data query(int o,int l,int r,int x,int y){
		if(x>y) return Data(inf,0);
		if(x<=l&&r<=y) return tr[o];
		int mid=(l+r)>>1;
		if(x<=mid&&y>mid) return merge(query(ls,l,mid,x,y),query(rs,mid+1,r,x,y));
		if(x<=mid) return query(ls,l,mid,x,y);
		return query(rs,mid+1,r,x,y);
	}
#undef ls
#undef rs
}sgt[maxm];
void clear(){}
void mymain(){
	clear();
	n=read(),d=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++){
		t[i]=t[i-1];
		while(t[i]<n&&a[t[i]+1]<=a[i]+d) t[i]++;
	}
	if(Typ==11||Typ==12){
		if(t[1]<=2) return cout<<0<<'\n',void();
		return cout<<max(0,n-2*(t[1]-1)+1)<<'\n',void();
	}
	ll ans=0;
	for(int i=n;i>=1;i--){
		sgt[i].build(1,1,i);
		sgt[i].modify(1,1,i,i,Data(0,1));
		for(int j=i+1;j<=n;j++){
			Data tmp=sgt[j].query(1,1,j,i+1,t[i]);
			if(tmp.mn<inf) tmp.mn++;
			sgt[j].modify(1,1,j,i,tmp);
			if(tmp.cnt==2) ans++;
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0),cout.tie(0);
	Typ=read(),_=read();
	while(_--) mymain();
	return 0;
}