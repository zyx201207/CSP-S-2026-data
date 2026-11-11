#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500001];
map<pair<int,int>,long long>mp;
vector<int>v[501];
vector<int>T[500001];
bool vis[500001];
long long ans=1e18;
void dfs(int sx,int ex,int metro,long long dist,int xx){
	vis[xx]=1;
	if(xx==ex){
		ans=min(ans,dist+mp[{metro,ex}]+w[ex]);
		return ;
	}
	if(xx==sx){
		for(int i=0;i<v[metro].size();i++){
			if(v[metro][i]!=sx){
				dfs(sx,ex,metro,dist,v[metro][i]);
				vis[v[metro][i]]=0;
			}
		}
	}
	else{
		for(int i=0;i<T[xx].size();i++){
			if(T[xx][i]==metro){
				for(int j=0;j<v[metro].size();j++){
					if(!vis[v[metro][j]]){
						dfs(sx,ex,metro,dist,v[metro][j]);
						vis[v[metro][j]]=0;
					}
				}
			}
			else{
				for(int j=0;j<v[T[xx][i]].size();j++){
					if(!vis[v[T[xx][i]][j]]){
						dfs(sx,ex,T[xx][i],dist+mp[{metro,xx}]+mp[{T[xx][i],xx}],v[T[xx][i]][j]);
						vis[v[T[xx][i]][j]]=0;
					}
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	while(cin>>c>>n>>m>>d>>q){
		memset(w,0,sizeof(w));
		ans=1e18;
		mp.clear();
		memset(v,0,sizeof(v));
		memset(T,0,sizeof(T)); 
		for(int i=1;i<=m;i++) cin>>w[i];
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				int a;
				long long t;
				cin>>a>>t;
				v[i].push_back(a);
				T[a].push_back(i);
				mp[{i,a}]=t;
			}
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			for(int i=0;i<T[x].size();i++){
				vis[x]=1;
				dfs(x,y,T[x][i],w[x]+mp[{T[x][i],x}],x);
				memset(vis,0,sizeof(vis));
			}
			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
}
