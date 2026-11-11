#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,M=5e5+10;
int w[M],k[N];
vector<int>a[N],t[N];
vector<int>v[M],qq[M];
int dist[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
			v[x].push_back(i);
			qq[x].push_back(y);
		}
	}memset(dist,0x3f,sizeof(dist));
	for(int i=1;i<=m;i++){
		for(int j=0;j<v[i].size();j++){
			for(int k=j+1;k<v[i].size();k++){
				dist[v[i][j]][v[i][k]]=min(dist[v[i][j]][v[i][k]],qq[i][j]+qq[i][k]);
				dist[v[i][k]][v[i][j]]=dist[v[i][j]][v[i][k]];
			}
		}
	}
	for(int i=1;i<=n;i++){
		dist[i][i]=0;
	}
	for(int tmp=1;tmp<=n;tmp++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=min(dist[i][j],dist[i][tmp]+dist[tmp][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=0x3f3f3f3f3f3f3f3f;
		for(int i=0;i<v[x].size();i++){
			for(int j=0;j<v[y].size();j++){
				ans=min(ans,dist[v[x][i]][v[y][j]]+qq[x][i]+qq[y][j]);
			}
		}cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
