#include<bits/stdc++.h>
#define ll long long
using namespace std;const int N=1e6+6;
int C,T,n,k,f[N],d[N],u,v,ans;vector<int>e[N];
queue<int>q;
void dfs1(int u){
	f[u]++;
	for(int o=0;o<e[u].size();o++)
		if(f[e[u][o]]==1)dfs1(e[u][o]);
}bool check(){int cnt=0;
	for(int i=1;i<=n;i++){
		if(f[i]==1)dfs1(i),cnt++;
	}return cnt<=2;
}void bfs(){int re=0;
	while(q.size()){
		int u=q.front();
		q.pop();re=max(re,d[u]);
		for(int o=0;o<e[u].size();o++)
			if(d[e[u][o]]>d[u]+1)q.push(e[u][o]),d[e[u][o]]=d[u]+1;
	}ans=min(ans,re);
}void F(int k){
	if(!k&&check()){memset(d,0x3f,sizeof(d));
		for(int i=1;i<=n;i++)if(f[i])q.push(i),d[i]=0;
		bfs();return;
	}for(int i=1;i<=n;i++)if(!f[i]){
		f[i]=1;F(k-1);
	}
}
int main(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
	cin>>C>>T;while(T--){ans=0x3f3f3f3f;
		cin>>n>>k;for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<n;i++)cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
		F(k);
	}
	return 0;
}
