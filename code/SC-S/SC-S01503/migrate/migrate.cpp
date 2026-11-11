#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int x[2000005];
int g[8005][8005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(g,0,sizeof g);
		for(int i=1;i<=n;i++)cin>>x[i];
		int tg=0;
		for(int i=1;i<=n;i++){
			int cnt=0;
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				else if(abs(x[i]-x[j])<=d){
					g[i][j]=g[j][i]=1;
					cnt++;
				}
			}
			if(cnt==n-1&&tg==0){
				tg=i;
			}
		}
		int ans=0;
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j||i==k||j==k)continue;
					if(i==tg||j==tg||k==tg)continue;
					if(g[i][k]&&g[k][j]&&g[i][j]==0)ans++;
				}
			}
		}
		cout<<ans/2<<"\n";
	}
}