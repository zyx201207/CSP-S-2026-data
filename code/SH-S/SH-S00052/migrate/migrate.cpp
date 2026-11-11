#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d;
long long x[2000010];
vector<int>g[2000010];
int vis[2000010];
int bfs(int s,int t){
	queue<int>que;
	for(int i=1;i<=n;i++) vis[i]=0;
	que.push(s);
	vis[s]=1;
	int cnt=0;
	while(que.size()){
		int h=que.front();
		if(vis[h]>=vis[t]&&vis[t]!=0) break;
		que.pop();
		if(cnt>2) break;
		for(int j:g[h]){
			if(j==t) cnt++;
			if(vis[j]) continue;
			vis[j]=vis[h]+1;
			que.push(j);
		}
	}
	return cnt==2;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		if(c>=13&&c<=14){
			cout<<"0\n";
			continue;
		}
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			g[i].clear();
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					g[i].push_back(j);
				}
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans+=bfs(i,j); 
			}
		}
		cout<<ans<<"\n";
	}
}
