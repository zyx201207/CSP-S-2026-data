#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <map>
using namespace std;
const int N=5e3+5;
int vis1[N],vis[N],n,k,s[N][N],ss[N][N],d[N],ans=99999999;
vector<int>e[N];
bool check(){
	memset(vis1,0,sizeof(vis1));
	for(int i=1;i<=n;i++)vis1[i]=vis[i];
	queue<int>q;
	for(int i=1;i<=n;i++)
		if(vis1[i]){
			q.push(i);
			break;
		}
	while(!q.empty()){
		int t=q.front();q.pop();
		vis1[t]=0;
		for(auto v:e[t])q.push(v);
	}
	for(int i=1;i<=n;i++)
		if(vis1[i]){
			q.push(i);
			break;
		}
	while(!q.empty()){
		int t=q.front();q.pop();
		vis1[t]=0;
		for(auto v:e[t])q.push(v);
	}
	for(int i=1;i<=n;i++)
		if(vis1[i])
			return false;
	return true;
}
void gz(int kk){
	if(kk==k){
		if(check()){
			int ans1=0;
			memset(d,0x7f,sizeof(d));
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					ss[i][j]=s[i][j];
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					for(int k=1;k<=n;k++)
						ss[i][j]=min(ss[i][k]+ss[k][j],ss[i][j]);
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++){
					d[i]=min(d[i],ss[i][j]);
				}
			for(int i=1;i<=n;i++)ans1=max(ans1,d[i]);
			ans=min(ans,ans1);
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			gz(kk+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		memset(s,0x7f,sizeof(s));
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			s[u][v]=s[v][u]=1;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		gz(0);
		cout<<ans;
		for(int i=1;i<=n;i++)e[i].clear();
	}
	return 0;
}
