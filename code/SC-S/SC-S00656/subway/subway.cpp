#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q;
int w[N],t[N][M];long long G[N][N];
vector<int>site[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){//和k=5x10^5
		int k,a[N];
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j];
			site[a[j]].push_back(i);
			cin>>t[i][a[j]];//i线路 a[j]输入的站厅
		}
	}
	memset(G,16,sizeof(G));
	for(int o=1;o<=m;o++){//M*d^2=1e8
		for(auto i:site[o]){
			for(auto j:site[o]){
				G[i][j]=t[i][o]+t[j][o];
				G[j][i]=t[i][o]+t[j][o];
			}
		}
	}
	long long ans=1111111415145;
	for(int k=1;k<=n;k++){//n^3=2.5e7
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)G[i][j]=0;
				G[i][j]=min(G[i][k]+G[k][j],G[i][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){//q*d^2=4e7
		int x,y;
		ans=1111111415145;
		cin>>x>>y;
		for(auto e:site[x]){
			for(auto u:site[y]){
				ans=min(G[e][u]+t[e][x]+t[u][y],ans);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<endl;
	}
	return 0;
}