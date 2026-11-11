#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF LONG_LONG_MAX
const int M=5e5+10;
const int N=510;
int w[M],k[N];
struct node{
	int sta;
	int times;
	node(int s,int t):sta(s),times(t){}
};
struct Snode{
	int line;
	int times;
	Snode(int l,int t):line(l),times(t){}
};
vector<node> a[N];
bool cmp(node x,node y){
	return x.sta<y.sta;
}
int g[N][N];
int n,m,d,q;
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(g[i][k]!=INF){
				for(int j=1;j<=n;j++){
					if(g[k][j]!=INF&&g[i][k]+g[k][j]<g[i][j]){
						g[i][j]=g[i][k]+g[k][j];
					}
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int abc;
	cin>>abc>>n>>m>>d>>q;
	vector<Snode> b[m+1];
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int u,t;
			cin>>u>>t;
			a[i].push_back(node(u,t));
			b[u].push_back(Snode(i,t));
		}
		sort(a[i].begin(),a[i].end(),cmp);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int l=0,r=0,minn=INF;
			while(l<k[i]&&r<k[j]){
				if(a[i][l].sta<a[j][r].sta){
					l++;
				}else if(a[i][l].sta>a[j][r].sta){
					r++;
				}else{
					minn=min(minn,a[i][l].times+a[j][r].times);
					l++;
					r++;
				}
			}
			g[i][j]=g[j][i]=minn;
		}
	}
	floyd();
	while(q--){
		int st,ed;
		cin>>st>>ed;
		int minn=INF;
		for(int i=0;i<b[st].size();i++){
			for(int j=0;j<b[ed].size();j++){
				int u=b[st][i].line,v=b[ed][j].line;
				minn=min(minn,w[st]+w[ed]+b[st][i].times+b[ed][j].times+g[u][v]);
			}
		}
		cout<<minn<<'\n';
	}
	return 0;
}