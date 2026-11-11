#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T;
int n,k;
int mk[1000005];
int u,v;
int dis[1000005];
vector<int>q[100005];
//int u[1000005],v[1000005];
int fa[15];
int dfs(int u,int fa,int dep){
//	cerr<<u<<' '<<fa<<' '<<dep<<endl;
//	system("pause");
	dis[u]=min(dis[u],dep);
	for(auto v:q[u]){
		if(v==fa)continue;
		dfs(v,u,dep+1);
	}
	return 0;
}
int find(int x){
//	cerr<<x<<endl;
	if(fa[x]==x){
		return x;
	} 
	return fa[x]=find(fa[x]);
}
int che(){
	if(k>2){
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		for(int i=1;i<=n;i++){
			if(mk[i]==0)continue;
			for(auto j:q[i]){
				if(mk[j]==0)continue;
				int x=find(i);
				int y=find(j);
				if(x==y)continue;
				fa[x]=fa[y];
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(fa[i]==i&&mk[i]){
				cnt++;
			}
		}
		if(cnt>2){
			return 1e9+1;
		}
	}
	for(int i=1;i<=n;i++){
		if(mk[i]==0)dis[i]=1e9;
		else{
			dis[i]=0;
		}
	}
	for(int i=1;i<=n;i++){
		if(mk[i]==0)continue;
		dfs(i,0,0);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,dis[i]);
	}
	return ans;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			mk[i]=0;
			q[i].clear();
		}
		for(int i=1;i<n;i++){
			cin>>u>>v;
			q[u].push_back(v);
			q[v].push_back(u);
		}
		int ans=1e9+2;
		if(k==1){
			for(int i=1;i<=n;i++){
				mk[i]=1;
				ans=min(ans,che());
				mk[i]=0;
			}
		}
		else if(k==2){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j)continue;
					mk[i]=mk[j]=1;
					ans=min(ans,che());
					mk[i]=mk[j]=0;
				}
			}
		}
		else{
			for(int i=0;i<(1<<n)-1;i++){
				int ct=0;
				for(int j=1;j<=n;j++){
					if(i&(1<<(j-1))){
						mk[j]=1;
						ct++;
					}
				}
				if(ct==k)ans=min(ans,che());
//				cout<<i<<endl;
				for(int j=1;j<=n;j++){
					if(i&(1<<(j-1))){
						mk[j]=0;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 1
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9
*/