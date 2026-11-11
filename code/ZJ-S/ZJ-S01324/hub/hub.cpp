#include<bits/stdc++.h>
#define int long long
using namespace std;
int us[2000010],res;
bool vs[2000010],nt[2000010];
vector<int> g[2000010];
void dfs(int x){
	for(int v:g[x]){
		if(vs[v]||!nt[v])continue;
		vs[v]=1;
		dfs(v);
	}
}
int ds(int x){
	if(us[x]!=0x3f3f3f3f3f3f3f3f)return us[x];
	for(int v:g[x]){
		if(vs[v])continue;
		ds(v);
		vs[x]=1;
		us[x]=min(us[x],us[v]+1);
	}
	return us[x];
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int a,b;
	cin>>a>>b;
	while(b--){
		int n,k;
		cin>>n>>k;
		for(int i=1,u,v;i<n;++i){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int ans=1e18;
		for(int p=0;p<(1<<n)-1;++p){
			int m=0;
			for(int i=1;i<=n;++i){
				if(p&(1<<i-1)){
					++m;
					nt[i]=1;
				}
			}
			if(m!=k)continue;
			int num=0;
			for(int i=1;i<=n;++i){
				if(!vs[i]&&nt[i])vs[i]=1,dfs(i),++num;
				if(num>2)break;
			}
			if(num>2)continue;
			memset(vs,0,sizeof vs);
			memset(us,0x3f,sizeof us);
			for(int i=1;i<=n;++i){
				if(!nt[i]){
					ds(i);
					res=us[i];
					ans=min(ans,res);
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

