#include<bits/stdc++.h>
using namespace std;
int const N=2e4+10;
int c,n,m,d,q;
int cs1[N];
int dist[N][N];
map<int,int> tool;
map<pair<int,int>,int> mp;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dist[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=m;i++) cin>>cs1[i];
	for(int i=1;i<=n;i++){
		int k;
		vector<int> v;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			tool[a]=t;
			v.push_back(a);
		}
		for(int j1=0;j1<v.size();j1++){
			for(int j2=j1+1;j2<v.size();j2++){
				int v1=v[j1],v2=v[j2];
				dist[v1][v2]=tool[v1]+tool[v2];
				dist[v2][v1]=tool[v1]+tool[v2];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			for(int t=1;t<=m;t++){
				if(t==i||t==j) continue;
				if(dist[i][t]==INT_MAX||dist[t][j]==INT_MAX) continue;
				dist[i][j]=min(dist[i][j],dist[i][t]+dist[t][j]);
			}
			dist[j][i]=dist[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<dist[x][y]+cs1[x]+cs1[y]<<endl;
	}
	return 0;
}

