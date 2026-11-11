#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k;
vector<int>edge[1000100];
signed main(){
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			edge[u].push_back(v);
			edge[v].push_back(u); 
		}
	}
	return 0;
}
/*
16:17 测试点1,2,3爆搜，分数=15
17:25 不会写爆搜 
*/

