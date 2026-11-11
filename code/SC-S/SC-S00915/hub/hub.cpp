#include<bits/stdc++.h>
#define N 1000005
using namespace std;
vector<int> e[N];
int fa[N],dep[N],lst[N];
int getfa(int x){
	if(fa[x]==x)return x;
	return fa[x]=getfa(fa[x]);
}
void dfs(int u,int f){
	dep[u]=dep[f]+1;
	lst[u]=f;
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if(v==f)continue;
		dfs(v,u);
	}
}
int dist(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	int dis=0;
	while(dep[u]!=dep[v]){
		dis++;
		u=lst[u];
	}
	while(u!=v){
		dis+=2;
		u=lst[u];
		v=lst[v];
	}
	return dis;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1,0);
		if(n<=10){
			int Ans=1e9;
			for(int S=0;S<(1<<n);S++){
				int cnt=0;
				for(int i=1;i<=n;i++){
					fa[i]=i;
					if(S&(1<<(i-1)))cnt++;
				}
				if(cnt!=k)continue;
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						if(i==j)continue;
						if((S&(1<<(i-1)))&&(S&(1<<(j-1)))){
							bool flag=false;
							for(int k=0;k<e[i].size();k++)if(e[i][k]==j)flag=true;
							if(flag){
								int fx=getfa(i);
								int fy=getfa(j);
								if(fx!=fy)fa[fx]=fy;
							}
						}
					}
				}
				cnt=0;
				for(int i=1;i<=n;i++){
					if(S&(1<<(i-1))){
						if(fa[i]==i)cnt++;
					}
				}
				if(cnt>2)continue;
				int ans=0;
				for(int i=1;i<=n;i++){
					if(S&(1<<(i-1)))continue;
					int tot=1e9;
					for(int j=1;j<=n;j++){
						if(S&(1<<(j-1)))tot=min(tot,dist(i,j));
					}
					ans=max(ans,tot);
				}
				Ans=min(Ans,ans);
			}
			cout<<Ans<<"\n";
		}
	}
	return 0;
}