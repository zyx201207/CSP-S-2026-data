#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define mid (l+r>>1)
#define PII pair<int,int>
#define ll long long
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define per(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define lbt(x) ((x)&(-x))
#define pb push_back

const int N = 1e6 + 10,Lg = 21;

int n,k,mxd[N],w[N],oc[N],st1[N][Lg],st2[N][Lg],gd[N],f[N],g[N],pr[N],rt1,rt2;
vector<int>p[N],chn;
PII get(int u,int frm){
	PII ret={1,u};pr[u]=0;
	for(auto v : p[u])if(v!=frm){
		PII f=get(v,u);f.F++;
		if(f>ret) ret=f,pr[u]=v;
	}return ret;
}
void get_f(int u,int frm,int x,int f[]){
	f[u]=1;mxd[u]=1;
	for(auto v : p[u])if(v!=frm)
		get_f(v,u,x,f),f[u]+=(mxd[v]>x)*f[v],mxd[u]=max(mxd[u],mxd[v]+1);
//	cout<<u<<' '<<f[u]<<"\n";
}
int qry(int l,int r,int st[][Lg]){
	if(l>r) return -1e9;int ln=__lg(r-l+1);
	return max(st[l][ln],st[r-(1<<ln)+1][ln]);
}
bool Chk(int x){
	get_f(rt1,0,x,f);
	get_f(rt2,0,x,g);
	int ps=chn.size()-1;
	auto chk=[&](int l,int r)->bool{
		if(l>r)return 1;int md=(l+r>>1);
		return qry(l,md,st1)-(l-1)<=x&&qry(md+1,r,st2)+r+1<=x;
	};
//	cout<<x<<" "<<k<<" - \n";
//	rep(i,1,n) cout<<f[i]<<" "<<g[i]<<"\n";
	per(i,chn.size()-1,0){
		while(ps>i&&!chk(i+1,ps-1)) ps--;
//		cout<<i<<' '<<ps<<" "<<chn[i]<<" "<<g[chn[i]]<<' '<<(ps<chn.size()?f[chn[ps+1]]:0)<<"\n"; 
		if(g[chn[i]]+(ps<chn.size()?f[chn[ps+1]]:0)<=k) return 1;
	}
	return 0;
}
void solve(){
	cin>>n>>k;
	rep(i,1,n)p[i].clear();
	rep(i,1,n-1){
		int u,v;cin>>u>>v;
		p[u].pb(v);p[v].pb(u);
	}
	rt1=get(1,0).S;rt2=get(rt1,0).S;
//	cout<<rt1<<' '<<rt2<<"\n";
	chn.clear();chn.pb(rt1);
	int ps=rt1;
	while(ps!=rt2)ps=pr[ps],chn.pb(ps);
	get_f(rt1,0,0,f);
	rep(i,1,n) oc[i]=0;
//	for(auto x : chn) cout<<x<<' ';cout<<" --- \n";
	for(auto x : chn) oc[x]=1;
	for(auto x : chn){
		for(auto v : p[x])
			if(!oc[v]) w[x]=max(w[x],mxd[v]);
//		cout<<w[x]<<" ";
	}
//	cout<<"\n";
	int k=chn.size();
	rep(i,0,k-1)st1[i][0]=w[chn[i]]+i,st2[i][0]=w[chn[i]]-i;
	rep(j,1,Lg-1)rep(i,0,k-1-(1<<j)+1)st1[i][j]=max(st1[i][j-1],st1[i+(1<<j-1)][j-1]); 
	rep(j,1,Lg-1)rep(i,0,k-1-(1<<j)+1)st2[i][j]=max(st2[i][j-1],st2[i+(1<<j-1)][j-1]);
	int l=0,r=n,ret=r;
	while(l<=r){
		int md=(l+r>>1);
		if(Chk(md))ret=md,r=md-1;
		else l=md+1;
	}
	cout<<ret<<"\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,T=1;
	cin >>c>> T;
	while (T--){
		solve();
	}
	return 0;
}
/*
检查空间，UB，未初始化变量，数组下标
别急

想法:考虑二分
check的时候考虑令f_u表示u选，子树内最少选多少个点能管好，g_u是对f换根的结果
考虑枚举g下面的那个点对于
首先可以做到2log考虑优化 ，上长剖即可做到1log 
先写n^2log 
不是，还有个问题啊这两个块有可能是没有先后关系的
那咋办?换根不能长剖吧 
令h_{u,j}表示u子树内块距离小于等于j的最小代价，同时要求到子树，事实上h_{u,j}一定直接从长儿子继承过来，同时贡献一定是从次大来的 
然后可以做了，这里复杂度是1log 
冲冲冲 nonono无法冲出来 
你把直径拿出来，然后跑一个双指针是不是就行了啊 
*/
