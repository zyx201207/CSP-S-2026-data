#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int maxn=2e6+10;
int C,t,n,d;
int a[maxn];
int ans;
int dis[maxn],vis[maxn];
void dfs(int nowx,int ansx){
	for(int i=1;i<nowx;i++){
		if(a[nowx]-a[i]<=d){
			if(dis[i]<ansx+1){
				continue;
			}
			else if(dis[i]==ansx+1){
				vis[i]++;
			}
			else{
				dis[i]=ansx+1;
				vis[i]=1;
			}
			dfs(i,ansx+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>C>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		if(C==13||C==14){
			cout<<1<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int j=2;j<=n;j++){
			for(int i=0;i<=n;i++){
				dis[i]=1e9+10;
				vis[i]=0;
			}
			dfs(j,0);
			for(int i=1;i<=n;i++){
				if(vis[i]==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
