#include<bits/stdc++.h>
using namespace std;
int n,d;
int a[2000005];
int dis[20005][20005]={0};
int cnt=0;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin>>c>>t;
	for(;t-->0;){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) dis[i][j]=0;
				else if(abs(a[i]-a[j])<=d) dis[i][j]=1;
				else dis[i][j]=1e9;
			}
		}
		int ans=0;
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(dis[i][k]+dis[k][j]<dis[i][j]){
						dis[i][j]=dis[i][k]+dis[k][j];
					}else if(dis[i][k]+dis[k][j]==dis[i][j]){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
