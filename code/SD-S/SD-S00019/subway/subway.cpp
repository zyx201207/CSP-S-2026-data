//44pts
#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*====================*/
const int N=1e5+10;
const int INF=0x3f3f3f3f;
/*====================*/
ll c,n,m,d,q,ans,st,tim;
ll w[N],dx[N],dy[N],dst[505];
vector<pair<ll,ll>>to[N];//第 i个站点都有哪几条线 ，对应时间 
ll trans[505][505],vis[505][505];//第i条线到第j条线的最短时间 
/*====================*/
void dfs(ll x){
	if(dy[x]){
		ans=min(ans,dst[x]+tim+dy[x]);
		//cout<<dst[x]<<" ";
		return;
	}
	for(int i=1;i<=n;i++){
		if(x==i||vis[i][x]==1||trans[i][x]==INF)continue;
		vis[x][i]=vis[i][x]=1;
		if(dst[i]<=dst[x]+trans[x][i]){
			continue;
		}
		//cout<<x<<" ";
		dst[i]=dst[x]+trans[x][i];
		dfs(i);
	}
}
/*====================*/
void Solve(void){
	memset(trans,INF,sizeof trans);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		ll k,a,t;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			to[a].push_back({i,t});
			for(auto kk:to[a]){
				if(kk.first==i)continue;
				trans[i][kk.first]=trans[kk.first][i]=min(trans[i][kk.first],kk.second+t);
				//if(i==3&&kk.first==1)cout<<a<<" ";
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<trans[i][j]<<' '; 
		}
		cout<<"\n";
	}*/
	while(q--){
		memset(dy,0,sizeof dy);
		ll u,v;
		cin>>u>>v;
		ans=INF;
		for(auto k:to[v]){
			dy[k.first]=k.second;
		}for(auto k:to[u]){
			memset(vis,0,sizeof vis);
			memset(dst,INF,sizeof dst);
			dst[k.first]=0;
			st=k.first;tim=k.second;
			dfs(k.first);
		}
		//cout<<ans<<"\n";
		cout<<ans+w[u]+w[v]<<"\n";
	}
}
/*====================*/
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	ll T=1;//cin>>T;
	while(T--){
		Solve();
	}
	return 0;
}
//这题咋做？
//有点思路好像
//试试 
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
