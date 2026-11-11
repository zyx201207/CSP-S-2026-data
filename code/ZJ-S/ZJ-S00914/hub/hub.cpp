#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int read(){
	int f=1,sum=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		sum=sum*10+ch-'0';
		ch=getchar();
	}
	return f*sum;
}
void print(int x){
	if(x<10){
		putchar('0'+x);
		return ;
	}
	print(x/10);
	putchar(x%10+'0');
}
int C,T,n,k;
int s,ans;
int dep[N],f[N][20];
vector<int> g[N];
bool vis[N];
void dfs(int u,int rt){
	dep[u]=dep[rt]+1;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==rt) continue;
		f[v][0]=u;
		dfs(v,u);
	}
}
void rs(int u){
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(!vis[v]&& (s&(1<<(v-1))) ){
			vis[v]=1;
			rs(v);
		}
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int j=20;j>=0;j--){
		if(dep[f[x][j]]>=dep[y]) x=f[x][j];
	}
	if(x==y) return x;
	for(int j=20;j>=0;j--){
		if(f[x][j]!=f[y][j]){
			x=f[x][j],y=f[y][j];
		}
	}
	return f[x][0];
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	while(T--){
		ans=N;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v),g[v].push_back(u);
		}
		f[1][0]=0;
		dfs(1,0);
		for(int j=1;j<=20;j++){
			for(int i=1;i<=n;i++){
				f[i][j]=f[f[i][j-1]][j-1];
			}
		}
		for(s=0;s<(1<<n);s++){
			int cnt=0;
			bool flag=1;
			for(int i=1;i<=n;i++){
				if( (s&(1<<(i-1))) &&!vis[i]){
					cnt++;
					if(cnt>k){
						flag=0;
						break;
					}
					vis[i]=1;
					rs(i);
				}
			}
			if(!flag) continue;
			int sum=0;
			for(int i=1;i<=n;i++){
				if(s&(1<<(i-1))) continue;
				for(int j=1;j<=n;j++){
					if(s&(1<<(j-1))) continue;
					int fa=lca(i,j);
					sum=max(sum,dep[i]+dep[j]-dep[fa]*2);
				}
			}
			ans=min(ans,sum);
			for(int i=1;i<=n;i++){
				vis[i]=0;
				g[i].clear();
			}
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
	}
	return 0;
}
