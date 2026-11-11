#include<bits/stdc++.h>
using namespace std;
vector<int> t[1000005];
bool f[25];
bool vis[25];
int dis[25];
int main(){
	freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
	cin.tie(0);
    int c,T;
	cin>>c>>T;
	while(T--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			t[i].clear();
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			t[u].push_back(v);
			t[v].push_back(u);
		}
		if(n<=20){
			int ans=1e9;
			int s=1<<n;
			for(int i=0;i<s;i++){
			    int j=i;
			    int num=0;
			    for(int k=1;k<=n;k++){
			    	vis[k]=0;
			    	dis[k]=1e9;
			    	f[k]=j&1;
			    	if(f[k]==1){
			    		num++;
					}
			    	j>>=1;
				}
				if(num!=k){
					continue;
				}
				int sum=0;
				for(int k=1;k<=n;k++){
					if(f[k]==1&&vis[k]==0){
						sum++;
						vis[k]=1;
						queue<int> q;
						q.push(k);
						while(!q.empty()){
							int u=q.front();
							q.pop();
							for(auto v:t[u]){
								if(f[v]==1&&vis[v]==0){
									vis[v]=1;
									q.push(v);
								}
							}
						}
					}
					
				}
				if(sum>2){
					continue;
				}
				for(int k=1;k<=n;k++){
					if(f[k]==0){
						continue;
					}
					for(int j=1;j<=n;j++){
						vis[j]=0;
					}
					queue<int> q;
					q.push(k);
					dis[k]=0;
					vis[k]=1;
					while(!q.empty()){
						int u=q.front();
						q.pop();
						for(auto v:t[u]){
							if(vis[v]==0){
								vis[v]=1;
								q.push(v);
								dis[v]=min(dis[u]+1,dis[v]);
							}
						}
					}
				}
				int ma=0;
				for(int j=1;j<=n;j++){
					ma=max(ma,dis[j]);
				}
				ans=min(ans,ma);
			}
			cout<<ans<<'\n';
			continue;
		}
		else{
			cout<<1<<'\n';
		}
	}
}