#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[20005],k[505],a[505][20005],t[505][20005],x,y,ans,v[20005][25],idx[20005];
bool visited[20005];
void dfs(int sta,int line,int tmp){
	for(int i=1;i<=k[line];i++){
		if(a[line][i]==y){
			ans=min(ans,tmp+t[line][y]);
			break;
		}
		if(a[line][i]!=sta&&!visited[a[line][i]]){
			for(int j=1;j<=idx[a[line][i]];j++){
				if(v[a[line][i]][j]!=line){
					visited[a[line][i]]=true;
					dfs(a[line][i],v[a[line][i]][j],tmp+t[line][a[line][i]]+t[v[a[line][i]][j]][a[line][i]]);
					visited[a[line][i]]=false;
				}
			}
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
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
	}
	memset(idx,0,sizeof(idx));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			v[a[i][j]][++idx[a[i][j]]]=i;
		}
	}
	while(q--){
		cin>>x>>y;
		ans=2147483647;
		memset(visited,false,sizeof(visited));
		visited[x]=true;
		for(int i=1;i<=idx[x];i++) dfs(x,v[x][i],w[x]+w[y]+t[v[x][i]][x]);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
