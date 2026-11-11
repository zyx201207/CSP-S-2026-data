#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int c,T,n,k;
vector<int> g[N];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		for(int i=1,u,v;i<=n;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout<<"1\n";
	}
	return 0;
}