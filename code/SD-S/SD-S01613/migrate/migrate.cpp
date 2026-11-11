#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000010],num[310],dis[310],vis[310],ans;
queue<int>q;
void bfs(int s){
	memset(num,0,sizeof(num));
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	q.push(s);
	dis[s]=0;
	num[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=1;i<=n;i++){
			if(abs(x[i]-x[u])<=d){
				if(dis[i]<=dis[u]){
					continue;
				}
				else if(dis[u]+1==dis[i]){
					num[i]+=num[u];
					if(num[i]>2||vis[u]){
						vis[i]=1;
					}
				}
				else{
					num[i]=num[u];
					dis[i]=dis[u]+1;
					q.push(i);
				}
			}
		}
	}
	for(int i=s+1;i<=n;i++){
		if(vis[i]==0&&num[i]==2){
			ans++;
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		ans=0;
		for(int i=1;i<=n;i++){
			bfs(i);
		}
		cout<<ans<<endl;
	}
	return 0;
}













