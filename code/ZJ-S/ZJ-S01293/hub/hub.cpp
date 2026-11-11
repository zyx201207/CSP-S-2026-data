#include<bits/stdc++.h>
using namespace std;
const int N=15,INF=1e9;

int c,T,n,k,ans;
bool mk[N];
vector<int> g[N];

void clear(){
	for (int i=1;i<=n;i++)  g[i].clear();
	ans=INF;
}

bool used(int s,int i){
	return (s>>(i-1))&1;
}

int cnt(int x){
	int res=0;
	while (x>0){
		if (x&1)  res++;
		x>>=1;
	}
	return res;
}

void mark(int u,int p,int s){
	mk[u]=true;
	for (auto v:g[u]){
		if (v==p || !used(s,v))  continue;
		mark(v,u,s);
	}
}

bool sol(int s){
	if (cnt(s)!=k)  return false;
	int num=0;
	memset(mk,false,sizeof(mk));
	for (int i=1;i<=n;i++){
		if (used(s,i) && !mk[i]){
			if (++num>2)  break;
			mark(i,0,s);
		}
	}
	if (num>2)  return false;
	return true;
}

int dfs(int u,int p,int s){
	if (used(s,u))  return 0;
	int res=INF;
	for (auto v:g[u]){
		if (v==p)  continue;
		res=min(res,dfs(v,u,s));
	}
	return res+1;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	if (c<=3){
		while (T--){
			cin>>n>>k;
			clear();
			for (int i=1;i<n;i++){
				int u,v;
				cin>>u>>v;
				g[u].push_back(v);
				g[v].push_back(u);
			}
			for (int i=0;i<(1<<n);i++){
				if (!sol(i))  continue;
				int res=0;
				for (int j=1;j<=n;j++){
					res=max(res,dfs(j,0,i));
				}
				ans=min(ans,res);
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}