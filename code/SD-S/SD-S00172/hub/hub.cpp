#include<bits/stdc++.h>
using namespace std;
int n,a[20],k,c,t,stt,st;
vector<int>g[20];
void dfs(int u,int fa){
	stt|=1<<u-1;
	for(int v:g[u])if(v^fa&&st&(1<<v-1))dfs(v,u);
}
int dfs2(int u,int fa){
	int res=998;
	if(st&(1<<u-1))return 0;
	for(int v:g[u])if(v^fa)res=min(res,dfs2(v,u)+1);
	return res;
}
signed main(){
	freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].emplace_back(v);g[v].emplace_back(u);
		}
		int mmin=99;
		for(st=0;st<1<<n;st++)if(__builtin_popcount(st)==k){
			stt=0;
			dfs(__lg(st&-st)+1,0);
			stt^=st;
			if(stt!=0)dfs(__lg(stt&-stt)+1,0);
			if(stt)continue;
			int mmax=0;
			for(int i=1;i<=n;i++)if(st&(1<<i-1)==0){
				int p=dfs2(i,0);
				mmax=max(mmax,p);
			}
			mmin=min(mmin,mmax);
		}
		cout<<mmin<<endl;
	}
	return 0;
}
/*
You have no egg!
马里亚纳海沟来的皮皮虾没有帮我敲完代码。
18:09 一只滚木从天花板的滚木吊扇上掉了下来，摔断了两根肋骨。
18:14  
*/
