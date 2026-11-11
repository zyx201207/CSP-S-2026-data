#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int N=508,M=5e5+8,inf=5e11+8;
int c,n,m,d,q,w[M],k[N],dist[N][N],sum[M];
map<pair<int,int>,int> t;
vector<pair<int,int> >v[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dist[i][j]=inf;
		}
		dist[i][i]=0;
	}
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a;
			cin>>a;
			cin>>t[make_pair(i,a)]; 
			v[a].push_back(make_pair(i,t[make_pair(i,a)]));
			sum[a]++;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<sum[i]-1;j++){
			for(int k=j+1;k<sum[i];k++){
				int ot1=v[i][j].first,ot2=v[i][k].first;
				int ti1=v[i][j].second,ti2=v[i][k].second;
				if(dist[ot1][ot2]>ti1+ti2){
					dist[ot1][ot2]=dist[ot2][ot1]=ti1+ti2;
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dist[i][k]+dist[k][j]<dist[i][j]){
					dist[i][j]=dist[j][i]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int ans=inf,x,y;
		cin>>x>>y;
		for(int j=0;j<sum[x];j++){
			for(int k=0;k<sum[y];k++){
				int dis=dist[v[x][j].first][v[y][k].first];
				int zou=t[make_pair(v[x][j].first,x)]+t[make_pair(v[y][k].first,y)];
				if(dis+zou<ans){
					ans=dis+zou;
				}
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}