#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int c,n,m,d,q;
int w[20005];
int ki[505];
int a[505][20005],t[505][20005];
int x,y,ans=0x3f3f3f3f,sum=0;
vector <int> e[1005],v[1005];
int kj[505][1005];
bool vis[1005];
void dfs(int k){
	if(vis[k]){
		return;
	}
	if(k==y){
		ans=min(ans,sum);
		return;
	}
	if(sum>=ans){
		return;
	}
	vis[k]=true;
	for(int i=0;i<e[k].size();i++){
		if(sum+t[e[k][i]][v[k][i]]>=ans){
			continue;
		}
		sum+=t[e[k][i]][v[k][i]];
		for(int j=1;j<=ki[e[k][i]];j++){
			sum+=t[e[k][i]][kj[ki[e[k][i]]][a[e[k][i]][j]]];
			dfs(a[e[k][i]][j]);
			sum-=t[e[k][i]][kj[ki[e[k][i]]][a[e[k][i]][j]]];
		}
		sum-=t[e[k][i]][v[k][i]];
	}
	vis[k]=false;
	return;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>ki[i];
		for(int j=1;j<=ki[i];j++){
			cin>>a[i][j]>>t[i][j];
			e[a[i][j]].push_back(i);
			v[a[i][j]].push_back(j);
			kj[ki[i]][a[i][j]]=j;
		}
	}
	for(int i=1;i<=q;i++){
		memset(vis,false,sizeof vis);
		cin>>x>>y;
		dfs(x);
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}

