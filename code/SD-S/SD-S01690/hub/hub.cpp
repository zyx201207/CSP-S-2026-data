#include<bits/stdc++.h>
using namespace std;
int n,k,vis[20],b[20],lst[20],dep[20],anss=0;
vector<int> v[20];
void dfs(int c){
	vis[c]=1;
	for(auto it:v[c]){
		if(vis[it]==0&&b[it]==1)	dfs(it);
	}
}
void dfs1(int c){
//	cout<<c<<' ';
	for(auto it:v[c]){
		if(it!=lst[c]){
			lst[it]=c,dep[it]=dep[c]+1;
			dfs1(it);
		}
	}
}
int lca(int x,int y){
	int ans=0;
	if(dep[x]<dep[y])	swap(x,y);
	while(dep[x]>dep[y])	x=lst[x],ans++;
	if(x==y)	return ans;
	while(x!=y)	x=lst[x],y=lst[y],ans+=2;
	return ans;
}
void solve(int c,int s){
//	cout<<c<<' ';
	if(c==n+1){
		int f=0,ans1=0;
		if(s!=k)	return;
//		for(int i=1;i<=n;i++)	cout<<b[i]<<' ';
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			if(b[i]==1&&vis[i]==0&&f<2)	f++,dfs(i);
			else if(b[i]==1&&vis[i]==0)	return;
		}
//		for(int i=1;i<=n;i++)	cout<<b[i]<<' ';
		for(int i=1;i<=n;i++){
			int ans=1e9;
			if(b[i]==0){
				for(int j=1;j<=n;j++){
					if(b[j]==1)	ans=min(ans,lca(i,j));
				}
				ans1=max(ans,ans1);
			}
		}
//		cout<<ans1<<'\n';
		anss=min(anss,ans1);
		return;
	}
	b[c]=1;
	if(s<k)	solve(c+1,s+1);
	b[c]=0;
	solve(c+1,s);
}
int main(){
	freopen("hub.in","r",stdin);
  	freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
    	int x,y;
    	anss=1e9;
    	cin>>n>>k;
    	for(int i=1;i<=n;i++){
    		lst[i]=dep[i]=0;
    		v[i].clear();
		}
    	for(int i=1;i<n;i++){
    		cin>>x>>y;
    		v[x].push_back(y);
    		v[y].push_back(x);
		}
		dfs1(1);
    	solve(1,0);
    	cout<<anss<<'\n';
	}
	return 0;
}

