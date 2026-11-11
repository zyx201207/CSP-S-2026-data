#include<bits/stdc++.h>
#define int long long
#define N 501000
using namespace std;
int w[N],dep[N+N],fa[N+N],k[N],bian,f[N*2][22],r[N*2][22];
struct node{
	int x,y,z;
}b[N*4];
int tzz33,n,m,d,q;
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
vector<pair<int,int>> t[N+N];
void dfs(int x,int fa,int yu){
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	r[x][0]=yu;
	for(int i=1;i<20;i++){
		f[x][i]=f[f[x][i-1]][i-1];
		r[x][i]=r[x][i-1]+r[f[x][i-1]][i-1];
	}
	for(auto hhh:t[x]){
		if(hhh.first==fa)continue;
		dfs(hhh.first,x,hhh.second);
	}
}
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	int ans=0;
	int kkk=dep[u]-dep[v];
	for(int i=19;i>=0;i--){
		if((kkk>>i)&1){
			ans+=r[u][i];
			u=f[u][i];
		}
	}
	if(u==v)return ans;
	for(int i=19;i>=0;i--){
		if(f[u][i]!=f[v][i]){
			ans+=r[u][i]+r[v][i];
			u=f[u][i];
			v=f[v][i];
		}
	}
	ans+=r[u][0]+r[v][0];
	return ans;
}
void debug(){
	cout<<"me1\n";
	for(int i=1;i<=n+m;i++){
		cout<<i<<": ";
		for(auto j:t[i]){
			cout<<"edge"<<j.first<<" bian"<<j.second<<' ';
		}
		cout<<endl;
	}
	cout<<"dep\n";
	for(int i=1;i<=n+m;i++){
		cout<<i<<":"<<dep[i]<<' ';
	}
	cout<<"\n";
	cout<<"f1\n";
	for(int i=1;i<=n+m;i++){
		cout<<i<<":"<<f[i][1]<<' ';
	}
	cout<<"\n";
	cout<<"r1\n";
	for(int i=1;i<=n+m;i++){
		cout<<i<<":"<<r[i][1]<<' ';
	}
	cout<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>tzz33>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n+m;i++){
		fa[i]=i;
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			b[++bian].x=i;
			b[bian].y=n+x;
			b[bian].z=y;
		}
	}
	sort(b+1,b+1+bian,[](node a,node b){
		return a.z<b.z;
	});
	int c=0;
	for(int i=1;i<=bian;i++){
		int x=find(b[i].x);
		int y=find(b[i].y);
		if(x!=y){
			fa[x]=y;
			c++;
			t[b[i].x].push_back({b[i].y,b[i].z});
			t[b[i].y].push_back({b[i].x,b[i].z});
			if(c==n+m-1)break;
		}
	}
	
	dfs(1,0,0);
//	debug();
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+lca(n+x,n+y)<<endl;
	}
	return 0;
} 
