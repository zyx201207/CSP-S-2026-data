#include<iostream>//T2 44-60
#include<vector>
#include<queue>
#define ll long long
using namespace std;
const int N=505,M=5e5+5;
ll w[M],k,a[M],t[M],s[M];
bool vis[M];
struct node{
	ll v,w;
};
vector<node>g[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,Q;
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int ii=1;ii<k;ii++){
			for(int jj=ii+1;jj<=k;jj++){
				int u=a[ii],v=a[jj];
				g[u].push_back((node){v,t[ii]+t[jj]});
				g[v].push_back((node){u,t[ii]+t[jj]});
			}
		}
	}
	while(Q--){
		for(int i=1;i<=m;i++){
			s[i]=1e18;
			vis[i]=0; 
		}
		int bg,fn;
		cin>>bg>>fn;
		s[bg]=0;
		queue<int>q;
		q.push(bg);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(auto p:g[u]){
				ll v=p.v,w=p.w;
				if(vis[v]) continue;
				if(s[v]<=s[u]+w) continue;
				s[v]=s[u]+w;
				q.push(v);
				vis[v]=1;
			}
		}
		cout<<s[fn]+w[bg]+w[fn]<<"\n";
	}
	return 0;
}
/*
#include<iostream>//T2 O(n3) 44
#define ll long long
using namespace std;
const int N=505,M=5e3+5;//M=5e5
ll w[M],k,s[M][M],a[M],t[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i!=j) s[i][j]=1e12;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int ii=1;ii<k;ii++){
			for(int jj=ii+1;jj<=k;jj++){
				int u=a[ii],v=a[jj];
				s[u][v]=min(s[u][v],t[ii]+t[jj]);
				s[v][u]=s[u][v];
			}
		}
	}
	for(int kk=1;kk<=m;kk++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				s[i][j]=min(s[i][j],s[i][kk]+s[kk][j]);
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<s[u][v]+w[u]+w[v]<<endl;
	}
	return 0;
}
*/ 
