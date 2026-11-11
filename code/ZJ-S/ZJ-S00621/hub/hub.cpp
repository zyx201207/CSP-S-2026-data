#include<bits/stdc++.h>
using namespace std;
vector<int>ed[15];
int count(int x){
	int res=0;
	while(x)x-=(x&-x),res++;
	return res;
}
int dis[15],fa[15];
int find(int x){
	if(fa[x]==x)return fa[x];
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	int c,t;cin>>c>>t;
	while(t--){
		int n,k;cin>>n>>k;
		for(int i=1;i<=n;i++)ed[i].clear();
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			ed[u].push_back(v);
			ed[v].push_back(u);
		}
		int ans=1e9;
		for(int i=1;i<(1<<n);i++){
			if(count(i)!=k)continue;
			queue<int>q;
			for(int j=1;j<=n;j++){
				if((i>>(j-1))&1)dis[j]=0,q.push(j),fa[j]=j;
				else dis[j]=1e9,fa[j]=0;
			}
			for(int i=1;i<=n;i++){
				for(auto x:ed[i]){
					if(find(x)&&find(i))fa[find(x)]=find(i);
				}
			}
			int id1=0,id2=0;
			int res=0;
			for(int i=1;i<=n;i++){
				if(find(i)){
					if(id1==0)id1=find(i);
					else if(find(i)!=id1&&id2==0)id2=find(i);
					else if(find(i)!=id1&&find(i)!=id2)goto end;
				}
			}
			while(!q.empty()){
				int u=q.front();q.pop();
				res=max(res,dis[u]);
				for(auto v:ed[u]){
					if(dis[v]>dis[u]+1){
						dis[v]=dis[u]+1;
						q.push(v);
					}
				}
			}
			//cerr<<i<<' '<<res<<'\n';
			//for(int i=1;i<=n;i++)cerr<<dis[i]<<' ';
			//cerr<<'\n';
			ans=min(res,ans);
			end:;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
__/\__
\    /
/_  _\
  \/
*/
//standard:15pts
//total standard:255pts
//finish at 31/10/26 17:35