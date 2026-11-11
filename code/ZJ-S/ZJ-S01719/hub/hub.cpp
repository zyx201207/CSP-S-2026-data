#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,m;
vector<int> v[2000010];
int f[4010][4010];
int vis[4010];
int ans;
void dfs(int x,int fa,int l,int r,int cnt){
	if(f[l][r]!=1e9){
		return;
	}
	if(x==r){
		f[l][r]=cnt;
		return;
	}
	for(int k=0;k<v[x].size();k++){
		int u=v[x][k];
		if(u!=fa){
			dfs(u,x,l,r,cnt+1);
		}
	}
}
void bfs(int x,int k){
	queue<int> q;
	q.push(x);
	vis[x]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int kk=0;kk<v[x].size();kk++){
			int u=v[x][kk];
			if(vis[u]){
				continue;
			}
			if((k&(1<<(u-1)))==0){
				continue;
			}
			q.push(u);
			vis[u]=1;
		}
	}
}
bool check(int k){
	int tot=0;
	for(int i=1;i<=n;i++){
		if((k&(1<<(i-1)))&&!vis[i]){
			bfs(i,k);
			tot++;
		}
	}
	return tot<=2;
}
int get(int k){
	int maxx=0;
	for(int i=1;i<=n;i++){
		int minn=1e9;
		for(int j=1;j<=n;j++){
			if((k&(1<<(j-1)))==0){
				continue;
			}
			minn=min(minn,f[i][j]);
		}
		maxx=max(maxx,minn);
	}
	return maxx;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=1e9;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			v[i].clear();
		}
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=1e9;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				dfs(i,0,i,j,0);
				f[j][i]=f[i][j];
			}
		}
		for(int k=0;k<(1<<n);k++){
			int tot=__builtin_popcount(k);
			if(tot!=m){
				continue;
			}
			for(int i=1;i<=n;i++){
				vis[i]=0;
			}
			if(!check(k)){
				continue;
			}
			ans=min(ans,get(k));
		}
		cout<<ans<<"\n";
	}
	return 0;
}