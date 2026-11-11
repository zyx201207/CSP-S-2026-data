#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+7;
int c,T;
int n,k;
int mp[305][305];
bool ans[305];
bool vis[305];
void dfs(int u){
	for(int i=1;i<=n;i++){
		if(!vis[i]&&mp[u][i]==1&&ans[i]){
			vis[i]=1;
			dfs(i);
		}
	}
}
bool check(){
	int cnt=0;
	for(int i=1;i<=n;i++)vis[i]=0;
	for(int i=1;i<=n;i++){
		if(ans[i]&&!vis[i])dfs(i),cnt++;
	}
//	cout<<cnt<<'\n';
	return cnt<=2;
}
int get(){
	int anss=0;
	for(int i=1;i<=n;i++){
		int tmp=inf;
		if(ans[i])continue;
		for(int j=1;j<=n;j++){
			if(ans[j])tmp=min(tmp,mp[i][j]);
		}
		anss=max(anss,tmp);
	}
	return anss;
}
void run1(){
	int anss=inf;
	for(int i=2;i<(1<<(n+1));i+=2){
		int pc=0;
		for(int j=1;j<=n;j++){
			if(i&(1<<j))ans[j]=1,pc++;
			else ans[j]=0;
		}
		if(pc!=k)continue;
		if(!check())continue;
//		for(int j=1;j<=n;j++)cout<<ans[j]<<' ';
//		cout<<'\n';
		anss=min(anss,get());
	}
	cout<<anss<<'\n';
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			mp[i][j]=mp[j][i]=inf;
		}
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		mp[u][v]=mp[v][u]=1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k)continue;
			for(int j=1;j<=n;j++){
				if(i==j||j==k)continue;
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[j][k]);
			}
		}
	}
	if(c<=3)run1();
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--)solve();
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
