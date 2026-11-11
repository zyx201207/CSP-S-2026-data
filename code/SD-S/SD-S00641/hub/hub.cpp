#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int c,t,n,k,vis[N],viss[N],a[N],ans=1e9,dis[N];
vector<int>E[N];
void ds(int u){
	for(auto v:E[u]){
		if(dis[u]+1<dis[v]){
			dis[v]=dis[u]+1;
			ds(v); 
		}
	}
}
void dd(int u){
	for(auto v:E[u]){
		if(vis[v]&&!viss[v]){
			viss[v]=1;
			dd(v);
		}
	}
}
int tz(){
	int anss=0;
	for(int i=1;i<=k;i++){
		if(!viss[a[i]]){
			viss[a[i]]=1;
			anss++;
			dd(a[i]);
		}
		if(anss>2)return 1e9;
	}
//	cout<<anss<<" ";
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=k;i++){
		dis[a[i]]=0;
		ds(a[i]);
	}
	int asd=0;
	for(int i=1;i<=n;i++){
//		cout<<dis[i]<<" ";
		asd=max(asd,dis[i]);
	}
	return asd;
}
void dfs(int t,int s){
	if(t==0){
		ans=min(ans,tz());
		return ;
	}
	for(int i=s+1;i+t-1<=n;i++){
		vis[i]=1;a[k-t+1]=i;
		dfs(t-1,i);
		vis[i]=0;a[k-t+1]=0;
	}
}
int main(){
//	freopen("hub1.in","r",stdin);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1,u,v;i<n;i++){
			scanf("%d%d",&u,&v);
			E[u].push_back(v);
			E[v].push_back(u);
		}
		dfs(k,0);
		cout<<ans<<"\n";
	}
	return 0;
}
/*
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
*/
