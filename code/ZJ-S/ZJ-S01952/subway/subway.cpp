#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int maxn=500+10;
const int maxm=5e5+10;
int c,n,m,d,q;
int w[maxm];
vector<int> a[maxn];
int t[maxm][maxn];
long long dis[maxn][maxn];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		a[i].resize(k+1);
		for(int j=1;j<=k;j++){
			cin>>a[i][j];
			cin>>t[a[i][j]][i];
		}	
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		for(int k=1;k<a[i].size();k++){
			int u=a[i][k];
			for(int j=1;j<=n;j++){
				if(t[u][j]!=0) dis[i][j]=min(dis[i][j],1LL*t[u][i]+1LL*t[u][j]);
				dis[j][i]=dis[i][j];
			}
		}
	}
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=1;k<=n;k++)
				if(i!=k&&j!=k) dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=n;i++)
		dis[i][i]=0;
	while(q--){
		int u,v;
		cin>>u>>v;
		long long ans=1e18;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(t[u][i]!=0&&t[v][j]!=0){
					ans=min(ans,dis[i][j]+1LL*w[u]+1LL*w[v]+1LL*t[u][i]+1LL*t[v][j]);
				} 
			}
		}
		cout<<ans<<'\n';
	} 
}

