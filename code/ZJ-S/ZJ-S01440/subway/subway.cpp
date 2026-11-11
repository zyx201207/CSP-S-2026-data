#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=5e5+5;
int c[M],a,C,n,m,d,Q,num,p,q,s;
ll dis[N][N],ans,t;
struct node{
	ll id,tm;
};
vector<node> g[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>C>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		cin>>num;
		for(int j=1;j<=num;j++){
			cin>>a>>t;
			g[a].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=j+1;k<g[i].size();k++){
				p=g[i][j].id,q=g[i][k].id,t=g[i][j].tm+g[i][k].tm;
				dis[p][q]=dis[q][p]=min(dis[p][q],t);
			}
		}
	}
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(Q--){
		cin>>s>>t;
		ans=1e18;
		for(int i=0;i<g[s].size();i++){
			for(int j=0;j<g[t].size();j++){
				ans=min(ans,dis[g[s][i].id][g[t][j].id]+g[s][i].tm+g[t][j].tm);
			}
		}
		cout<<ans+c[s]+c[t]<<"\n";
	}
	return 0;
}
