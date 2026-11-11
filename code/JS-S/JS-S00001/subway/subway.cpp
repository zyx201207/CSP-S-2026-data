#include<bits/stdc++.h>
using namespace std;
const int N=1e9;
int qweq,n,m,d,q; 
int ans;
vector<int> w;
vector<vector<int>> it,a,ch;
vector<int> vis;
void dfs(int now,int to,int c){
	if(now==to){
		ans=min(ans,c);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(i==now) continue;
		int xc=c+ch[now][i];
		if(vis[i]!=N&&vis[i]<=xc) continue;
		if(xc>ans) continue;
		vis[i]=true;
		dfs(i,to,xc);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&qweq,&n,&m,&d,&q);
	w.resize(n+1);
	it.resize(m+1,vector<int>());
	a.resize(n+1,vector<int>(m+1));
	ch.resize(n+1,vector<int>(n+1,N));
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int k; scanf("%d",&k);
		for(int j=0;j<k;j++){
			int ai,ti; scanf("%d%d",&ai,&ti);
			a[i][ai]=ti;
			it[ai].push_back(i);
		}
	}
	for(int i=1;i<n;i++){
		ch[i][i]=0;
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<=m;k++){
				if(a[i][k]&&a[j][k]) ch[i][j]=min(ch[i][j],a[i][k]+a[j][k]);
			}
		}
	}
	while(q--){
		int x,y;ans=N; scanf("%d%d",&x,&y);
		for(auto x1:it[x]) for(auto y1:it[y]){
			vis.assign(n+1,N);
			dfs(x1,y1,a[x1][x]+a[y1][y]+w[x]+w[y]);
		}
		printf("%d\n",ans);
		return 0;
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2 
 */

