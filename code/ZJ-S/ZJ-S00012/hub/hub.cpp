#include<bits/stdc++.h>
#define int long long
#define inf 1e17
using namespace std;
int c,t,n,k,nw[1000005],b[1000005],ok[1000005],ans=inf,dis[1000005],s[2];
vector<int>e[1000005];
inline void dfs(int i){
	dis[i]=0;
	for(int nxt:e[i]){
		if(!b[nxt]&&ok[nxt]){
			b[nxt]=1;
			dfs(nxt);
		}
	}
	return ;
}
inline void dfss(int i,int ftr){
	for(int nxt:e[i]){
		if(nxt!=ftr){
			if(!ok[nxt]){
				dis[nxt]=min(dis[nxt],dis[i]+1);
			}
			dfss(nxt,i);
		}
	}
	return ;
}
inline void check(){
	for(int i=1;i<=n;i++){
		ok[i]=b[i]=0;
		dis[i]=inf;
	}
	for(int i=1;i<=k;i++){
		ok[nw[i]]=1;
	}
	int l=0;
	for(int i=1;i<=k;i++){
		if(!b[nw[i]]){
			l++;
			if(l==3){
				return ;
			}
			s[l-1]=nw[i];
			b[nw[i]]=1;
			dfs(nw[i]);
		}
	}
	dfss(s[0],0);
	dfss(s[1],0);
	int ret=0;
	for(int i=1;i<=n;i++){
		ret=max(ret,dis[i]);
	}
	ans=min(ans,ret);
	return ;
}
inline void cs(int lst,int cnt){
	if(cnt==k){
		check();
		return ;
	}
	for(int i=lst+1;i<=n;i++){
		nw[cnt+1]=i;
		cs(i,cnt+1);
	}
	return ;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		cs(0,0);
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++){
			e[i].clear();
		}
		ans=inf;
	}
	return 0;
}

