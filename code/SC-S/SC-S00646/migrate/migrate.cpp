#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
int T,C;
int n;ll d,ans;
ll a[N];
bool ck(int u,int v){
	return a[v]-a[u]<=d;
}
bool vis[N];
int st,cnt;
void check(int s,int e){
	int p=s,res=0;
	vis[e]=1;
	for(int i=s;i<=e;i++){
		if(vis[i]){
			if(!ck(p,i)) return ;
			p=i;res++;
		}
	}
	
	if(st>res){
//		for(int i=1;i<=n;i++) cout<<vis[i]<<' ';
//		cout<<'\n';cout<<st<<'\n';
		st=res;cnt=1;
	}
	
	else if(st==res){
		cnt++;
//		for(int i=1;i<=n;i++) cout<<vis[i]<<' ';
//		cout<<'\n';cout<<'\n';
	} 
	vis[e]=0;
}
void dfs(int u,int s,int e){
	if(u>=e){
		check(s,e);
		return ;
	}
	vis[u]=1;dfs(u+1,s,e);
	vis[u]=0;dfs(u+1,s,e);
}
void solve1(){
	for(int i=1;i<=n;i++){
		for(int j=i+3;j<=n;j++){
			st=n,cnt=0;dfs(i+1,i,j);
			
			if(cnt==2) ans++;
		}
	}
//	cout<<st<<' '<<cnt<<'\n';
	cout<<ans<<'\n';
}
void solve(){
	cin>>n>>d;ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=9){
		solve1();return ;
	}
	int k=a[2]-a[1];bool ok=1;
	for(int i=2;i<n;i++){
		if(k!=a[i+1]-a[i]){
			ok=0;break;
		}
	}
	if(a[2]-a[1]>=d||a[n]-a[1]<=d){
		cout<<0<<'\n';return ;
	}
	int r=d/(a[2]-a[1]);
	cout<<n-r*2+1;cout<<'\n';
}
/*
#define ls u<<1
#define rs u<<1|1
int t[N*4];
void pushup(int u){
	t[u]=t[ls]+t[rs];
}
void build(int u,int l,int r){
	if(l==r){
		t[u]=a[l];
		return ;
	} 
	int mid=l+r>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	pushup(u);
}
void modify(int u,int pos,int v,int l,int r){
	if(l==r){
		t[u]+=v;
		return ;
	}
	int mid=l+r>>1;
	if(pos<=mid) modify(ls,pos,v,l,mid);
	else modify(rs,pos,v,mid+1,r);
	pushup(u);
}
int query(int u,int L,int R,int l,int r){
	if(L<=l&&R<=r){
		return t[u];
	}
	int mid=l+r>>1,res=0;
	if(L<=mid) res+=query(ls,L,R,l,mid);
	if(R>mid) res+=query(rs,L,R,mid+1,r);
	return res;
}
I love SGT.
*/
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while(T--) solve();
	return 0;
}