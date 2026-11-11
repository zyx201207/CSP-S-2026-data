#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;
int c,t;
int n,k;
vector<int>to[N];
int mxdep,mxid; 
void dfs(int u,int fa,int dep){
//	cout<<u<<endl;
	if(dep>mxdep){
		mxdep=dep;
		mxid=u;
	}
	for(int i=0;i<to[u].size();i++){
		int v=to[u][i];
		if(v==fa){
			continue;
		}
		dfs(v,u,dep+1);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		for(int i=1;i<=n;i++){
			to[i].clear();
		}
		mxdep=mxid=0;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
//			cout<<u<<" "<<v<<endl;
			to[u].push_back(v);
			to[v].push_back(u);
		}
		dfs(1,0,1);
//		cout<<mxid<<endl;
		mxdep=0;
		dfs(mxid,0,1);
//		cout<<mxdep<<endl;
		cout<<ceil((mxdep-k)*1.0/4)<<endl;
	}
	return 0;
}
