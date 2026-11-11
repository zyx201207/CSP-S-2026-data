#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans=0;
int w[500005];
vector<int> linee[500005];
struct node{
	int id;
	int line[505];
	int tline[505];
}a[500005];
void dfs(int u,int v){
	if(u==v) return;
	for(int culine:a[u].line){
		for(int cunode:linee[culine]){
			if(cunode==v){ans=w[u]+w[v]+a[u].tline[culine]+a[v].tline[culine];return;}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) {cin>>w[i];a[i].id=i;}
	for(int i=1;i<=n;i++){
		int k,o=0;cin>>k;
		for(int j=1;j<=k;j++){
			int x;cin>>x;
			a[x].line[o++]=i;linee[i].push_back(x);
			cin>>a[i].tline[a[i].line[i]];
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;cin>>u>>v;
		dfs(u,v);
		cout<<ans<<endl;
	}
	return 0;
}

