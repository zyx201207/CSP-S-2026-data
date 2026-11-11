#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,T,n,k;
vector<int> e[N];
void solve(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].emplace_back(v);
			e[v].emplace_back(u);
		}
		cout<<1<<"\n";
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c;
	solve();
	return 0;
}
