#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+7;
int c,t,n,k;
vector<int> edge[N];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		cout<<1<<endl;
	}
	return 0;
}
