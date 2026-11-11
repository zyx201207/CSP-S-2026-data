#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2000009;
const ll INF=3e18+1009;
int n;ll D;
ll x[N];
int fa[N],lb[N],d[N];
vector<int> to[N]; 
int col[N],cnt0[N],cnt1[N];
int f0[N],f1[N],f2[N];
ll sum0[N],sum1[N];

struct Q{int u,type,k,id;}q[4*N];
int cntq=0;
vector<int> vec[N];
ll ans[N];

void clear(){
	for(int i=1;i<=n+1;i++){
		x[i]=fa[i]=lb[i]=d[i]=0;
		to[i].clear();
		col[i]=cnt0[i]=cnt1[i]=0;
		f0[i]=f1[i]=f2[i]=0;
		sum0[i]=sum1[i]=0;
		vec[i].clear();
		ans[i]=0;
	}
	for(int i=1;i<=cntq;i++)q[i]=(Q){0,0,0,0};
	cntq=0;
}

void dfs1(int u){
	int p=fa[u],q=lb[p],r=lb[q];
	if(d[p]-d[q]==d[q]-d[r])lb[u]=r;
	else lb[u]=p;
	for(int v:to[u]){
		if(v==fa[u])continue;
		d[v]=d[u]+1;
		f0[v]=f0[u]+(col[v]==0);
		f1[v]=f1[u]+(col[v]==1);
		f2[v]=f2[u]+(col[v]==2);
		dfs1(v);
	}
}
void dfs2(int u){
//	cout<<"%% "<<u<<" "<<sum0[u]<<" "<<sum1[u]<<endl;
	for(int i:vec[u]){
		ans[q[i].id]+=(ll)q[i].k * (q[i].type ? sum1[u]:sum0[u]);
//		cout<<"$$ "<<u<<" "<<q[i].type<<" "<<q[i].k<<" "<<q[i].id<<" "<<ans[q[i].id]<<endl;
	}
	for(int v:to[u]){
		if(v==fa[u])continue;
		sum0[v]=sum0[u]+cnt0[v];
		sum1[v]=sum1[u]+cnt1[v];
		dfs2(v);
	}
}
void work(int u){
	int v1=u;
	while(f1[ v1 ]>=f1[u]){
		if(f1[ lb[v1] ]>=f1[u])v1=lb[v1];
		else v1=fa[v1];
	}
	int v2=u;
	while(f1[ v2 ]>=f1[u]-1){
		if(f1[  lb[v2] ]>=f1[u]-1)v2=lb[v2];
		else v2=fa[v2];
	}
	int v_=u;
	while(f2[ v_ ]>=f2[u]){
		if(f2[ lb[v_] ]>=f2[u])v_=lb[v_];
		else v_=fa[v_];
	}
//	cout<<"## "<<u<<" "<<v1<<" "<<v2<<" "<<v_<<endl;
	if(v_>=v1){
		q[++cntq]=(Q){min(v2,v_),0,-1,u};
		q[++cntq]=(Q){v1,0,1,u};
		q[++cntq]=(Q){v1,1,-1,u};
		q[++cntq]=(Q){u,1,1,u};
	}
	else{
		q[++cntq]=(Q){v_,1,-1,u};
		q[++cntq]=(Q){u,1,1,u};
	}
}
void init(){
	for(int i=1;i<=n;i++){
		if(fa[i]==n+1 || fa[fa[i]]==n+1)continue;
		if(fa[i]-1>i && x[fa[i]-1]>=x[fa[fa[i]]]-D){
			if(fa[i]-2>i && x[fa[i]-2]>=x[fa[fa[i]]]-D){
				col[i]=2;
			}
			else col[i]=1;
		}
		else col[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(fa[i]==n+1)continue;
		if(fa[fa[i]]==n+1){
			cnt0[i]=1;
			continue;
		}
		cnt0[i]=1;
		if(fa[i]-1>i){
			int l1=fa[i]+1,r1=fa[fa[i]],res1=fa[fa[i]];
			while(l1<=r1){
				int mid=l1+(r1-l1)/2;
				if(x[mid]>x[fa[i]-1]+D)res1=mid,r1=mid-1;
				else l1=mid+1;
			}
			int l2=fa[i]+1,r2=res1,res2=res1;
			while(l2<=r2){
				int mid=l2+(r2-l2)/2;
				if(x[mid]>x[fa[i]-2]+D)res2=mid,r2=mid-1;
				else l2=mid+1;
			}
			cnt0[i]+=fa[fa[i]]-res1;
			cnt1[i]+=res1-res2;
		}
	}
}	

void solve(){
	x[0]=-INF,x[n+1]=INF;
	for(int p=1,q=1;p<=n;p++){
		while(q<=n&&x[q]-x[p]<=D)q++;
		fa[p]=q-1;
		if(fa[p]==p)fa[p]=n+1;
		to[p].emplace_back(fa[p]);
		to[fa[p]].emplace_back(p);
	}
	init();
	fa[n+1]=lb[n+1]=n+1;d[n+1]=1;dfs1(n+1);
	f0[n+1]=f1[n+1]=f2[n+1]=-N;
	
//	for(int i=1;i<=n+1;i++)cout<<fa[i]<<" ";cout<<endl;
//	for(int i=1;i<=n+1;i++)cout<<col[i]<<" ";cout<<endl;
//	for(int i=1;i<=n+1;i++)cout<<f0[i]<<" ";cout<<endl;
//	for(int i=1;i<=n+1;i++)cout<<f1[i]<<" ";cout<<endl;
//	for(int i=1;i<=n+1;i++)cout<<f2[i]<<" ";cout<<endl;
//	for(int i=1;i<=n+1;i++)cout<<cnt0[i]<<" ";cout<<endl;
//	for(int i=1;i<=n+1;i++)cout<<cnt1[i]<<" ";cout<<endl;
	
	for(int i=1;i<=n;i++)work(i);
	for(int i=1;i<=cntq;i++)vec[q[i].u].emplace_back(i);
	dfs2(n+1);
	
//	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<endl;
	
	ll sum=0;
	for(int i=1;i<=n;i++)sum+=ans[i];
	cout<<sum<<endl;
	clear();
}

const int sN=5009,C=31;
int rmax[N],f[N],d_[N];
int tr[4*sN],tag[4*sN];
void chg(int s,int t,int p,ll k){
	tr[p]+=(t-s+1)*k,tag[p]+=k;
}
void pushdown(int s,int t,int p){
	int mid=s+(t-s)/2;
	chg(s,mid,p<<1,tag[p]),chg(mid+1,t,p<<1|1,tag[p]);
	tag[p]=0;
}
void build(int s,int t,int p){
	tr[p]=tag[p]=0;
	if(s==t)return;int mid=s+(t-s)/2;
	build(s,mid,p<<1),build(mid+1,t,p<<1|1);
}
void add(int l,int r,int s,int t,int p,int k){
	if(l<=s&&t<=r){chg(s,t,p,k);return;}
	int mid=s+(t-s)/2;if(tag[p])pushdown(s,t,p);
	if(l<=mid)add(l,r,s,mid,p<<1,k);
	if(r>=mid+1)add(l,r,mid+1,t,p<<1|1,k);
	tr[p]=tr[p<<1]+tr[p<<1|1];
}
int req(int l,int s,int t,int p){
	if(s==t)return tr[p];
	int mid=s+(t-s)/2;if(tag[p])pushdown(s,t,p);
	if(l<=mid)return req(l,s,mid,p<<1);
	if(l>=mid+1)return req(l,mid+1,t,p<<1|1);
}

void Solve(){
	cin>>n>>D;
	for(int i=1;i<=n;i++)cin>>x[i];
	solve();
//	if(n<=5000)solvebf();
//	else solve();
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;cin>>c>>T;
	while(T--)Solve();
	return 0;
}
