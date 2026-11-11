#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int ans[N][N];
int c,t,n,d;
int dis[N];
void dfs(int dep){
	for(int i=dep+1;i<=n;i++){
		if(dis[i]-dis[dep]>=d){
			ans[dep][i]+=1;
			dfs(i);
		}
		else return;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int cnt=0;
		memset(ans,0,sizeof ans);
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>dis[i];
		}
		dfs(dis[1]);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(ans[i][j]==2){
					cnt++;
				}
			}
			
		}
		if(d<=dis[2]-dis[1]) cout<<0;
		else cout<<n-3<<"\n";
	}
}
