#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+1e3;
int n,m,q,as;
vector<int>ne[N];
void dfs(int u,int fa,int e){
	if(e>as)as=e,q=u;
	for(int v:ne[u]){
		if(v==fa)continue;
		dfs(v,u,e+1);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,K;
	cin>>c>>K;
	while(K--){
		cin>>n>>m;
		for(int i=0;i<=n;i++){
			ne[i].clear();
		}
		for(int i=1;i<n;i++){
			int a,b;
			cin>>a>>b;
			ne[a].push_back(b);
			ne[b].push_back(a);
		}
		as=-1;
		dfs(1,0,0);
		as=-1;
		dfs(q,0,0);
		cout<<as/3<<endl;
	}
	return 0;
}
