#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e6+10; 
int a[N]; 
int c,t; 
int n,d; 
vector<int>g[N],g2[N]; 
int dis[N],vis[N],cnt[N]; 
int ind[N]; 
int num=0; 
void bfs(int s){
	dis[s]=0;
	queue<int>q; 
	q.push(s);vis[s]=1; 
	while(!q.empty()){
		int u=q.front();q.pop();
		vis[u]=0;
		for(int v:g[u]){
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;  
				if(!vis[v]){
					vis[v]=1;
					q.push(v); 
				}
			}
		}
	} 
	for(int i=1;i<=n;i++)g2[i].clear(); 
	for(int i=1;i<=n;i++){
		for(int j:g[i]){
			if(dis[i]+1==dis[j]){
				g2[i].push_back(j); 
				ind[j]++; 
			}
		}
	}
	queue<int>hq; 
	for(int i=1;i<=n;i++){
		if(ind[i]==0){
			hq.push(i);
			cnt[i]=1; 
		}
	}
	while(!hq.empty()){
		int u=hq.front();hq.pop(); 
		for(int v:g2[u]){
			cnt[v]+=cnt[u]; 
			if(--ind[v]==0){
				hq.push(v); 
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(cnt[i]==2)num++; 
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	cin>>c>>t; 
	while(t--){
		num=0; 
		cin>>n>>d; 
		for(int i=1;i<=n;i++){
			g[i].clear(); 
			g2[i].clear(); 
		}
		for(int i=1;i<=n;i++)cin>>a[i]; 
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue; 
				if(a[j]-a[i]<=d)g[i].push_back(j); 
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[j]=1e18;
				vis[j]=0; 
				cnt[j]=0; 
				ind[j]=0; 
			} 	
			bfs(i); 
		}
		cout<<num<<endl; 
	}
	return 0; 
}
