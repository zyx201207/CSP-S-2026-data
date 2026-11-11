#include <bits/stdc++.h>
using namespace std;
const int N=1e3,M=5e5+5;
struct Node{
	int v,dist;
};
int c,n,m,d,q,w[N];
long long dist[N][N];
vector<struct Node> tt[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1,k;i<=n;i++){
		cin>>k;
		dist[i][i]=0;
		for(int j=1,st,ti;j<=k;j++){
			cin>>st>>ti;
			for(int kk=0;kk<tt[st].size();kk++){
				dist[i][tt[st][kk].v]=tt[st][kk].dist+ti;
				dist[tt[st][kk].v][i]=tt[st][kk].dist+ti;
			}
			tt[st].push_back({i,ti});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			for(int k=1;k<=n;k++){
				if(i==k or j==k) continue;
				if(dist[i][k]+dist[k][j]<dist[i][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		long long ans=(1ll<<60);
		for(int j=0;j<tt[x].size();j++){
			for(int k=0;k<tt[y].size();k++){
				ans=min(ans,(long long)dist[tt[x][j].v][tt[y][k].v]+w[x]+w[y]+tt[x][j].dist+tt[y][k].dist);
//				cout<<"\\"<<dist[tt[x][j].v][tt[y][k].v]<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

