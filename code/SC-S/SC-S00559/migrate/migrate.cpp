#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,c;
int n,d;
int a[2000006];
vector<int>g[2000006];
int dis[5005],cnt[5005],vis[5005];
void dij(int s){
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	memset(cnt,0,sizeof cnt);
	dis[s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	q.push({0,s});
	cnt[s]=1;
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int v:g[x]){
			if(dis[v]>dis[x]+1){
				dis[v]=dis[x]+1;
				cnt[v]=cnt[x];
				q.push({dis[v],v});
			}else if(dis[v]==dis[x]+1){
				cnt[v]+=cnt[x];
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				if(abs(a[i]-a[j])<=d){
					g[i].push_back(j);
				}
			}
		}
		int ct=0;
		for(int i=1;i<=n;i++){
			dij(i);
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2){
					ct++;
				}
			}
		}
		cout<<ct<<endl;
	}
	return 0;
}