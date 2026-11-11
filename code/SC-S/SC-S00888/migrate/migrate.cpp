#include<bits/stdc++.h>
#define sjh0626s return
#define code 0
#define ll long long
//#define int ll
#define PII pair<int,int>
#define all(v) v.begin(),v.end()
using namespace std;
const int N=2e6+10;
const ll inf=1e18;
int T=1,c,t,n;
ll d;
ll x[N],l[N];
vector<int>g[N];
ll dis[N],cnt[N];
int vis[N];
queue<int>q;
namespace segment{
#define lson (x<<1)
#define rson (x<<1|1)
#define mid ((tr[x].l+tr[x].r)/2)
	struct node{
		int l,r;
		ll dis,cnt;
	}tr[N<<2];
	void pushup(int x){
		tr[x].dis=min(tr[lson].dis,tr[rson].dis);tr[x].cnt=0;
		if(tr[lson].dis==tr[x].dis)tr[x].cnt+=tr[lson].cnt;
		if(tr[rson].dis==tr[x].dis)tr[x].cnt+=tr[rson].cnt;
	}
	node merge(node a,node b){
		node rt;
		rt.dis=min(a.dis,b.dis);rt.cnt=0;
		if(a.dis==rt.dis)rt.cnt+=a.cnt;
		if(b.dis==rt.dis)rt.cnt+=b.cnt;
		return rt;
	}
	void build(int x,int l,int r,int P){
		tr[x].l=l,tr[x].r=r;
		tr[x].dis=inf,tr[x].cnt=0;
		if(l==r)return;
		build(lson,l,mid,P);
		build(rson,mid+1,r,P);
		pushup(x);
	}
	void modify(int x,int p,int v,int cn){
		if(tr[x].l==tr[x].r){tr[x].dis=v,tr[x].cnt=cn;return;}
		if(p<=mid)modify(lson,p,v,cn);
		else modify(rson,p,v,cn);
		pushup(x);
	}
	node query(int x,int l,int r){
		if(l<=tr[x].l&&tr[x].r<=r)return tr[x];
		if(l>mid)return query(rson,l,r);
		else if(r<=mid)return query(lson,l,r);
		else return merge(query(lson,l,r),query(rson,l,r));
	}
}
using namespace segment;
void bfs(int s){
	build(1,1,n,s);
	modify(1,s,0,1);
	for(int i=s+1;i<=n;i++){
		auto res=query(1,l[i],i);cnt[i]=res.cnt;dis[i]=res.dis+1;
		if(i!=s)modify(1,i,res.dis+1,res.cnt);
	}
}
int ans=0;
void solve(){
	cin>>n>>d;
	ans=0;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<=n;i++){
		cin>>x[i];
		l[i]=i;
		for(int j=i-1;j>=1;j--){
			if(x[i]-x[j]<=d){
//				g[j].emplace_back(i);
				l[i]=j;
			}
			else break;
		}
	}
//	for(int i=1;i<=n;i++){
//		int L=i+1,R=n,v=0;
//		while(L<=R){
//			int mid=(L+R)/2;
//			if(x[mid]-x[i]<=d)R=mid-1,v=mid;
//			else L=mid+1;
//		}
//		if(x[v]-x[i]<=d)g[i].emplace_back(v);
//	}
	for(int i=1;i<=n;i++){
		bfs(i);
		for(int j=i+1;j<=n;j++){
			if(cnt[j]==2){
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)solve();
	sjh0626s code;
}
/*
会赢吗？会赢的！
1:17 24pts start
*/