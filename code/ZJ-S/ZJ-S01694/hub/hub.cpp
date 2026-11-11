#include<bits/stdc++.h>
#define PII pair<int,int>
#define int long long
#define LL long long
using namespace std;
const int inf=0x3f3f3f3f,INF=0x3f3f3f3f3f3f3f3f;
const int tianyiblue=0x66ccff;
int cid,t,n,k,m,fa[1000005],mxdep[1000005],dep[1000005],sum[1000005],mxdis,mxpos;
vector<int>g[1000005],f[1000005],path,vec;
bool b[1000005];
void dfs(int x,int fat,int dis=0){
	fa[x]=fat;
	if(dis>mxdis)mxdis=dis,mxpos=x;
	for(int y:g[x]){
		if(y==fat)continue;
		dfs(y,x,dis+1);
	}
}
void dfs1(int x,int fat){
	dep[x]=dep[fat]+1,mxdep[x]=dep[x],vec.push_back(x);
	for(int y:g[x]){
		if(b[y]||y==fat)continue;
		dfs1(y,x),mxdep[x]=max(mxdep[x],mxdep[y]);
	}
}
bool cmp(int x,int y){return mxdep[x]-dep[x]>mxdep[y]-dep[y];}
struct Seg{
	struct Node{
		int l,r,mx,ad;
	}t[4000005];
	inline void build(int l,int r,int p){
		t[p].l=l,t[p].r=r,t[p].mx=-inf,t[p].ad=0;
		if(t[p].l==t[p].r)return;
		int m=(t[p].l+t[p].r)>>1;
		build(l,m,p<<1),build(m+1,r,p<<1|1);
		t[p].mx=max(t[p<<1].mx,t[p<<1|1].mx);
	}
	inline void pushdn(int p){
		if(t[p].l==t[p].r)return;
		t[p<<1].mx+=t[p].ad,t[p<<1|1].mx+=t[p].ad;
		t[p<<1].ad+=t[p].ad,t[p<<1|1].ad+=t[p].ad;
		t[p].ad=0;
	}
	inline void update1(int l,int r,int c,int p){
		pushdn(p);
		if(l<=t[p].l&&t[p].r<=r){
			t[p].mx+=c,t[p].ad+=c;
			return;
		}int m=(t[p].l+t[p].r)>>1;
		if(l<=m)update1(l,r,c,p<<1);
		if(m<r)update1(l,r,c,p<<1|1);
		t[p].mx=max(t[p<<1].mx,t[p<<1|1].mx);
	}
	inline void update2(int x,int c,int p){
		pushdn(p);
		if(t[p].l==t[p].r){
			t[p].mx=c;
			return;
		}int m=(t[p].l+t[p].r)>>1;
		if(x<=m)update2(x,c,p<<1);
		else update2(x,c,p<<1|1);
		t[p].mx=max(t[p<<1].mx,t[p<<1|1].mx);
	}
	inline int query(int l,int r,int p){
		pushdn(p);
		if(l<=t[p].l&&t[p].r<=r)return t[p].mx;
		int m=(t[p].l+t[p].r)>>1,res=-inf;
		if(l<=m)res=max(res,query(l,r,p<<1));
		if(m<r)res=max(res,query(l,r,p<<1|1));
		return res;
	}
}tr;
inline bool check(int len){
	for(int i=1;i<=m;++i){
		if(mxdep[path[i]]<=len)sum[i]=1;
		else sum[i]=max(1ll,f[i][len]);
		sum[i]+=sum[i-1];
	}
	if(len+1>m-len)return 1;
	if(sum[m-len]-sum[len]<=k)return 1;
	tr.build(1,n,1);
	for(int l=len+1,r=l+1;l<=m-len;++l){
		while(r<=m-len){
			int mid=(l+r+1)>>1;
			tr.update2(r,mxdep[path[r]],1),tr.update1(mid,r,1,1),++r;
			if(tr.query(l+1,r-1,1)>len){
				--r,tr.update2(r,-inf,1),tr.update1(mid,r,-1,1);
				break;
			}
		}
		if(sum[l]-sum[len]+sum[m-len]-sum[r-1]<=k)return 1;
		if(r==l+1)++r;
		else{
			int mid=(l+r)>>1;
			tr.update2(l+1,-inf,1),tr.update1(l+1,mid,-1,1);
		}
	}return 0;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>cid>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;++i){
			int u,v;cin>>u>>v;
			g[u].push_back(v),g[v].push_back(u);
		}int spos=0,tpos=0;
		mxdis=0,mxpos=1,dfs(1,0);
		spos=mxpos;
		mxdis=0,mxpos=1,dfs(spos,0);
		tpos=mxpos;
		int tmp=tpos;
		while(tmp!=spos)path.push_back(tmp),tmp=fa[tmp];
		path.push_back(tmp),path.push_back(0),reverse(path.begin(),path.end());
		m=path.size()-1;
		for(int i=1;i<=m;++i)b[path[i]]=1;
		for(int i=1;i<=m;++i){
			vec.clear(),dep[0]=-1,dfs1(path[i],0);
			sort(vec.begin(),vec.end(),cmp),f[i].clear();
			for(int j=0;j<=mxdep[path[i]];++j)f[i].push_back(0);
			for(int j=mxdep[path[i]]-1,k=0;j>=0;--j){
				f[i][j]=f[i][j+1];
				while(k<(int)vec.size()&&mxdep[vec[k]]-dep[vec[k]]>=j)++f[i][j],++k;
			}
		}
		int l=0,r=(m-1)/2,res=-1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid))r=mid-1,res=mid;
			else l=mid+1;
		}cout<<res<<'\n';
		for(int i=1;i<=n;++i)b[i]=0,g[i].clear();
		path.clear();
	}
	return 0;
}
/*
让我过吧，求求了，我真的很想去 WC，只要我不挂分，这题不卡我双 log，那我就是 100+100+40+100=340 了
我真的，为什么偏偏遇到了这种情况……本来我可以过掉 T3 的，为什么……
现在已经没机会了，也没必要后悔了
有一句话留给  wrong_accept：
说好从今以后都牵着手，因为要走很远
谢谢你，也谢谢天依，陪我度过了这辈子最后一次 CSP 
*/
