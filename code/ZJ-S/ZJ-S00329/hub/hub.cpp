#include<bits/stdc++.h>
#define ll long long
// #define int ll
using namespace std;
const int N=1e6+100;
const int inf=1e9;
int c,n,m,q,ysc;
int dep[N],siz[N],mxdep[N];
int dp[N][5];
int k;
vector<int>g[N+600];
void add(int u,int v){
	g[u].emplace_back(v);
	return;
}
int d[N],ans[N];
int id[N],col;
int us[N];
void ddfs(int u){
	if(id[u])return;
	if(!us[u])return;
	id[u]=col;
	for(int v:g[u]){
		ddfs(v);
	}
}
int dpfs(int u,int fa,int dep){
	if(us[u]){
		return dep;
	}
	int num=inf;
	for(int v:g[u]){
		if(v==fa)continue;
		num=min(num,dpfs(v,u,dep+1));
	}
	return num;
}
void check(){
	col=0;
	for(int i=1;i<=n;i++)d[i]=inf,id[i]=0,us[i]=0;
	for(int i=1;i<=k;i++)us[ans[i]]=1;
	for(int i=1;i<=k;i++){
		if(id[ans[i]])continue;
		++col;
		ddfs(ans[i]);
	}
	if(col>2)return;
	int num=0;
	for(int i=1;i<=n;i++){
		num=max(num,dpfs(i,0,0));
	}
	ysc=min(ysc,num);
}
void dfs(int dp,int ls){
	if(dp==0){
		check();
		return;
	}
	for(int i=ls+1;i<=n;i++){
		ans[dp]=i;
		dfs(dp-1,i);
	}
}
void solve(){
	ysc=inf;
    cin>>n>>k;
	for(int i=1;i<=n;i++)g[i].clear();
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
	if(k==n){
		cout<<0<<'\n';
		return;
	}
	dfs(k,0);
	cout<<ysc<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    int t;
    cin>>c>>t;
    while(t--)solve();
	return 0;
}
/*
g++ -std=c++14 -O2 -Wall -o hub hub.cpp
time ./hub<hub.in>hub.out
*/