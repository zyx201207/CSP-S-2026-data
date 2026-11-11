#include<bits/stdc++.h>
using namespace std;
struct lines{
	inr a,t;
};
const int MAXM=5e5+5;
int c,n,m,d,q,k,ans,w[MAXM],used[MAXM];
vector<lines> E[MAXM];
vector<lines> l;
void dfs(int x,int y){
	if(x==y) return;
	used[x]=true;
	for(int i=0;i<E[x].size();i++){
		if(!used[E[x][i].a]){
			used[E[x][i].a]=true;
			ans=ans+E[x][i].t+lines[x].t;
			dfs(E[x][i].a);
			used[E[x][i]]=false;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>k;
		l[i].resize(k);
		if(k>2) flag=false;
		for(int j=1;j<=k;j++)
			cin>>l[i][j].a>>l[i][j].t;
	}
	if(flag){
		for(int i=1;i<=n;i++){
			lines u=l[i][1],v=l[i][2];
			E[u.a].push_back(v);
			E[v.a].push_back(u);
		}
	}
	while(q--){
		memset(used,0,sizeof(used));
		int x,y,ans=0;
		cin>>x>>y;
		if(flag) dfs(x,y);
		cout<<ans<<endl;
	}
	return 0;
}
