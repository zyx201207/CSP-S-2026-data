#include<bits/stdc++.h>

using namespace std;

#define int long long

mt19937_64 rdm(time(0));

const int N=15,inf=1e18;

int n,k;

vector<int>e[N];

int fa[N],dep[N],ans=inf,IS[N],son[N];

void dfs1(int x,int lst){
	fa[x]=lst;
	for(auto i:e[x]){
		if(i==lst) continue;
		dep[i]=dep[x]+1;
		dfs1(i,x);
	}
}

int dis(int u,int v){
	int tot=0;
	if(dep[u]<dep[v]) swap(u,v);
	while(dep[u]>dep[v]){
		u=fa[u];
		tot++;
	}
	while(u!=v){
		u=fa[u];
		v=fa[v];
		tot+=2;
	}
	return tot;
}

void dfs(int x,int sum){
	if(sum>k) return ;
	if(x>n&&sum!=k) return ;
	if(x>n&&sum==k){
		for(int i=1;i<=n;i++){
			son[i]=0;
		}
		for(int i=1;i<=n;i++){
			if(IS[fa[i]]) son[i]++;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(IS[i]&&son[i]==0) cnt++;
		}
		if(cnt>2) return ;
		int sum=0;
		for(int i=1;i<=n;i++){
			int tmp=inf;
			if(IS[i]) continue;
			for(int j=1;j<=n;j++){
				if(IS[j]) tmp=min(tmp,dis(i,j));
			}
			sum=max(sum,tmp);
		}
		ans=min(ans,sum);
//		cout<<sum<<endl;
//		for(int i=1;i<=n;i++){
//			cout<<IS[i]<<' ';
//		}
//		cout<<endl;
		return ;
	}
	dfs(x+1,sum);
	IS[x]=1;
	dfs(x+1,sum+1);
	IS[x]=0;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			e[i].clear();
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		ans=inf;
		dfs1(1,0);
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}

