#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> g[1000010];

int maxdep[1000010],dep[1000010],fa[1000010];
int dfn[1000010],tot=1;

void dfs(int x){
	dfn[x]=tot++;
	dep[x]=dep[fa[x]]+1;
	if(g[x].size()==1&&g[x][0]==fa[x]){
		maxdep[x]=dep[x];
		return;
	}
	for(int i:g[x]){
		if(i==fa[x]) continue;
		fa[i]=x;
		dfs(i);
		maxdep[x]=max(maxdep[i],maxdep[x]);
	}
}

bool check(int x,int n){
	int i;
	set<int> s;
	for(i=1;i<=n;i++){
		if(dep[i]>=x&&maxdep[i]-dep[i]>=x){
			s.insert(dfn[i]);
		}
	}
	int lst=-1,cnt=0;
	for(auto it:s){
		if(lst+1==it) cnt++;
	}
	return cnt<=2;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int cc,_;cin>>cc>>_;
	while(_--){
		memset(maxdep,0,sizeof(maxdep));
		tot=1;
		int n,k;cin>>n>>k;
		int i;
		for(i=1;i<=n;i++)g[i].clear();
		for(i=1;i<n;i++){
			int u,v;cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1);
		int l=0,r=maxdep[1];
		while(l<r){
			int mid=(l+r+1)>>1;
			if(check(mid,n)) l=mid;
			else r=mid-1;
		}
		cout<<l<<'\n';
	}
	
	return 0;
}

