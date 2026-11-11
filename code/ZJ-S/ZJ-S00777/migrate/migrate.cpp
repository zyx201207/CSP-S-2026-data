#include<bits/stdc++.h>
using namespace std;
int c,t;
long long a[200001];
long long dis[5001][5001];
long long dist[5001][5001];//i~j
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=1e9;
				dist[i][j]=0; 
			}
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
			dis[i][i]=0;
			dist[i][i]=1;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=k;i++){
				for(int j=k;j<=n;j++){
					if(a[j]-a[k]<=d&&dis[i][k]+1<dis[i][j]){
//						cout<<"different"<<i<<" "<<k<<" "<<j<<endl;
						dis[i][j]=dis[i][k]+1;
						dist[i][j]=dist[i][k];
					}
					else if(a[j]-a[k]<=d&&dis[i][k]+1==dis[i][j]){
//						cout<<"same"<<i<<" "<<k<<" "<<j<<endl;
						dist[i][j]+=dist[i][k];
					}
				}
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
//				cout<<i<<" "<<j<<" "<<dis[i][j]<<" "<<dist[i][j]<<endl;
				if(dist[i][j]==2){
//					cout<<i<<" "<<j<<endl;
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/ 
