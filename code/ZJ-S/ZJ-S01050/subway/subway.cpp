#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,M=500005;
int c,n,m,d,q,w[M],dis[N][N];
struct node{
	int v,t;
};
vector<node> e[M];
int read(){
	char c=getchar();
	int f=1,x=0;
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c^48);
	}
	return f*x;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v,t;
			cin>>v>>t;
			e[v].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(auto p1:e[i]){
			for(auto p2:e[i]){
				if(p1.v!=p2.v){
					dis[p1.v][p2.v]=min(dis[p1.v][p2.v],p1.t+p2.t);
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y,ans=0x3f3f3f3f3f3f3f3f;
		cin>>x>>y;
		for(auto p1:e[x]){
			for(auto p2:e[y]){
				ans=min(ans,w[x]+w[y]+p1.t+p2.t+dis[p1.v][p2.v]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
