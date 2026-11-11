#include<bits/stdc++.h>
#define int long long
#define pair pair<int,int>
#define x first
#define y second
#define p 998244353
#define endl '\n'
using namespace std;
inline void read(int &x){
	x=0;
	char y=getchar();
	int z=1;
	while(y<'0'||y>'9'){
		if(y=='-'){
			z=-1;
		}
		y=getchar();
	}
	while(y>='0'&&y<='9'){
		x=(x<<1)+(x<<3)+y-'0';
		y=getchar();
	}
	x*=z;
}
int id,t,n,m,fa[1000006],vis[1000006],sh[1000006],s[1000006],mx[1000006][2],dp[1000006],he[1000006],wc[1000006],ans;
vector<int> a[1000006];
pair b[1000006];
void dfs1(int x,int y){
	if(x==0){
		return;
	}
	vis[x]=y;
	sh[x]=0;
	mx[x][0]=mx[x][1]=0;
	wc[x]=0;
	dp[x]=0;
	for(int i:a[x]){
		if(vis[i]!=0){
			continue;
		}
		fa[i]=x;
		dfs1(i,y);
		sh[x]=max(sh[x],sh[i]+1);
		if(sh[i]+1>dp[x]){
			wc[x]=i;
		}
		sh[x]=max(sh[x],sh[i]+1);
		if(sh[i]>sh[mx[x][0]]){
			mx[x][1]=mx[x][0];
			mx[x][0]=i;
		}
		else if(sh[i]>sh[mx[x][1]]){
			mx[x][1]=i;
		}
		if(dp[i]>dp[x]){
			wc[x]=i;
		}
		dp[x]=max(dp[x],dp[i]);
	}
	if(mx[x][1]!=0&&sh[mx[x][0]]+sh[mx[x][1]]+2>dp[x]){
		wc[x]=mx[x][0];
	}
	if(mx[x][1]!=0){
		dp[x]=max(dp[x],sh[mx[x][0]]+sh[mx[x][1]]+2);
	}
}
void qiu(int x,int y){
	for(int i=1;i<=n;i++){
		he[i]=0;
		vis[i]=0;
		fa[i]=0;
		wc[i]=0;
	}
	vis[x]=1;
	vis[y]=2;
	dfs1(x,1);
	dfs1(y,2);
	int u=x,v=y;
	while(wc[u]!=0){
		u=wc[u];
	}
	while(wc[v]!=0){
		v=wc[v];
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1){
			vis[i]=0;
		}
	}
	dfs1(u,1);
	for(int i=1;i<=n;i++){
		if(vis[i]==2){
			vis[i]=0;
		}
	}
	dfs1(v,2);
	int h=sh[u]/2,g=sh[v]/2;
	while(h!=0){
		u=wc[u];
		h--;
	}
	while(g!=0){
		v=wc[v];
		g--;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1){
			vis[i]=0;
		}
	}
	dfs1(u,1);
	for(int i=1;i<=n;i++){
		if(vis[i]==2){
			vis[i]=0;
		}
	}
	dfs1(v,2);
	int now=m-2;
	for(int i=1;i<=n;i++){
		if(i==u||i==v){
			continue;
		}
		he[sh[i]+1]++;
	}
	for(int i=n;i>=0;i--){
		if(now<he[i]){
			ans=min(ans,i);
			break;
		}
		now-=he[i];
	}
}
void dfs(int x){
	for(int i:a[x]){
		if(fa[x]==i){
			continue;
		}
		fa[i]=x;
		dfs(i);
	}
}
void sol(){
	read(n);
	read(m);
	for(int i=1;i<=n;i++){
		fa[i]=0;
		a[i].clear();
	}
	for(int i=1;i<n;i++){
		int x,y;
		read(x);
		read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	if(n==m){
		cout<<0<<endl;
		return;
	}
	dfs(1);
	ans=(int)1e18;
	for(int i=1;i<=n;i++){
		b[i].x=i;
		b[i].y=fa[i];
	}
	for(int i=1;i<=n;i++){
		qiu(b[i].x,b[i].y);
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	read(id);
	read(t);
	for(int i=1;i<=t;i++){
		sol();
	}
}
