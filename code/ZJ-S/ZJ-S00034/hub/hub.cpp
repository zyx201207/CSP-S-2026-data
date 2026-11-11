#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,dep[505],u[505],v[505],fa[505],book[505],books[505],mp[505][505],minn=0x3f3f3f3f3f3f3f3f;
vector<int>G[505];
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=x;
}
void merge(int a,int b){
	int x=find(a),y=find(b);
	if(x!=y){
		fa[y]=x;
	}
}
int count(){
	memset(books,0,sizeof(books));
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=n;i++){
		if(book[i]&&book[fa[i]]){
			merge(i,fa[i]);
		}
	}
	for(int i=1;i<=n;i++){
		if(book[i]){
			books[fa[i]]=1;
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++) cnt+=books[i];
	if(cnt>2) return 0x3f3f3f3f3f3f3f3f;
	int ans=0;
	for(int i=1;i<=n;i++){
		int now=0x3f3f3f3f3f3f3f3f;
		for(int j=1;j<=n;j++){
			if(book[j]) now=min(now,mp[i][j]);
		}
		ans=max(ans,now);
	}
	return ans;
}
void dfss(int step,int sum){
	if(sum>k||n-step+1+sum<k) return ;
	if(step==n+1){
		if(sum==k){
			minn=min(minn,count());
		}
		return ;
	}
	book[step]=1;
	dfss(step+1,sum+1);
	book[step]=0;
	dfss(step+1,sum);
}
void dfs(int now,int fa){
	dep[now]=dep[fa]+1;
	for(int i:G[now]){
		if(i!=fa){
			dfs(i,now);
		}
	}
}
signed maim(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<n;i++){
		cin>>u[i]>>v[i];
		G[u[i]].push_back(v[i]);
		G[v[i]].push_back(u[i]);
		mp[u[i]][v[i]]=1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(mp[i][j]>mp[i][k]+mp[k][j]){
					mp[i][j]=mp[i][k]+mp[k][j];
				}
			}
		}
	}
	dfs(1,0);
	for(int i=1;i<n;i++){
		if(dep[u[i]]>dep[v[i]]){
			fa[u[i]]=v[i];
		}
		else{
			fa[v[i]]=u[i];
		}
	}
	dfss(1,0);
	cout<<minn;
	return 0;
}
