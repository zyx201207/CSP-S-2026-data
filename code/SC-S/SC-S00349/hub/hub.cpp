#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int c,T,n,k,tmp,ans,col[maxn],dis[maxn];
vector<int> v[maxn];
void dfs1(int x,int fa){
	for(int i=0;i<v[x].size();i++){
		int y=v[x][i];
		if(y==fa){
			continue;
		}
		dis[y]=min(dis[y],dis[x]+1);
		dfs1(y,x);
	}
	return;
} 
int check(){
	tmp=0;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		if(col[i]){
			dis[i]=0;
			dfs1(i,0);
		}
	}
	for(int i=1;i<=n;i++){
		tmp=max(tmp,dis[i]);
	}
	return tmp;
}
void dfs(int now,int used){
	if(used==k){
		if(now==n+1){
			ans=min(ans,check());
		}
		return;
	}
	if(now==n+1){
		return;
	}
	col[now]=1;
	dfs(now+1,used+1);
	col[now]=0;
	dfs(now+1,used);
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >>c >>T;
	while(T--){
		ans=INT_MAX;
		cin >>n >>k;
		for(int i=1;i<=n-1;i++){
			int x,y;
			cin >>x >>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(1,0);
		cout <<ans <<"\n";
	}
	return 0;
}
/*
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
关注luogu 893382
100+92+8+5=205
*/