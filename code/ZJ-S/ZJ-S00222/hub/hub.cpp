#include<bits/stdc++.h>
using namespace std;
int c,T,ans,n,book[10005],cnt,go[10005][10005],k,vis[10005];
vector<int>ed[10005];
inline int read(){
	int k=0,f=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-f;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k<<3+k<<1+c-'0';
		c=getchar();
	}
	return k*f;
}
void floyd(){
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				go[i][j]=min(go[i][j],go[i][k]+go[k][j]);
			}
		}
	}
}
void ddfs(int x){
	for(int i=0;i<ed[x].size();++i){
		int v=ed[x][i];
		if(!vis[v]){
			vis[v]=1;
			ddfs(v);
		}
	}
}
bool ck(){
	int ct=0;
	for(int i=1;i<=n;++i){
		vis[i]=!book[i];
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			vis[i]=1;
			++ct;
			ddfs(i);
		}
	}
	return ct<=2;
}
void check(){
	int ma=0;
	if(!ck()){
		return;
	}
	for(int i=1;i<=n;++i){
		if(book[i]){
			continue;
		}
		int mi=n-2;
		for(int j=1;j<=n;++j){
			if(!book[j]){
				continue;
			}
			mi=min(mi,go[i][j]);
		}
		ma=max(ma,mi);
	}
	ans=min(ans,ma);
}
void dfs(int x){
	if(cnt>k){
		return;
	}
	if(x==n+1&&cnt==k){
		check();
		return;
	}else if(x==n+1){
		return;
	}
	dfs(x+1);
	book[x]=1;
	++cnt;
	dfs(x+1);
	book[x]=0;
	--cnt;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;++i){
			ed[i].clear();
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				go[i][j]=(i==j?0:n-1);
			}
		}
		for(int i=1;i<n;++i){
			int u,v;
			cin>>u>>v;
			ed[u].push_back(v);
			ed[v].push_back(u);
			go[u][v]=go[v][u]=1;
		}
		floyd();
		ans=n-2;
		dfs(1);
		cout<<ans<<'\n';
	}
}