//#include<iostream>
//#include<cstdio>
//#include<vector>
//using namespace std;
//const int N=2e5+5,M=105;
//bool ST;
//int ID,T,n,m;vector<int>gr[N];
//int f[M][M][M][3][2],g[M][M][3][2];//rt=i,d->0_mx=j,d->1_mn=k
//int len[N],mx;
//inline void set(int&x,int y){x=min(x,y);}
//void dfs(int p,int fa){
//	len[p]=1;f[p][0][0][0][0]=0;f[p][0][0][1][1]=1;
//	for(auto to:gr[p]){
//		if(to==fa)continue;
//		dfs(to,p);
//		for(int j=1;j<=len[p]+1;j++)
//			for(int k=1;k<=len[p]+1;k++)
//				for(int x=0;x<=2;x++)
//					for(int y=0;y<=1;y++)g[j][k][x][y]=m+1;
//		for(int i=1;i<=len[p];i++)
//			for(int j=1;j<=len[p];j++)
//				for(int x=0;x<=2;x++)
//					for(int y=0;y<=1;y++){
//						if(f[p][i][j][x][y]>m)continue;
//						for(int I=1;I<=len[p];I++)
//							for(int J=1;J<=len[p];J++)
//								for(int X=0;X<=2;X++)
//									for(int Y=0;Y<=1;Y++){
//										if(f[to][I][J][X][Y]>m+1)continue;
//										int ni=max(i,I+1)
//									}
//					}
//		for(int j=1;j<=len[p]+1;j++)
//			for(int k=1;k<=len[p]+1;k++)
//				for(int x=0;x<=2;x++)
//					for(int y=0;y<=1;y++)f[p][j][k][x][y]=g[j][k][x][y];
//		len[p]=max(len[p],len[to]+1);
//	}
//}
//bool check(int x){
//	mx=x;
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++)
//			for(int k=1;k<=n;k++)
//				for(int x=0;x<=2;x++)
//					for(int y=0;y<=1;y++)f[i][j][k][x][y]=m+1;
//	dfs(1,0);
//	
//}
//void solve(){
//	cin>>n>>m;
//	for(int i=1;i<=n;i++)gr[i].clear();
//	for(int i=1,u,v;i<n;i++)cin>>u>>v,gr[u].push_back(v),gr[v].push_back(u);
//	if(m==n)return cout<<0<<'\n',void();
//	int l=1,r=n,res=n;
//	while(l<=r){
//		int mid=(l+r)>>1;
//		if(check(mid))r=mid-1,res=mid;
//		else l=mid+1;
//	}
//	cout<<res<<'\n';
//}
//bool ED;
//int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cerr<<(&ED-&ST)/1024.0/1024<<endl;	
//	cin>>ID>>T;while(T--)solve();
//	return 0;
//}
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=2e5+5,M=105;
bool ST;
int ID,T,n,m;vector<int>gr[N];
//int mxl[N],mxp[N],xl[N],xp[N];
//void dfs(int p,int fa){
//	xl[p]=-n,mxl[p]=mxp[p]=xp[p]=0;
//	for(auto to:gr[p]){
//		if(to==fa)continue;
//		dfs(to,p);
//		bool fl=0;
//		if(mxl[to]>=0){
//			int d=mxl[to]+1;
//			if(d>mxl[p])xl[p]=mxl[p],xp[p]=mxp[p],mxl[p]=d,mxp[p]=to,fl=1;
//			else if(d>xl[p])xl[p]=d,xp[p]=to,fl=1;
//		}
//		if(!fl&&xl[to]>=0){
//			int d=xl[to]+1;
//			if(d>mxl[p])xl[p]=mxl[p],xp[p]=mxp[p],mxl[p]=d,mxp[p]=to;
//			else if(d>xl[p])xl[p]=d,xp[p]=to;
//		}
//	}
////	cout<<p<<' '<<mxp[p]<<' '<<mxl[p]<<' '<<xp[p]<<' '<<xl[p]<<'\n';
//}
//int res,rt;
//void redfs(int p,int fa,int v,bool fl){
//	if(p!=rt){
//		if(fl)res=min(res,max(mxl[p],v));
//	}
//	for(auto to:gr[p]){
//		if(to==fa)continue;
//		if(to==mxp[p])res
//		else redfs(to,p,max(v+1),fl);
//	}
//}
bool vis[M];int f[M][M];
int fa[N];
inline int find(int f){
	while(f!=fa[f])f=fa[f]=fa[fa[f]];
	return fa[f];
}
inline void merge(int u,int v){
	u=find(u),v=find(v);
	if(u!=v)fa[u]=v;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)gr[i].clear();
	for(int i=1,u,v;i<n;i++)cin>>u>>v,gr[u].push_back(v),gr[v].push_back(u);
	if(m==n)return cout<<0<<'\n',void();
//	if(ID==7){
//		int ans=n;
//		rt=1,res=n+1,dfs(rt,0),redfs(rt,0,0),ans=min(ans,res);
////		for(rt=1;rt<=n;rt++)
//		cout<<ans<<' ';
//	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=i==j?0:n+1;
	for(int p=1;p<=n;p++)for(auto to:gr[p])f[p][to]=1;
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	int ans=n;
	for(int S=0;S<(1<<n);S++){
		if(__builtin_popcount(S)!=m)continue;
		for(int i=0;i<n;i++)vis[i+1]=(S>>i)&1,fa[i+1]=i+1;
		for(int u=1;u<=n;u++)for(auto v:gr[u])if(vis[u]&&vis[v])merge(u,v);
		int mx=0,tot=0;
		for(int i=1;i<=n;i++)if(vis[i])tot+=i==find(i);
		if(tot>2)continue;
		for(int i=1;i<=n;i++){
			int d=n+1;
			for(int j=1;j<=n;j++)if(vis[j])d=min(d,f[i][j]);
			mx=max(mx,d);
		}
		ans=min(ans,mx);
	}
	cout<<ans<<'\n';
}
bool ED;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
//	cerr<<(&ED-&ST)/1024.0/1024<<endl;	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>ID>>T;while(T--)solve();
	return 0;
}
//last remote
/*
7 1
16 2
1 2
1 3
1 4
2 5
2 6
3 7
3 8
5 9
7 10
8 11
8 12
11 13
12 14
12 15
15 16
ans:3


0 2
5 2
1 2
2 3
3 4
4 5
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
