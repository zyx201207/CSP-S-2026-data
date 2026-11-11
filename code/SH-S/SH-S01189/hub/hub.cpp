#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int ret=0,w=1;
	char c=getchar();
	while(c<'0'||c>'9'){ 
		if(c=='-')w=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		ret=ret*10+c-'0';
		c=getchar();
	}
	return w*ret;
}
void write(long long x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
const int N=2000015;
int c,n,k,t;
vector<int>e[N];
bool vis[N];
int tmp=0;
void dfs(int u,int fa,int dep){
	if(vis[u])return;
	tmp=max(tmp,dep);
	for(auto j:e[u]){
		if(j==fa)continue;
		dfs(j,u,dep);
	}
}
bool vvis[N];
int cc=0;
void dfs_col(int u,int fa){
	if(!vis[u])return;
	vis[u]=0;
	for(auto j:e[u]){
		if(j==fa)continue;
		dfs_col(j,u);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),k=read();
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<n;i++){
			int a=read(),b=read();
			e[a].push_back(b),e[b].push_back(a);
		}
		int ans=1e9;
		for(int i=0;i<1<<n;i++){
			int cnt=0;
			for(int j=0;j<n;j++){
				if(i>>j&1)cnt++;
			}
			if(cnt!=k)continue;
			cc=0;
			for(int j=1;j<=n;j++){ 
				if(vis[j])cc++,dfs_col(j,-1);
			}
			if(cc!=k)continue; 
			for(int j=1;j<=n;j++){
				vis[j]=0;
			}
			for(int j=0;j<n;j++){ 
				if(i>>j&1)vis[j+1]=1;
			}
			tmp=0;
			for(int j=1;j<=n;j++){
				dfs(i,-1,0);
			}
			ans=min(ans,tmp);
		}
		write(ans),putchar('\n');
	}
	return 0;
}
