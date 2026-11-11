#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
const int MAXN=2e6+10;
const int INF=1e9;
int c,T;
ll n,d,x[MAXN],dp[MAXN],cnt[MAXN],ans;
namespace SEG{
	struct Seg_Tree{ll minn,cnt;}tree[MAXN<<2];
	inline void build(int rt,int l,int r){
		tree[rt].minn=INF,tree[rt].cnt=0;
		if (l==r)return;
		int mid=(l+r)>>1;
		build(rt<<1,l,mid),build(rt<<1|1,mid+1,r);
	}
	inline void push_up(int rt){
		tree[rt].minn=min(tree[rt<<1].minn,tree[rt<<1|1].minn);
		if (tree[rt<<1].minn==tree[rt<<1|1].minn)tree[rt].cnt=tree[rt<<1].cnt+tree[rt<<1|1].cnt;
		else if (tree[rt<<1].minn<tree[rt<<1|1].minn)tree[rt].cnt=tree[rt<<1].cnt;
		else tree[rt].cnt=tree[rt<<1|1].cnt;
	}
	inline void update(int rt,int l,int r,int pos,int x,int cnt){
		if (l==r)return tree[rt].minn=x,tree[rt].cnt=cnt,void();
		int mid=(l+r)>>1;
		if (pos<=mid)update(rt<<1,l,mid,pos,x,cnt);
		else update(rt<<1|1,mid+1,r,pos,x,cnt);
		push_up(rt);
	}
	inline void apply(pii &x,pii y){
		if (x.F>y.F)x.F=y.F,x.S=y.S;
		else if (x.F==y.F)x.S+=y.S;
	}
	inline pii query(int rt,int l,int r,int L,int R){
		if (L<=l&&r<=R)return {tree[rt].minn,tree[rt].cnt};
		int mid=(l+r)>>1;pii res={INF,0};
		if (L<=mid)apply(res,query(rt<<1,l,mid,L,R));
		if (R>mid)apply(res,query(rt<<1|1,mid+1,r,L,R));
		return res;
	}
}
namespace yixing{
	inline void Main(){
		ans=0;
		cin>>n>>d;
		for (int i=1;i<=n;i++)cin>>x[i];
		for (int u=1;u<=n;u++){
			dp[u]=0,cnt[u]=1;
			SEG::build(1,u,n);
			SEG::update(1,u,n,u,0,1);
			for (int v=u+1;v<=n;v++){
//				for (int w=v-1;w>=u;w--){
//					if (x[v]-x[w]>d)break;
//					if (dp[v]>dp[w]+1){
//						dp[v]=dp[w]+1;
//						cnt[v]=0;
//					}
//					if (dp[v]==dp[w]+1)cnt[v]+=cnt[w];
//				}
				int pos=lower_bound(x+1,x+1+v,x[v]-d)-x;
		//		if (x[pos]>x[v]-d)
		//		cout<<u<<" "<<v<<" "<<pos<<"\n";
				pii res=SEG::query(1,u,n,pos,v-1);
		//		cout<<u<<" "<<v<<" "<<res.F+1<<"\n";
				if (res.S==2)ans++;
				SEG::update(1,u,n,v,res.F+1,res.S);
		//		if (cnt[v]==2)ans++;
			//	cout<<u<<" "<<v<<" "<<dp[v]<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while (T--)yixing::Main();
	return 0;
}