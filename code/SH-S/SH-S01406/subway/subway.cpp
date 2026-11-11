#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=5e5+5;
int c,n,m,d,q,w[M],u[M],cd[M],x,y,t[50][M],ans;
vector<int> e[M],l[50];
bool find(int u,int line){
	for(int i=0;i<l[u].size();i++)
		if(l[u][i]==line)
			return 1;
	return 0;
}
int bl(int x,int y){
	for(int i=0;i<l[x].size();i++)
		for(int j=0;j<l[y].size();j++)
			if(l[x][i]==l[y][j]){
				return l[x][i];
			}
}
void dfs(int u,int fa,int time,int line){
	if(u==y){
		cout<<y<<'\n';
		time+=t[line][u];
		ans=min(ans,time);
		return ;
	}
	if(!cd[u]) return ;
	cout<<u<<'\n';
	for(int i=0;i<e[u].size();i++){
		if(!find(e[u][i],line)){
//			cout<<e[u][i]<<' '<<u<<'\n';
//			cout<<t[bl(e[u][i],u)][u]<<'\n';
			time=time+t[line][u]+t[bl(e[u][i],u)][u];
			dfs(e[u][i],u,time,bl(e[u][i],u));
			time=time-(t[line][u]+t[bl(e[u][i],u)][u]);
		}
		else 
			dfs(e[u][i],u,time,line);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int ti;
			cin>>u[j]>>ti;
			t[i][u[j]]=ti;
			l[u[j]].push_back(i);
//			cout<<u[j]<<' '<<t[i][u[j]]<<'\n';
		}
		for(int j=1;j<k;j++){
			e[u[j]].push_back(u[j+1]);
			cd[u[j]]++; 
		}
	}
//	cout<<bl(1,2)<<' '<<bl(3,2)<<'\n';
	while(q--){
		cin>>x>>y;
		ans=2e9;
		for(int i=0;i<l[x].size();i++){
//			cout<<t[l[x][i]][x]<<'\n';
			int sum=w[x]+w[y];
			sum+=t[l[x][i]][x];
			dfs(x,-1,sum,l[x][i]);
		}
		cout<<ans<<'\n';
	}
}
