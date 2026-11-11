#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=310,inf=1e18;
int c,t,n,d,minn=inf,cnt;
int a[N];
int dis[N][N];
unordered_map<int,int> mp;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cnt=0;
		for (int i=1;i<310;i++){
			for (int j=1;j<310;j++){
				dis[i][j]=inf;
			}
		}
		cin>>n>>d;
		for (int i=1;i<=n;i++){
			cin>>a[i];
		}
		for (int i=1;i<=n;i++){
			dis[i][i]=0;
		}
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (j!=i&&abs(a[i]-a[j])<=d){
					dis[i][j]=1;
				}
//				cout<<((abs(a[i]-a[j]))<=d)<<" ";
			}
//			cout<<"\n";
		}
//		cout<<"\n";
		for (int u=1;u<=n;u++){
			for (int v=u+1;v<=n;v++){
				mp.clear();
				minn=1e18;
				for (int k=1;k<=n;k++){	
					if (k!=u&&k!=v&&dis[u][k]!=1e18&&dis[k][v]!=1e18){
						int d=dis[u][k]+dis[k][v];
						dis[u][v]=min(dis[u][v],d);
//						if (dis[u][v]<minn){
//							cout<<k<<" "<<dis[u][v];
//						}
						minn=min(minn,dis[u][v]);
						mp[d]++;
					}
				}		
//				cout<<"\n";
				if(mp[minn]==2){
					cnt++;
//					cout<<minn<<" "<<u<<" "<<v<<"\n";
				}
//				cout<<u<<" "<<v<<" "<<minn<<" "<<cnt<<" "<<mp[minn]<<"\n";
			}		

		}				
//		cout<<"\n";
//		for (int i=1;i<=n;i++){
//			for (int j=1;j<=n;j++){
//				cout<<dis[i][j]<<" ";
//			}
//			cout<<"\n";
//		}
		cout<<cnt<<"\n";
	}
	return 0;
}
//1 1 0 0 0 0 0
//1 1 1 1 0 0 0
//0 1 1 1 1 1 0
//0 1 1 1 1 1 0
//0 0 1 1 1 1 1
//0 0 1 1 1 1 1
//0 0 0 0 1 1 1

//0 1 2 2 3 3 4
//1 0 1 1 2 2 3
//1000000000000000000 1 0 1 1 1 2
//1000000000000000000 1 1 0 1 1 2
//1000000000000000000 1000000000000000000 1 1 0 1 1
//1000000000000000000 1000000000000000000 1 1 1 0 1
//1000000000000000000 1000000000000000000 1000000000000000000 1000000000000000000 1 1 0
