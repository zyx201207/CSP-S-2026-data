#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,t,a,w[505],k[505],mn;
struct node{
	vector<pair<int,int>> a;
	bool vis[500005];
}xl[505];
bool vi[500005];
void dfs(int s,int e,int v,int x,int l){
	if(s==e){
		mn=min(mn,v);
		return;
	}
	vi[s]=1;
	for(int i=1;i<=n;i++){
		if(xl[i].vis[s]){
			for(auto u:xl[i].a){
				if(!vi[u.first]){
					if(x==i) dfs(u.first,e,v,i,u.second);
					else dfs(u.first,e,v+u.second+l,i,u.second);
				}
			}
		}
	}
	vi[s]=0;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a>>t;
			xl[i].a.push_back({a,t});
		}
	}
	while(q--){
		int xr,yr;
		cin>>xr>>yr;
		//cout<<dist(xr,yr)+w[yr]; 
		memset(vi,0,sizeof(vi));
		for(int i=1;i<=n;i++){
			if(xl[i].vis[xr]){
				for(auto v:xl[i].a){
					if(v.first==xr){
						dfs(xr,yr,w[xr],i,v.second);
					}
				}
			}
		}
		cout<<mn+w[yr]<<"\n";
	}
	return 0;
}
