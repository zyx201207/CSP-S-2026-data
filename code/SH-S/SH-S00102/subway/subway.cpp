#include<bits/stdc++.h>
using namespace std;
struct Node{
	long long a,t;
};
vector<vector<Node>>dt;
vector<vector<int>>xl;
long long c,n,m,d,q,a[500005],vst[500005],sz[1005],vstdt[505];
long long dfs(int u,int v){
	if(u==v)return 0;
	long long ans=1e18;
	for(auto i:xl[u]){
		if(vstdt[i]==0){
			vstdt[i]=1;
			long long tmp=1e18,ud=0;
			for(auto j:dt[i]){
				if(j.a==u){
					ud=j.t;
				}else if(vst[j.a]==0){
					vst[j.a]=1;
					tmp=min(tmp,j.t+dfs(j.a,v));
					vst[j.a]=0;
				}
			}			
			ans=min(ans,tmp+ud);
			vstdt[i]=0;
		}
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}dt.resize(n+1);xl.resize(m+1);
	for(int i=1;i<=n;i++){
		cin>>sz[i];
		for(int j=1;j<=sz[i];j++){
			int A,T;cin>>A>>T;
			dt[i].push_back({A,T});
			xl[A].push_back(i);
		}
	}
	while(q--){
		for(int i=1;i<=m;i++){
			vst[i]=0;
		}
		for(int i=1;i<=n;i++){
			vstdt[i]=0;
		}
		int u,v;cin>>u>>v;
		vst[u]=1;
		long long ans=a[u]+a[v]+dfs(u,v);
		cout<<ans<<"\n"; 
	}
}
