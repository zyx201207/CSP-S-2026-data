#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n,k,c,t,vis[50],ret=1e9;
vector<int>g[2010];
void dfs(int idx,int x){
	for(int v:g[x]){
		if(!vis[v]&&(idx&(1<<(v-1)))){
			vis[v]=1;
			dfs(idx,v);
		}
	}
}
signed main(){
	ios
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ret=1e9;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		for(int i=1;i<(1<<n);i++){
			int cnt=0;
			for(int j=1;j<=n;j++)if(i&(1<<(j-1)))++cnt;
			if(cnt!=k)continue;
			memset(vis,0,sizeof vis);
			int lia=0;
			for(int j=1;j<=n;j++){
				if(i&(1<<(j-1))){
					if(!vis[j]){
						++lia;
						vis[j]=1;
						dfs(i,j);
					}
				}
			}
			if(lia>2)continue;
			int res=0;
			for(int j=1;j<=n;j++){
				if(i&(1<<(j-1)))continue;
				queue<int>q;
				q.push(j);
				memset(vis,0,sizeof vis);
				vis[j]=1;
				int ans=-1;
				while(!q.empty()){
					int x=q.front();
					q.pop();
					if(i&(1<<(x-1))){
						ans+=vis[x];
						break;
					}
					for(int v:g[x]){
						if(!vis[v]){
							vis[v]=vis[x]+1;
							q.push(v);
						}
					}
				}
				res=max(res,ans);
			}
//			for(int I=1;I<=n;I++){
//				if(i&(1<<(I-1)))cout<<1;
//				else cout<<0;
//			}
//			cout<<"___"<<res<<"----"<<lia<<"\n";
			ret=min(ret,res);
		}
		cout<<ret<<"\n";
		for(int i=1;i<=n;i++)g[i].clear();
	}
	return 0;
}
