#include <bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
int w[M],l[N];
struct S{
	int a,b;
};
vector<S> bel[M];
long long g[N][N];
long long dis[N][N];
int st[N],ed[N];
int main(){
  	freopen("subway.in","r",stdin);
  	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(dis,0x3f,sizeof dis);
	memset(g,0x3f,sizeof g);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(int i=1;i<=n;i++){
		cin>>l[i];
		for(int j=1;j<=l[i];j++){
			int u,w;
			cin>>u>>w;
			bel[u].push_back({i,w});
		}
	}
	for(int i=1;i<=m;i++){
		int len=bel[i].size();
		for(int j=0;j<len;j++){
			for(int k=j+1;k<len;k++){
				int a1=bel[i][j].a,a2=bel[i][k].a;
				long long w1=bel[i][j].b,w2=bel[i][k].b;
				g[a1][a2]=min(g[a1][a2],w1+w2);
				g[a2][a1]=min(g[a2][a1],w1+w2);
				
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<g[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=g[i][j];
		}
		dis[i][i]=0;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}	
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	while(q--){
		int x,y;
		cin>>x>>y;
		long long ans=0x3f3f3f3f3f3f3f3fll;
		int len1=bel[x].size(),len2=bel[y].size();
		for(int i=0;i<len1;i++){
			for(int j=0;j<len2;j++){
				int a1=bel[x][i].a,a2=bel[y][j].a;
				int w1=bel[x][i].b,w2=bel[y][j].b;
				ans=min(ans,dis[a1][a2]+w1+w2);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
fc C:\Users\lenovo\Desktop\kaoshi\subway\subway7.ans C:\Users\lenovo\Desktop\kaoshi\subway\subway7.out
*/
