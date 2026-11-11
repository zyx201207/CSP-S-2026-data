#include<bits/stdc++.h>
const int slen=2e3+10;
const long long INF=0x7f7f7f7f7f7f7f7f;
using namespace std;
int w[slen];
int c,n,m,d,q;
struct info{
  int to,w;
};
vector<info>e[slen];
long long dis[slen][slen];
int main(){
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  memset(dis,0x7f,sizeof(dis));
  cin>>c>>n>>m>>d>>q;
  for(int i=1;i<=m;i++){cin>>w[i];}
  for(int i=1;i<=n;i++){
  	int k;
  	cin>>k;
  	for(int j=1;j<=k;j++){
  	  int v,w;
  	  cin>>v>>w;
  	  dis[i][v+n]=w;
  	  dis[v+n][i]=w;
	}
  }
  for(int k=1;k<=n+m;k++){
  	for(int i=1;i<=n+m;i++){
  	  for(int j=1;j<=n+m;j++){
  	    if(dis[i][k]!=INF&&dis[j][k]!=INF&&dis[i][j]>dis[i][k]+dis[j][k]){
  	      dis[i][j]=dis[i][k]+dis[j][k];
		}
	  }
	}
  }
  for(int i=1;i<=q;i++){
  	int x,y;
  	cin>>x>>y;
  	cout<<w[x]+w[y]+dis[x+n][y+n]<<'\n';
  }
  return 0;
}