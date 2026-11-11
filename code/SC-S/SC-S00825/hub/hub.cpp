#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+6;
int c,T,n,k;
vector<int> v[MAXN];
bool vis[MAXN],f[MAXN];
void dfs(int x){
	vis[x]=1;
	for(int i:v[x])
		if(!vis[i]&&f[i]) dfs(i);
	return ;
}
queue<pair<int,int> > q;
int bfs(){
	for(int i=1;i<=n;i++){
		vis[i]=0;
		if(f[i]) vis[i]=1,q.push({i,0});
	}
	int res=0;
	pair<int,int> p;
	while(!q.empty()){
		p=q.front();
		res=max(res,p.second);
		q.pop();
		for(int i:v[p.first]){
			if(!vis[i]){
				vis[i]=1;
				q.push({i,p.second+1});
			}
		}
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		int a,b;
		for(int i=1;i<n;i++){
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		int t,cnt;
		int ans=1e9;
		for(int i=1;i<=(1<<n)-1;i++){
			t=0,cnt=0;
			for(int j=1;j<=n;j++) vis[j]=f[j]=0;
		 	for(int j=1;j<=n;j++)
		 		if(((1<<(j-1))&i)>0){
		 			t++;
		 			f[j]=1;
				}
			if(t!=k) continue ;
			for(int j=1;j<=n;j++){
				if(((1<<(j-1))&i)>0&&!vis[j]){
					cnt++;
					dfs(j);
				}
			}
//			printf("(%d,%d)",t,cnt);
			if(cnt>2||t!=k) continue ;
//			cout<<bfs()<<' ';
			ans=min(ans,bfs());
		}
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++) v[i].clear();
	}
	return 0;
}