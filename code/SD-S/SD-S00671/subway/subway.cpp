#include<bits/stdc++.h>
using namespace std;
#define N 501000
#define endl "\n"
#define mod 998244353
int c,n,m,d,q;
vector<int>w(N),chu(N);
vector<int>a[N];
vector<long long>t[N];
long long dis[800][800];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dis,0x1f,sizeof dis);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	//建图 
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u=i+m,v,W;
			cin>>v>>W;
			a[u].push_back(v);
			a[v].push_back(u);
			t[u].push_back(W);
			t[v].push_back(W);
			chu[v]++;
		}
	}
	//预处理
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<chu[i];j++){
			for(int k=0;k<chu[i];k++){
				int u=a[i][j]-m,v=a[i][k]-m;
				if(u==v)continue;
//				cout<<"run"<<t[i][j]+t[i][k]<<endl;
				dis[u][v]=min(t[i][j]+t[i][k],dis[u][v]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][j]>dis[i][k]+dis[k][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
//	cout<<"-------------------dis"<<endl;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<"--------------------"<<endl;
	//处理查询
	while(q--){
		int u,v;
		cin>>u>>v;
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(int i=0;i<chu[u];i++){
			for(int j=0;j<chu[v];j++){
				int s=a[u][i]-m,e=a[v][j]-m;
//				cout<<"query: "<<t[u][i]<<" "<<t[v][j]<<" "<<dis[s][e]<<" "<<t[u][i]+t[v][j]+dis[s][e]<<" "<<ans<<endl;
				ans=min(t[u][i]+t[v][j]+dis[s][e],ans);
			}
		}
		cout<<ans+w[u]+w[v]<<endl;
	} 
	return 0;
}
//subway
