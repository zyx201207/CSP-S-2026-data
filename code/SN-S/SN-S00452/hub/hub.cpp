#include <bits/stdc++.h>
using namespace std;

int ccc,n,K,fa[200005][22],dep[200005],fff[200005],v[200005];
vector<int>e[200005];

int find(int x){
	if(x!=fff[x])fff[x]=find(fff[x]);
	return fff[x];
}

void dfs(int x,int f){
	dep[x]=dep[f]+1;fa[x][0]=f;
	for(int i=1;i<=20;i++)fa[x][i]=fa[fa[x][i-1]][i-1];
	int ss=e[x].size();
	for(int i=0;i<ss;i++){
		if(e[x][i]==f)continue;
		dfs(e[x][i],x);
	}
}

int LCA(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=20;i>=0;i--)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=20;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}

int dis(int x,int y){
	int lca=LCA(x,y);
	int ans=dep[x]+dep[y]-2*dep[lca];
	return ans;
}

void solve(){
	cin>>n>>K;
	for(int i=1;i<=n;i++)e[i].clear();
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1,0);
	int ans=200000;
	for(int i=1;i<(1<<n);i++){
		int sum=0;
		for(int j=0;j<n;j++){
			if((i>>j)&1){
				sum++;
				v[j+1]=1;
			}
			else v[j+1]=0;
		}
		if(sum!=K)continue;
		for(int j=1;j<=n;j++)fff[j]=j;
		for(int j=1;j<=n;j++){
			if(!v[j])continue;
			int ss=e[j].size();
			for(int k=0;k<ss;k++){
				if(v[e[j][k]]){
					int fx=find(j),fy=find(e[j][k]);
					if(fx!=fy)fff[fy]=fx;
				}
			}
		}
		set<int>sss;
		for(int j=1;j<=n;j++)if(v[j])sss.insert(find(j));
		int ssss=sss.size();
		if(ssss>2)continue;
		int bbb=0;
		for(int j=1;j<=n;j++){
			int aaa=200000;
			for(int k=1;k<=n;k++){
				if(!v[k])continue;
				aaa=min(aaa,dis(j,k));
			}
			bbb=max(bbb,aaa);
		}
		ans=min(ans,bbb);
	}
	cout<<ans<<endl;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T;cin>>ccc>>T;
	while(T--)solve();
	
	return 0;
}
