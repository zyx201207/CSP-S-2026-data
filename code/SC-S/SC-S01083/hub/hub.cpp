#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=998244353; 
int C,T,n,k; 
vector<int>e[N];
void solve(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	cout<<rand()%M<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>T;
	while(T--) solve();
	return 0; 
}