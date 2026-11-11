#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[50005];
int a[5003][5003];
int t[5003][5003];
int vis[5003][5003];
vector<int>h[10003];
long long mx=0;bool f;
void dfs(int x,int y,long long cnt){
	if(x==y){
		mx=max(mx,cnt);f=1;

		return;
	}
	for(int i=0;i<=h[x].size();i++){
		int v=h[x][i];
			if(f==1)return;
			for(int j=1;j<=a[v][0];j++){
				if(!vis[v][j]){
					vis[v][j]=1;
					dfs(a[v][j],y,cnt+t[v][j]);
				}
			}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>a[i][0];
		for(int j=1;j<=a[i][0];j++){
			cin>>a[i][j]>>t[i][j];
			h[a[i][j]].push_back(i);
		}
	}
	while(q--){
		f=0;
		memset(vis,0,sizeof(vis));
		mx=0;
		int x,y;cin>>x>>y;
		dfs(x,y,0);
		cout<<mx+w[x]+w[y]<<endl;
	}
	return 0;
} 
