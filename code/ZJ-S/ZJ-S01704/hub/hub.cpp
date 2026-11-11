#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int t,ccff;
vector<int>v[50001];
int b[50001];
int c[50001];
bool vis[50001];
bool islian(){
	int t=0;
	for(int i=1;i<=n;i++){
		if(b[i]==1 && !vis[i]){
			queue<int>q;
			t++;
			q.push(i);
			while(!q.empty()){
				int k=q.front();
				q.pop();
				vis[k]=true;
				for(int j=0;j<v[k].size();j++){
					if(b[v[k][j]]==1 && !vis[v[k][j]]){
						vis[v[k][j]]=true;
						q.push(v[k][j]);
					}
				}
			}
		}
	}
	return t<=2;
}
void ytt(int x,int y){
	c[x]=y;
	for(int i=0;i<v[x].size();i++){
		if(y+1<c[v[x][i]]){
			ytt(v[x][i],y+1);
		}
	}
	return ;
}
int ma(){
	memset(c,0x3f,sizeof(c));
	for(int i=1;i<=n;i++){
		if(b[i]==1)ytt(i,0);
	}
	int maxx=0;
	for(int i=1;i<=n;i++){
		maxx=max(maxx,c[i]);
	}
	return maxx;
}
int dfs(int x,int y){
	if(x==m){
		memset(vis,false,sizeof(vis));
		if(!islian())return LLONG_MAX;
		return ma();
	}
	int ans=LLONG_MAX;
	for(int i=y+1;i<=n;i++){
		b[i]=1;
		ans=min(ans,dfs(x+1,i));
		b[i]=0;
	}
	return ans;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>ccff>>t;
	while(t--){
		memset(v,0,sizeof(v));
		cin>>n>>m;
		for(int i=1;i<n;i++){
			int u,w;cin>>u>>w;
			v[u].push_back(w);
			v[w].push_back(u);
		}
		cout<<dfs(0,0)<<endl;
	}
	return 0;
}
