#include<bits/stdc++.h>
using namespace std;
int n,k,c,t,mn=1e9,vis[505],mp[505][505];
void mmin(){
	int d[505],v[505],mx;
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			v[i]=1;
			q.push(i);
			d[i]=0;
		}else d[i]=1e9;
	}
	while(!q.empty()){
		int c=q.front();
		q.pop();
		for(int i=1;i<=n;i++){
			if(mp[c][i]){
				if(!vis[i]){
					d[i]=d[c]+1;
					q.push(i);
					mx=max(mx,d[i]);
				}
			}
		}
	}mn=min(mn,mx);
}
bool l(){
	queue<int>q;
	int v[505],cnt=0;
	for(int i=1;i<=n;i++){
		if(vis[i] and !v[i]){
			q.push(i);
			v[i]=1;
			while(!q.empty()){
				int c=q.front();
				q.pop();
				for(int j=1;j<=n;j++){
					if(mp[c][j]){
						if(!v[j]){
							v[j]=1;
							q.push(j);
						}
					}
				}
			}cnt++;
		}
	}return cnt<=2;
}
void dfs(int p,int s){
	if(p>n){
		if(l){
			mmin();
		}
		return;
	}if(s<k){
		vis[p]=1;
		dfs(p+1,s+1);
		vis[p]=0;
	}dfs(p+1,s);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			mp[u][v]=1;
			mp[v][u]=1;
		}
		dfs(1,0);
		cout<<mn;
	}
	return 0;
}
