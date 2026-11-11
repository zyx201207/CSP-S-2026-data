#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
const unsigned long long inf=1e18;
int c,n,m,d,q,t[N][N];
unsigned long long dist[N][N],w[M];
bool b[N][N];
vector<int> zh[M];
void bf(){
//	for(int i=1;i<=n;i++){
//		dist[i][i]=0;
//	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int kk=1;kk<=n;kk++){
				if(i!=j&&b[i][kk]&&b[kk][j]){
//					cout<<i<<' '<<j<<' '<<kk<<' '<<dist[i][kk]<<' '<<dist[kk][j]<<endl;
					dist[i][j]=min(dist[i][j],dist[i][kk]+dist[kk][j]);
				}
			}
		}
	}
}
int main(){ios::sync_with_stdio(false);cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a;
			cin>>a>>t[i][a];
			zh[a].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dist[i][j]=inf;
		}
	}
	for(int i=1;i<m;i++){
		for(int j=0;j<zh[i].size();j++){
			for(int kk=0;kk<zh[i].size();kk++){
				int x=zh[i][j],y=zh[i][kk];
				b[x][y]=1;
//				cout<<i<<' '<<j<<' '<<a[i][k1]<<' '<<a[j][k2]<<' '<<t[i][a[i][k1]]+t[j][a[j][k2]]<<endl;
				dist[x][y]=min(dist[x][y],(unsigned long long)t[x][i]+t[y][i]);
			}
			
		}
	}
					
	
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dist[i][j]<<' ';
//		}cout<<endl;
//	}
	bf();
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dist[i][j]<<' ';
//		}cout<<endl;
//	}
	while(q--){
		int x,y;
		cin>>x>>y;
		unsigned long long ans=inf;
		int m1=-1,m2=-1;
//		cout<<zh[x].size();
		for(int i=0;i<zh[x].size();i++){
			for(int j=0;j<zh[y].size();j++){
//				cout<<zh[x][i]<<' '<<zh[y][i];
				if(dist[zh[x][i]][zh[y][j]]<ans){
					ans=dist[zh[x][i]][zh[y][j]];
					m1=zh[x][i];
					m2=zh[y][j];
				}
			}
		}
//		cout<<m1<<' '<<m2<<endl;
		if(m1==m2){
			cout<<w[x]+w[y]+t[m1][x]+t[m2][y]<<endl;
		}else{
			cout<<w[x]+w[y]+ans+t[m1][x]+t[m2][y]<<endl;
		}
	}
	return 0;
}