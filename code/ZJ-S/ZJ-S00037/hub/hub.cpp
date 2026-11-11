#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int>edge[20];
bool vis[20];
int n,cnt2,dis[20];
void dfs(int x,int fa,int bin){
	if(!((bin>>(x-1))&1)){
		return;
	}
	vis[x]=true;
	cnt2++;
	for(int i=0;i<edge[x].size();i++){
		if(edge[x][i]==fa){
			continue;
		}
		dfs(edge[x][i],x,bin);
	}
}
void dfs2(int x,int fa,int d){
	dis[x]=min(dis[x],d);
	for(int i=0;i<edge[x].size();i++){
		if(edge[x][i]==fa){
			continue;
		}
		dfs2(edge[x][i],x,d+1);
	}
}
int solve(int bin){
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		if((bin>>(i-1))&1){
			dfs2(i,0,0);
		}
	}
	int ret=0;
	for(int i=1;i<=n;i++){
		ret=max(ret,dis[i]);
	}
	return ret;
}
int main(){
	// freopen("E:\\down\\hub\\hub1.in","r",stdin);
	// freopen("E:\\down\\hub\\hub1.out","w",stdout);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			edge[i].clear();
		}
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		int ans=n;
		for(int i=0;i<(1<<n);i++){
			int cnt=0,tmp;
			for(int j=1;j<=n;j++){
				if((i>>(j-1))&1){
					cnt++;
					tmp=j;
				}
			}
			if(cnt==k){
				cnt2=0;
				memset(vis,false,sizeof(vis));
				dfs(tmp,0,i);
				if(cnt2==k){
					ans=min(ans,solve(i));
				}else{
					for(int j=1;j<=n;j++){
						if(((i>>(j-1))&1)&&!vis[j]){
							dfs(j,0,i);
							break;
						}
					}
					if(cnt2==k){
						ans=min(ans,solve(i));
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}