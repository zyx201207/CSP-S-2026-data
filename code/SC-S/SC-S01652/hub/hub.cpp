#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;
const int N=5e5+5,mod=998244353;
int c,T,n,k,u[N],v[N],fa[N],minv,dep[N];
bool vis[N];
vector<int> edge[N];

inline int findset(int k){
	if(fa[k]==k) return k;
	return fa[k]=findset(fa[k]);
}

inline void dfs(int root,int fa){
	if(vis[root]) minv=min(minv,dep[root]);
	for(auto i:edge[root]){
		if(i==fa) continue;
		dep[i]=dep[root]+1;
		dfs(i,root);
	}
}

inline void solve1(){
	int answer=100000;
	for(int i=0;i<(1<<n);i++){
		for(int j=1;j<=n;j++){
			vis[j]=false;
			fa[j]=j;
		}
		int num=0;
		for(int j=0;j<n;j++){
			if((1<<j)&i){
				vis[j+1]=true;
				num++;
			}
		}
		if(num!=k){
			continue;
		}
		// vis 选进来的点集合
		for(int j=1;j<n;j++){
			if(vis[u[j]]&&vis[v[j]]){
				int fx=findset(u[j]),fy=findset(v[j]);
				if(fx!=fy){
					fa[fx]=fy;
					num--;
				}
			}
		}
		if(num<=2){
			int maxv=0;
			for(int j=1;j<=n;j++){
				for(int p=1;p<=n;p++){
					dep[p]=0;
				}
				minv=100000;
				dfs(j,0);
				maxv=max(maxv,minv);
			}
			answer=min(answer,maxv);
		}
	}
	printf("%d\n",answer);
}

inline void get_ans(int root,int father){
	for(auto i:edge[root]){
		if(i==father) continue;
		dep[i]=dep[root]+1;
		fa[i]=root;
		get_ans(i,root);
	}
}

inline void solve2(){
	for(int i=1;i<=n;i++){
		dep[i]=0;
	}
	get_ans(1,0);
	int maxval=-10000,node=-1;
	for(int i=1;i<=n;i++){
		if(dep[i]>maxval){
			maxval=dep[i];
			node=i;
		}
	}
	for(int i=1;i<=n;i++){
		dep[i]=0,fa[i]=0;
	}
	get_ans(node,0);
	maxval=-100000,node=-1;
	for(int i=1;i<=n;i++){
		if(dep[i]>maxval){
			maxval=dep[i];
			node=i;
		}
	}
	for(int i=1;i<=maxval/3;i++){
		node=fa[node];
	}
	int k1=0,k2=0,answer=0;
	k1=node;
	for(int i=1;i<=maxval/3+(maxval%3!=0);i++){
		node=fa[node];
	}
	k2=node;
	for(int i=1;i<=n;i++){
		dep[i]=0;
	}	
	get_ans(k1,0);
	for(int i=1;i<=n;i++){
		answer=max(answer,dep[i]);
		dep[i]=0;
	}
	get_ans(k2,0);
	for(int i=1;i<=n;i++){
		answer=max(answer,dep[i]);
		dep[i]=0;
	}
	printf("%d\n",answer);
}

inline void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		edge[i].clear();
	for(int i=1;i<n;i++){
		scanf("%d%d",&u[i],&v[i]);
		edge[u[i]].push_back(v[i]);
		edge[v[i]].push_back(u[i]);		
	}
	if(n<=10){
		solve1();
	} else{
		if(k==2){
			solve2();
		}
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		solve();
	}
	return 0;
} 