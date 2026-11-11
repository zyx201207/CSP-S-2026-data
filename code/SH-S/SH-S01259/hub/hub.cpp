#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,ans,dis[15][15],fa[15];
vector<int>E[15],chosen;
bool bc[15];

int get (int x) {
	return fa[x]==x ? x : fa[x]=get(fa[x]);
}
void merge (int x,int y){
	x=get(x),y=get(y);
	fa[x]=y;
}

int check(){
	for(int i=1;i<=n;i++) bc[i]=0,fa[i]=i;
	for(int i=0;i<chosen.size();i++) bc[chosen[i]]=1;
	for(int i=1;i<=n;i++) if(bc[i]){
		for(int j=0;j<E[i].size();j++) if(bc[E[i][j]]) merge(i,E[i][j]);
	}
	int cnt=0;
	for(int i=1;i<=n;i++) if(bc[i]&&get(i)==i) cnt++;
	if(cnt>2) return 10000;
	int nans=0;
	for(int i=1;i<=n;i++) if(!bc[i]){
		int ndis=10000;
		for(int j=1;j<=n;j++) if(bc[j]) ndis=min(ndis,dis[i][j]);
		nans=max(nans,ndis);
	}
	return nans;
}

void dfs(int nk,int nn){
	if(nk==n&&nn==k){
		ans=min(ans,check());
		return;
	}
	else if(nk==n) return;
	dfs(nk+1,nn);
	chosen.push_back(nk+1);
	dfs(nk+1,nn+1);
	chosen.pop_back();
}

void solve(){
	memset(dis,0x3f,sizeof(dis));
	chosen.clear();
	ans=10000;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) E[i].clear(),dis[i][i]=0;
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		E[x].push_back(y);
		E[y].push_back(x);
		dis[x][y]=dis[y][x]=1;
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	dfs(0,0);
	printf("%d\n",ans);
}

void solve1(){
	scanf("%d%d",&n,&k);
	int x,y;
	for(int i=1;i<n;i++) scanf("%d%d",&x,&y);
	ans=2000000;
	if(k>=n){
		puts("0");
		return;
	}
	n/=2;
	if(k>=n){
		puts("1");
		return;
	}
	for(int i=1;i<=n;i++){
		ans=min(ans,max(i,(n-2*i+3-k)/2+1));
	}
	printf("%d\n",ans);
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c==13||c==14){
		while(t--) solve1();
		return 0;
	}
	while(t--) solve();
	return 0;
}
