#include<bits/stdc++.h>
using namespace std;
const int NUM=10000000;
int c,t,n,ans,dis[2000001];
long long d,x[2000001];
int a[5000][5000];
/*void dj(int s){
	for(int i=1;i<=n;i++)dis[i]=NUM;
	dis[0]=NUM;dis[s]=0;
	while(1){
		int u=0;
		for(int i=1;i<=n;i++){
			if(!vis[i]&&dis[i]<dis[u])u=i;
		}
		if(u==0)break;
		vis[u]=1;
		for(int i=0;i<a[u].size();i++){
			int v=a[u][i];
			if(dis[v]>dis[u]+1)dis[v]=dis[u]+1;
		}
	}
}*/
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			for(int j=1;j<i;j++){
				if(x[i]-x[j]<=d){
					a[i][j]=1;
					a[j][i]=1;
				}
				else{
					a[i][j]=NUM;a[j][i]=NUM;
				}
			}
		}
		/*for(int i=1;i<=n;i++){
			for(int j=a[i][a[i].size()-1]+1;j<=n;j++){
				if(f(i,j))ans++;
			}
		}*/
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				int cnt=0;
				for(int k=j+1;k<i;k++){
					if((a[j][k]==a[j][i]-1)&&x[i]-x[k]<=d)cnt++;
					if(cnt>3)break;
				}
				if(cnt==2){
					//cout<<i<<" "<<j<<"\n";
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
