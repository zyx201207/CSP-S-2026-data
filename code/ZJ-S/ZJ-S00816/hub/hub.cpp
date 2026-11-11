#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,T,n,k,u,v,d[N],f[N][25],ans;
vector<int>g[N];
void dfs(int nw,int fa){
	f[nw][0]=fa;
	for(int i=1;i<21;i++)f[nw][i]=f[f[nw][i-1]][i-1];
	d[nw]=d[fa]+1;
	for(auto i:g[nw]){
		if(i==fa)continue;
		dfs(i,nw);
	}
}
int fd(int x,int y){
	if(d[x]<d[y])swap(x,y);
	for(int i=20;i>=0;i--){
		if(d[f[x][i]]>d[y])x=f[x][i];
	}
	x=f[x][0];
	if(x==y)return x;
	for(int i=20;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
bool is[N],vis[N];
int q[N],l;
void ch(int nw){
	if(vis[nw])return;
	vis[nw]=1;
	for(auto i:g[nw]){
		ch(i);
	}
}
bool check(){
	for(int i=1;i<=n;i++){
		if(!is[i])vis[i]=1;
		else vis[i]=0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			if(cnt==2)return 0;
			ch(i);
			cnt++;
		}
	}
	return 1;
}
void sol(int nw,int num){
	if(n-nw+1<num||!check())return;
	if(num==0){
		if(check()){
			int mx=0;
			for(int i=1;i<=n;i++){
				if(is[i])continue;
				int mn=1e9;
				for(int j=1;j<=k;j++){
					mn=min(mn,d[i]+d[q[j]]-d[fd(i,q[j])]*2);
				}
				mx=max(mx,mn);
			}
			ans=min(ans,mx);
		}
		return;
	}
	for(int i=nw;i<=n;i++){
		is[i]=1;
		q[++l]=i;
		sol(i+1,num-1);
		is[i]=0;
		l--;
	}
}
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		ans=n+1;
		dfs(1,0);
		sol(1,k);
		cout<<ans<<'\n';
	}
	return 0;
}
