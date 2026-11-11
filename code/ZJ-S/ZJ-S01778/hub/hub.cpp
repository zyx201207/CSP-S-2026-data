#include<bits/stdc++.h>
using namespace std;
int c,T,n,k,dis[4010][4010],t,b[1000010],ans=1e9;
vector<int> g[1000010];
bool f[1000010],has[1000010];
void dfs1(int x){
	f[x]=1;
	for(int i=0;i<g[x].size();i++){
		int v=g[x][i];
		if(has[v]&&!f[v]){
			f[v]=1;
			dfs1(v);
		}
	}
}
bool check(){
	for(int i=1;i<=n;i++) has[i]=f[i]=0;
	int cnt=0;
	for(int i=1;i<=t;i++) has[b[i]]=1;
	for(int i=1;i<=t;i++){
		if(f[b[i]]) continue;
		dfs1(b[i]);
		cnt++;
	}
	return cnt<=2;
}
void dfs(int x){
	if(t==k){
		if(check()){
			int maxn=-1e9;
			for(int i=1;i<=n;i++){
				int minn=1e9;
				for(int j=1;j<=t;j++){
					minn=min(minn,dis[min(i,b[j])][max(i,b[j])]);
				}
				maxn=max(maxn,minn);
			}
			ans=min(ans,maxn);
		}
		return;
	}
	if(x==n+1) return;
	b[++t]=x;
	dfs(x+1);
	t--;
	dfs(x+1);
}
void solv(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[i][j]=1e9;
	}
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
		dis[x][y]=1;
	}
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	if(k==2){
		int minn=1e9;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int maxn=-1e9;
				for(int k=1;k<=n;k++){
					maxn=max(maxn,min(dis[min(k,i)][max(k,i)],dis[min(k,j)][max(k,j)]));
				}
				minn=min(minn,maxn);
			}
		}
		cout<<minn<<'\n';
		return;
	}
	dfs(1);
	cout<<ans<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--) solv();
	return 0;
}

