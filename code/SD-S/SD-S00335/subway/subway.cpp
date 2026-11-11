#include<bits/stdc++.h>
#define int long long
using namespace std; 
const int inf=1e18+7;
int read(){
	int res=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=(res<<1)+(res<<+3)+(c^48);
		c=getchar();
	}
	return res*f;
}
void print(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		print(x/10);
	}
	putchar((x%10)^48);
}
const int M=5e5+666;
const int N=510;
int cid,n,m,d,q,w[M],k[N],g[N][N];
vector<pair<int,int> >station[M];
//vector<int>line[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cid=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;++i){
		w[i]=read();
	}
	for(int i=1;i<=n;++i){
		k[i]=read();
		for(int j=1;j<=k[i];++j){
			int x=read(),tim=read();
//			line[i].push_back(x);
			station[x].push_back({i,tim});
		}
	}
	memset(g,0x3f,sizeof(g));
	for(int i=0;i<=n+5;++i){
		g[i][i]=0;
	}
	for(int i=1;i<=m;++i){
		for(int j=0;j<station[i].size();++j){
			for(int p=j+1;p<station[i].size();++p){
				pair<int,int>pt1=station[i][j],pt2=station[i][p];
				g[pt1.first][pt2.first]=g[pt2.first][pt1.first]=min(g[pt1.first][pt2.first],pt1.second+pt2.second);
			}
		}
	}
	for(int mid=1;mid<=n;++mid){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(i==mid||i==j||mid==j)continue;
				g[i][j]=min(g[i][j],g[i][mid]+g[mid][j]);
			}
		}
	}
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=n;++j){
//			cerr<<i<<"->"<<j<<":"<<g[i][j]<<"\n";
//		}
//	}
	while(q--){
		int u=read(),v=read();
		int ans=inf;
		for(int i=0;i<station[u].size();++i){
			for(int j=0;j<station[v].size();++j){
				int x=station[u][i].first,y=station[v][j].first;
//				cerr<<x<<"->"<<y<<":"<<g[x][y]<<"\n";
				ans=min(ans,g[x][y]+station[u][i].second+station[v][j].second);
			}
		}
		print(ans+w[u]+w[v]);putchar('\n');
	}
	return 0;
}
