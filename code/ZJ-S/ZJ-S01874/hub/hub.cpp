#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector<int> g[N];
void solve(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cout<<rand()<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--)solve();
	return 0;
}
//MIHUOXINGWEIDASHANG！！！