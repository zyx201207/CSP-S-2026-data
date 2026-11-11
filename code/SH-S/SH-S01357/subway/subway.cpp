#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=511,M=5e5+10,inf=1e15;
int c,n,m,d,q;
int tts[M];//w[i]
int dis[N][N];
int k[N],a[N][N],t[N][N];
vector<pair<int,int> > qp[M];
void input(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>tts[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			qp[a[i][j]].push_back(make_pair(i,t[i][j]));
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=inf,dis[j][i]=inf;
}
void built(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<qp[i].size();j++){
			for(int k=0;k<j;k++){
				int p1=qp[i][j].first,t1=qp[i][j].second,p2=qp[i][k].first,t2=qp[i][k].second;
				dis[p1][p2]=min(dis[p1][p2],t1+t2);
				dis[p2][p1]=min(dis[p2][p1],t1+t2);
			}
		}
	}
}
void Floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
int nx,ny,ans;
void solve(){
	while(q--){
		cin>>nx>>ny;
		ans=inf;
		for(int i=0;i<qp[nx].size();i++){
			for(int j=0;j<qp[ny].size();j++){
				int p1=qp[nx][i].first,t1=qp[nx][i].second,p2=qp[ny][j].first,t2=qp[ny][j].second;
				ans=min(ans,t1+t2+dis[p1][p2]);
				if(p1==p2) ans=min(ans,t1+t2);
			}
		}
//		if(ans==inf) cout<<"DIS"<<endl;
		cout<<ans+tts[nx]+tts[ny]<<endl;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	input();
	built(); 
	Floyd();
	solve();
}
