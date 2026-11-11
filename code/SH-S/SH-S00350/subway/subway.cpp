#include <bits/stdc++.h>
using namespace std;
const int N=505,M=500005;
int c,n,m,d,q,w[M],k[N],a[N][M],t[N][M];
long long ans;
vector<int> v[M];//该地铁站被哪些线经过 
bool vis[M];
void dfs(int x,int y,int p,int line,int time){//从x到y,p为是否到站厅 ，line在哪条线上（p=1,line=0） 
	
	if(vis[x]) break;
	vis[x]=1;
	if(p){
		for(int l:v[x]){
			dfs(x,y,0,l,t[l][/*???*/]);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			v[a[i][j]].push_back(i);
		}
	}
	for(int i=1,x,y;i<=q;i++){
		memset(vis,0,sizeof(vis));
		cin>>x>>y;
		ans=w[x]+w[y];
		//dfs(x,y,1,0,0); 
	}
	return 0;
} 
