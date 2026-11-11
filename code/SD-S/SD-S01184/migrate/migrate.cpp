#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T;
int n,d ;
int a[2000006]; 
vector<int>g[2000006];
int s[2000006];
bool vis[2000006];
int cnt[2000006];
queue<int>q;
void bfs(int st){
	while(!q.empty()){
		q.pop();
	}
	memset(vis,0,sizeof(vis));
	memset(s,0x3f,sizeof(s));
	memset(cnt,0,sizeof(cnt));
	q.push(st);
	s[st]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			if(vis[g[u][i]]){
				continue;
			}
			if(s[g[u][i]]>s[u]+1){
				s[g[u][i]]=s[u]+1;
				cnt[g[u][i]]=1;
				q.push(g[u][i]);
			}else if(s[g[u][i]]==s[u]+1){
				cnt[g[u][i]]++;
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int r=1;
		for(int i=1;i<=n;i++){
			while(r<=n&&a[r]<=a[i]+d){
				r++;
			}
			g[i].clear();
			for(int l=i+1;l<r;l++){
				g[i].push_back(l);
			}
		}
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
