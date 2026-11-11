#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
const int N=3400+10;
const long long inf=0x3f3f3f3f3f3f3f3f;
vector<vector<long long>> g(N);
long long dist[N][N];
long long w[N];
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	int nn=n;
	
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	
	
	for(int i=1;i<=d*n;i++){
		for(int j=1;j<=d*n;j++){
			dist[i][j]=inf;
		}
	}
	
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		int last=-1;
		
		for(int j=1;j<=k;j++){
			long long u,w;
			cin>>u>>w;
			if(last!=-1){
				dist[last][u+g[u].size()*n]=0;
				dist[u+g[u].size()*n][last]=0;
			}
			g[u].emplace_back(w);
			
			last=u+(g[u].size()-1)*n;
			
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=0;k<g[i].size();k++){
				dist[n*j+i][n*k+i]=min(dist[n*j+i][n*k+i],g[i][j]+g[i][k]);
			}
		}
		
	}
	
	n=d*n;
	
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	
	
	for(int k=1;k<=q;k++){
		int x,y;
		cin>>x>>y;
		long long ans=inf;
		for(int i=0;i<d;i++){
			for(int j=0;j<d;j++){
				ans=min(ans,dist[x+i*nn][y+j*nn]+w[x]+w[y]+g[x][i]+g[y][j]);
			}
		}
			
		cout<<ans<<endl;
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}