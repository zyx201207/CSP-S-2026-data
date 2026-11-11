#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>v[N];
int c,t,n,k,cun[N];
bool vis[N];
bool check(){
	//检查联通块个数
	int sum=0;
	for(int i=1;i<=k;i++){
		bool if1=0;
		for(int j=1;j<i;j++){
			if(v[cun[i]][0]==cun[j]){
				if1=1;
				break;
			}
		}
		if(!if1)sum++;
		if(sum>2)return 0;
	} 
	return 1;
}
int ans=INT_MAX;
int fa[N][20],dep[N];
void dfs1(int now,int f){
	fa[now][0]=f;
	dep[now]=dep[f]+1;
	for(int i=1;i<=20;i++){
		fa[now][i]=fa[fa[now][i-1]][i-1];
	}
	for(int i=0;i<v[now].size();i++){
		int to=v[now][i];
		if(to==f)continue;
		dfs1(to,now);
	}
}
int lca(int a,int b){
	if(dep[a]<dep[b])swap(a,b);
	int len=dep[a]-dep[b];
	for(int i=0;i<=20;i++){
		if(len>>i&1)a=fa[a][i];
	}
	if(a==b)return a;
	for(int i=20;i>=0;i--){
		if(fa[a][i]==fa[b][i])continue;
		a=fa[a][i];
		b=fa[b][i];
	}
	return fa[a][0];
}
void dfs(int x){
	if(x==k+1){
		int sum1=0;
		for(int i=1;i<=n;i++){
			int sum=INT_MAX;
			for(int j=1;j<=k;j++){
				int len=dep[i]+dep[cun[j]]-(2*dep[lca(i,cun[j])]);
				sum=min(sum,len);
			}
			sum1=max(sum1,sum);
		}
		ans=min(ans,sum1);
		return;
	}
	for(int i=cun[x-1]+1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		cun[x]=i;
		dfs(x+1);
		vis[i]=0;
		cun[x]=0;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		//多测清空
		cin>>n>>k;
		for(int i=1;i<=n;i++)v[i].clear();
		memset(fa,0,sizeof fa);
		memset(dep,0,sizeof dep);
		memset(cun,0,sizeof cun);
		memset(vis,0,sizeof vis);
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs1(1,0);
		dfs(1);
		cout<<ans<<'\n';
		ans=INT_MAX;
	}
	return 0;
}
