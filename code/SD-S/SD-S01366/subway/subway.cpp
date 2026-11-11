#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=509,M=5e5+9,INF=1e17+9;
int c,n,m,d,q;
int w[M],a[N][N],dist[N][N];
vector<int> pas[M],psw[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			if(i==j)continue;
			else
			a[i][j]=INF,dist[i][j]=INF;
	}
	{
		//1e6
		int a,k,t;
		for(int i=1;i<=n;i++){
			cin>>k;
			for(int j=1;j<=k;j++){
				scanf("%lld%lld",&a,&t);
				pas[a].push_back(i);
				psw[a].push_back(t);
			}
		}
	}
	//1e7
	for(int i=1;i<=m;i++){
		for(int j=0;j<pas[i].size();j++){
			for(int k=j+1;k<pas[i].size();k++){
				int u=pas[i][j],v=pas[i][k];
				int tu=psw[i][j],tv=psw[i][k];
				a[u][v]=min(a[u][v],tu+tv);
				a[v][u]=a[u][v];
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(a[i][j]==INF)cout<<"@"; 
//			else cout<<a[i][j];
//			cout<<" ";
//		}
//		cout<<"\n";	
//	}
	//1e8
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<=n;k++){
				a[j][i]=a[i][j]=min(a[i][j],a[i][k]+a[j][k]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(a[i][j]==INF)cout<<"@"; 
//			else cout<<a[i][j];
//			cout<<" ";
//		}
//		cout<<"\n";	
//	}
	int x,y,ans;
	//4e7
	while(q--){
		ans=INF;
		scanf("%lld%lld",&x,&y);
		for(int i=0;i<pas[x].size();i++){
			for(int j=0;j<pas[y].size();j++){
				ans=min(ans,a[pas[x][i]][pas[y][j]]+psw[x][i]+psw[y][j]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
