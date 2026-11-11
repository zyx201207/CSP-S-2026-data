#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,u,v,maxa;
vector <long long> s[1000005];
long long vis[1000005];
//queue <long long> q;
//void bfs(long long x){
//	while(!q.empty())
//	for(int i=0;i<s[x].size();i++){
//		if(vis[s[x][i]]==0){
//			vis[s[x][i]]=vis[x]+1;
//			dfs(s[x][i]);
//		}
//	}
//}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			cin>>u>>v;
			s[u].push_back(v);
			s[v].push_back(u);
		}
//		for(int i=1;i<=n;i++){
//			memset(vis,0,sizeof(vis));
//			vis[i]=0;
//			q.push(i);
//			bfs();
//			for(int j=1;j<=n;j++){
//				maxa=max(maxa,vis[j]);
//			}
//		}
		cout<<k-1<<"\n";
	}
	return  0;
}

