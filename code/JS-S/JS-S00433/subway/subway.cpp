//Furk CCF!!!!!!!!!!!
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF=0x3f3f3f3f;
const int MX=1e5+5;


int c,n,m,d,q;
int w[20005];//m
struct line{vector<int> a;vector<int> t;}l[505];

int g[20005][20005];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)cin>>w[i];
	for(int i=0;i<n;i++){
		int k;cin>>k;
		for(int j=0;j<k;j++){
			int u,v;
			cin>>u>>v;
			l[i].a.push_back(u);
			l[i].t.push_back(v);
			}
		}
	
	memset(g,0x3f,sizeof(g));
	for(int i=0;i<m;i++)g[i][i]=0;
	for(int i=0;i<n;i++){
		for(int u : l[i].a){
			for(int v : l[i].a){
				g[u][v]=w[u];//u->v
				g[v][u]=w[v];//v->u
				}
			}
		}
		
	//floyd
	
 	for(int k=0;k<=m;k++){
		for(int i=0;i<=m;i++){
			for(int j=0;j<=n;j++){
				if(g[i][k]<INF && g[k][j]<INF){
					g[i][j]=min(g[i][j] , g[k][j]+g[i][k]);
				}
			}
		}
	}
	
	
	
	while(q--){
		int x,y;
		
		cin>>x>>y;
		cout<<g[x][y]+2*l[0].t[0]<<endl;
		
	}
	
	return 0;
}
