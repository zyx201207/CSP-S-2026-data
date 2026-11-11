#include<bits/stdc++.h>
#define int long long
#define inf 1e18+7
using namespace std;
int c,t,n,k,fa[15],isky[15],cand,bj;
vector<int> a[15],ky;
int findf(int x){
	if(fa[x]==x)return x;
	return fa[x]=findf(fa[x]);
}
bool check(int s){
	ky.clear();
	for(int i=1;i<=n;i++)fa[i]=i,isky[i]=0;
	for(int i=1;i<=n;i++){
		if(s&(1<<i-1)){
			ky.push_back(i);
			isky[i]=1;
		}
	}
	for(auto u:ky){
		for(auto v:a[u]){
			if(!isky[v])continue;
			int fu=findf(u),fv=findf(v);
			if(fu!=fv)fa[fu]=fv;
		}
	}
	int res=0;
	for(int i=1;i<=n;i++){
		if(isky[i]&&fa[i]==i)res++;
	}
	return res<=2;
}
void dfs(int u,int fat,int st){
	if(isky[u]){
		cand=min(cand,st);
		return;
	}
	for(auto v:a[u]){
		if(v==fat)continue;
		dfs(v,u,st+1);
	}
	return;
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		int ans=inf;
		for(int i=1;i<=n;i++)a[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		int all=(1<<n)-1;
		for(int i=0;i<=all;i++){
			bj=0;
			int cnt=0;
			for(int j=1;j<=n;j++){
				if(i&(1<<j-1))cnt++;
			}
			if(cnt!=k||!check(i))continue;
			for(int j=1;j<=n;j++){//求j的通勤距离 
				cand=inf;
				dfs(j,0,0);
				bj=max(bj,cand);//通勤半径 
			}
			ans=min(ans,bj);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
6 5
1 2
2 5
4 5
5 3
3 6
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
