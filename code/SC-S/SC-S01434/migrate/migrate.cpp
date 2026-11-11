#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+6,mod=998244353,INF=1e18;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define rep(i,l,r)	for(int i=(l);i<=(r);i++)
#define atrep(i,l,r)	for(int i=(r);i>=(l);i--)
int pos[N];
struct node{
	int l,r;
	int val;
	ull cnt;
}t[N<<2];
#define ls(u)	(u<<1)
#define rs(u)	(u<<1|1)
void push(node &u,node x,node y){
	if(x.val==y.val){
		u.val=x.val;
		u.cnt=x.cnt+y.cnt;
	}else if(x.val<y.val){
		u.val=x.val;
		u.cnt=x.cnt;
	}else if(x.val>y.val){
		u.val=y.val;
		u.cnt=y.cnt;
	}
}
void pushup(int u){
	push(t[u],t[ls((u))],t[rs(u)]);
}
void build(int u,int l,int r){
	t[u].l=l,t[u].r=r;
	t[u].cnt=0,t[u].val=0;
	if(l==r){
		return ;
	}
	int mid=(l+r)>>1;
	build(ls(u),l,mid);build(rs(u),mid+1,r);
	pushup(u);
}
node query(int u,int l,int r){
	if(l>r){
		return {114514,114514,INF,0};
	}
	if(t[u].l>=l&&t[u].r<=r)	return t[u];
	int mid=(t[u].l+t[u].r)>>1;
	if(r<=mid)	return query(ls(u),l,r);
	else if(l>mid)	return query(rs(u),l,r);
	else{
		node L=query(ls(u),l,r),R=query(rs(u),l,r);
		node ans;push(ans,L,R);
		return ans;
	}
}
void modify(int u,int k,node p){
	if(t[u].l==t[u].r){
		t[u].val=p.val;
		t[u].cnt=p.cnt;
		return ;
	}
	int mid=(t[u].l+t[u].r)>>1;
	if(k<=mid)	modify(ls(u),k,p);
	else	modify(rs(u),k,p);
	pushup(u);
}
void solve(){
	int n,D;
	cin>>n>>D;
	rep(i,1,n)	cin>>pos[i];
	int res=0;
	rep(i,1,n){
		build(1,i,n);
		node p;
		p.val=0,p.cnt=1;
		modify(1,i,p);
		rep(j,i+1,n){
			int pre=lower_bound(pos+i,pos+j+1,pos[j]-D)-pos;
			node now=query(1,pre,j-1);
			now.val++;
			modify(1,j,now);
			if(now.cnt==2){
				res++;
			}
		}
	}
	cout<<res<<'\n';
}
namespace subA{
	int pos[N];
	void solve(){
		int n,D;
		cin>>n>>D;
		rep(i,1,n){
			cin>>pos[i];
		}
		if(n==1){
			cerr<<"gunmu"<<endl;
			cout<<0<<endl;
			return;
		}
		int c=pos[2]-pos[1];
		D=D/c;
		cerr<<n<<" "<<D<<" "<<c<<endl;
		if(D==0){
			cout<<0<<endl;
		}else if(D==1){
			cout<<0<<endl;
		}else{
			cout<<max(0ll,n-1-D)<<endl;
		}
	}
}
main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	int c,T;
	cin>>c>>T;
	rep(i,1,T){
		if(c>=11&&c<=12)	
			subA::solve();
		else solve();
	}
}