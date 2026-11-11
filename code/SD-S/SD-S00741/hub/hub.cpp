#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,vis[35],cnt,sum,jv,x,y,ans;
vector<int> a[35];
void df(int u,int fa){
	if(vis[u])sum++;
	for(int v:a[u]){
		if(v!=fa){
			if(vis[u]&&vis[v])cnt++;
			df(v,u);
		}
	}
}
void dff(int u,int fa,int st){
	if(vis[u]){
		jv=min(jv,st);
	}
	for(int v:a[u]){
		if(v!=fa){
			dff(v,u,st+1);
		}
	}
}
void dfs(int step){
	if(step==n+1){
		cnt=sum=0;
		df(1,0);
		if(sum-cnt>2||sum!=k){
			return ;
		}
//		for(int i=1;i<=n;i++){
//			cout<<vis[i]<<' ';
//		}
//		cout<<'\n';
		int cnn=0;
		for(int i=1;i<=n;i++){
			jv=1e9;
			dff(i,0,0);
			cnn=max(cnn,jv);
		}
//		cout<<cnn<<'\n';
		ans=min(ans,cnn);
		return ;
	}
	vis[step]=0;
	dfs(step+1);
	vis[step]=1;
	dfs(step+1);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			a[i].clear();
		}
		ans=1e9;
		for(int i=1;i<n;i++){
			cin>>x>>y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		dfs(1);
		cout<<ans<<'\n';
	}
	return 0;
}

