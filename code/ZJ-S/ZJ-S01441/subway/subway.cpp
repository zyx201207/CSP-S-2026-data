#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500510;
struct node{
	int x,y,z;
}b[N];
struct nd{
	int x,v;
};
vector<nd>v[N];
int w[N],f[N],fa[N][22],dis[N][22],dep[N];
int find(int x){
	if(f[x]==0)return x;
	f[x]=find(f[x]);
	return f[x];
}
bool cmp(node a1,node a2){
	return a1.z<a2.z;
}
void dfs(int p,int fr){
	dep[p]=dep[fr]+1;
	for(auto son:v[p]){
		if(son.x==fr)continue;
		fa[son.x][0]=p;
		dis[son.x][0]=son.v;
		dfs(son.x,p);
	}
	return;
}
int lca(int x,int y){
	int num=0;
	if(dep[x]<dep[y])swap(x,y);
	for(int i=20;i>=0;i--){
		if(dep[fa[x][i]]>=dep[y]){
			num+=dis[x][i];
			x=fa[x][i];
		}
	}
	if(x==y)return num;
	for(int i=20;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			num+=dis[x][i]+dis[y][i];
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	num+=dis[x][0]+dis[y][0];
	return num;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,k,a,t,cnt=0,x,y,ans;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			cnt++;
			b[cnt]={a,m+i,t};
		}
	}
	sort(b+1,b+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		if(find(b[i].x)!=find(b[i].y)){
			f[find(b[i].x)]=find(b[i].y);
			v[b[i].x].push_back({b[i].y,b[i].z});
			v[b[i].y].push_back({b[i].x,b[i].z});
		}
	}
	dfs(1,0);
	for(int i=1;i<=20;i++){
		for(int j=1;j<=n+m;j++){
			fa[j][i]=fa[fa[j][i-1]][i-1];
			dis[j][i]=dis[j][i-1]+dis[fa[j][i-1]][i-1];
		}
	}
	while(q--){
		cin>>x>>y;
		ans=w[x]+w[y]+lca(x,y);
		cout<<ans<<"\n";
	}
	return 0;
}