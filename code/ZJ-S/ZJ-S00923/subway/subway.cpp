#include<bits/stdc++.h>
#define int long long
#define mp(a,b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
const int N=510,M=5e5+10,INF=1e17;
int c,n,m,d,q,G[N][N];
int w[M];
vector<pii>gr[N],ed[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<=n+5;i++)
	for(int j=0;j<=n+5;j++){
		if(i==j)G[i][j]=0;
		else G[i][j]=INF;
	}
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			gr[i].push_back(mp(x,y));
			ed[x].push_back(mp(i,y));
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<gr[i].size();j++){
			int a=gr[i][j].first,w=gr[i][j].second;
			 for(int k=0;k<ed[a].size();k++){
			 	int to=ed[a][k].first,w2=ed[a][k].second;
			 	if(to==i)continue;
			 	G[i][to]=min(G[i][to],w+w2);
			 }
		}
		/*
		for(int j=0;j<gr[i].size();j++){
			for(int k=0;k<gr[i].size();k++){
				if(j==k)continue;
				int p1=gr[i][j].first,p2=gr[i][k].first;
				G[p1][p2]=min(G[p1][p2],gr[i][j].second+gr[i][k].second);
			}
		}
		*/
	}
	/*
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++){
		if(i!=j&&G[i][j]!=INF){
			cout<<i<<" "<<j<<" "<<G[i][j]<<endl;
		}
	}
	*/
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
			}
		}
	}
	while(q--){
		int x,y,ans=INF;
		cin>>x>>y;
		for(int i=0;i<ed[x].size();i++)
		for(int j=0;j<ed[y].size();j++){
			int w1=ed[x][i].second,w2=ed[y][j].second;
			int p1=ed[x][i].first,p2=ed[y][j].first;
			if(ans>w1+w2+G[p1][p2]){
				ans=w1+w2+G[p1][p2];
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
