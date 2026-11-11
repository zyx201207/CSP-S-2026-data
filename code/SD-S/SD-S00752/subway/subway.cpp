#include<bits/stdc++.h>
using namespace std;
const int M=2e4+10;
const int N=510;
long long w[M],t[M];
long long f[N][M];
bool flag[M];
int c,n,m,d,q,x,y;
long long ans;
void dfs(int u,long long t,long long v){
	flag[u]=true;
	if(u==y){
		ans=min(ans,t+f[v][u]+w[u]);
		return;
	}
	for(int i=1;i<=m;i++){
		if(f[v][i]!=0&&flag[f[v][i]]==false){
			dfs(i,t,v);
		}
	}
	for(int i=1;i<=n;i++){
		if(f[i][u]!=0&&flag[f[i][u]]==false){
			dfs(u,t+f[v][u]+f[i][u],i);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int s;
		cin>>s;
		for(int j=1;j<=s;j++){
			int a,b;
			cin>>a>>b;
			f[i][a]=b;
		}
	}
	for(int i=1;i<=q;i++){
		memset(flag,false,sizeof(flag));
		cin>>x>>y;
		ans=1e18;
		for(int i=1;i<=n;i++){
			if(f[i][x]!=0){
				dfs(x,w[x],i);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
