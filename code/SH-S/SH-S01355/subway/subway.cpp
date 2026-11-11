#include<bits/stdc++.h>
using namespace std;

long long c, n, m, d, q, ans, maxn;
long long w[500005];
long long line[1002][1002], t[1002][1002];
bool visit[500005];

void dfs(int node, int spend, int vis, int f){
	if(vis>m) return;
	if(node==f){
		if(spend<maxn) maxn=spend;
		return;
	}
	for(int i=1;i<=n;i++){
		int j=1; bool dotravel=false;
		while(line[i][j]!=-1) {
			if(line[i][j]==node) dotravel=true;
			j++;
		}
		j=1;
		if(dotravel)
			while(line[i][j]!=-1){
				if(!visit[line[i][j]]){
					visit[line[i][j]]=true;
					dfs(line[i][j], spend+t[i][node]+t[i][line[i][j]], vis+1, f);
					visit[line[i][j]]=false;
				}
				j++;
			}
	}
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++) {
			cin>>line[i][j]; cin>>t[i][line[i][j]];
		}
		line[i][k+1]=-1;
	}
	while(q--){
		ans=0;
		maxn=2147483647;
		int x, y;
		cin>>x>>y;
		ans+=w[x]+w[y];
		memset(visit, false, m+1);
		dfs(x,0,1,y);
		ans+=maxn;
		cout<<ans<<endl;
	}
	return 0;
}
