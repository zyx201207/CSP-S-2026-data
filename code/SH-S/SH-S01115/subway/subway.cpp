#include<bits/stdc++.h>
using namespace std;
const int N=1009;
vector<int>edge[N];
int min_d[N][N],w[N],a[N],t[N];
bool vis[N][N];
int c,n,m,d,q,ans;
void dfs(int x,int start,int end,int last){
	if(x==end)return;
	for(auto y:edge[x]){
		if(y==last||vis[x][y])continue;
		min_d[start][y]=min(min_d[start][x]+min_d[x][y],min_d[start][y]);
		min_d[y][start]=min_d[start][y];
		vis[x][y]=1;
		dfs(y,start,end,x);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	memset(min_d,0x3f,sizeof(min_d));
	for(int i=1;i<=n;i++){
		int cnt;
		cin>>cnt;
		for(int j=1;j<=cnt;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=cnt;j++){
			for(int k=j+1;k<=cnt;k++){
				edge[a[j]].push_back(a[k]);
				edge[a[k]].push_back(a[j]);
				min_d[a[j]][a[k]]=t[j]+t[k];
				min_d[a[k]][a[j]]=t[j]+t[k];
			}
		}
	}
	while(q--){
		memset(vis,0,sizeof(vis));
		int start,end;
		cin>>start>>end;
		dfs(start,start,end,-1);
		ans=w[start]+w[end]+min_d[start][end];
		cout<<ans<<'\n';
	}
	return 0;
}
