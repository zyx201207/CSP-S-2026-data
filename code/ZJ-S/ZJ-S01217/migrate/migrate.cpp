#include <bits/stdc++.h>
using namespace std;
const int N=3e2+10;
int c,T;
int n,d;
int a[N];
int dist[N][N];
int sum[N][N];
int p[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	cin>>c>>T;
	while (T--){
		cin>>n>>d;
		memset(p,0,sizeof p);
		memset(dist,0x3f,sizeof dist);
		for (int i=1;i<=n;i++){
			cin>>a[i];
			p[i]+=a[i];
			p[i]+=p[i-1];
			dist[i][i]=0;
			dist[i-1][i]=a[i]-a[i-1];	
		}
		for (int i=2;i<=n;i++){
			for (int j=1;j<=n-i+1;j++){
				for (int k=j;k<=n-i+1;k++){
					if (dist[j][j+i]>dist[j][k]+dist[k][j+i]){
						dist[j][j+i]=dist[j][k]+dist[k][j+i];
						sum[i][j]=1;
					}
					else if (dist[j][j+i]==dist[j][k]+dist[k][j+i]){
						sum[i][j]++;	
					}
				} 
			}
		}
		int ans=0;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (sum[i][j]==2 && i!=j){
					ans++;
				}	
			}
		}
//		for (int i=1;i<=n;i++){
//			for (int j=1;j<=n;j++){
//				cout<<dist[i][j]<<" ";	
//			}
//			cout<<endl;
//		}
		cout<<ans<<endl; 
	}
	return 0;
}
