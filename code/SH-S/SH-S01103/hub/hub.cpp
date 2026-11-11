#include<bits/stdc++.h>
using namespace std;
const int N=2e6+9;
int cid,T;
int n,k;
int tot,h[N],to[N],ne[N];
void add(int u,int v){
	tot++;to[tot]=v;ne[tot]=h[u];h[u]=tot;
}
int d[N],rt,mid;
void dfs(int u,int fa){
	d[u]=0;
	for(int i=h[u];i;i=ne[i]){
		int v=to[i];
		if(v==fa) continue;
		dfs(v,u);
		d[u]=max(d[u],d[v]+1);
	}
	if(d[u]==mid) rt=u;
}
int nr,fth[N];
int dfs2(int u,int fa){
	fth[u]=fa;
	d[u]=0;
	int num=0;
	for(int i=h[u];i;i=ne[i]){
		int v=to[i];
		if(v==fa) continue;
		num+=dfs2(v,u);
		d[u]=max(d[u],d[v]+1);
	}
	if(d[u]>=mid) num++;
	if(d[u]==mid) nr=u;
	return num;
}
int ql[N],cnt,val[N],d2[N],maxd;
int dfs3(int u,int fa,int ban,bool fg){
	d2[u]=0;
	int num=0;
	for(int i=h[u];i;i=ne[i]){
		int v=to[i];
		if(v==fa||v==ban) continue;
		num+=dfs3(v,u,ban,1);
		d2[u]=max(d2[u],d2[v]+1);
	}
	if(fg&&d2[u]>=mid) num++;
	maxd=max(maxd,d2[u]);
	return num;
}
int check(){
	rt=0;
	dfs(1,0);
	if(!rt) return 1;
	int all=1,minn=0;//cout<<rt<<'\n';
	for(int i=h[rt];i;i=ne[i]){
		int v=to[i];
		nr=0;
		int vl=dfs2(v,rt);
		all+=vl;//cout<<vl<<' '<<nr<<'\n';
		if(!nr) continue;
		int x=nr;
		int nv=1,ty=0;
		cnt=0;
		while(fth[x]!=rt){
			ty++;
			maxd=0;
			nv+=dfs3(fth[x],fth[fth[x]],x,0);
			maxd=min(maxd,mid);//cout<<maxd<<'\n';
			int ls=max(ty-(mid-maxd),0);
			nv+=ls;ty-=ls;//cout<<nv<<'\n';
			ql[++cnt]=fth[x];
			val[cnt]=nv;
			x=fth[x];
		}
		ql[0]=nr;ql[cnt+1]=rt;
		val[0]=1;
		minn=min(minn,val[cnt]-vl);
		nv=0;ty=0;
		for(int i=cnt;i>=1;i--){
			ty++;
			maxd=0;
			nv+=dfs3(ql[i],ql[i+1],ql[i-1],0);
			maxd=min(maxd,mid);//cout<<maxd<<'\n';
			int ls=max(ty-(mid-maxd),0);
			nv+=ls;ty-=ls;//cout<<nv<<'\n';
			minn=min(minn,nv+val[i-1]-vl);
		}
	}//cout<<all<<' '<<minn<<'\n';
	return all+minn;
}
void solve(){
	cin>>n>>k;
	tot=0;
	for(int i=1;i<=n;i++) h[i]=0;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
//	mid=6;
//	cout<<check()<<'\n';return;
	int l=1,r=n;
	while(l<r){
		mid=(l+r)/2;
		if(check()<=k) r=mid;
		else l=mid+1;//cout<<l<<' '<<r<<' '<<mid<<'\n';
	}
	//mid=6;
	//cout<<n<<' '<<k<<' '<<check()<<'\n';
	cout<<l<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>cid>>T;
	while(T--) solve();
	return 0;
} 
/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
