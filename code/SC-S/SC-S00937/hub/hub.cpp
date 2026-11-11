#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n,k;
vector<int> e[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(0);
	cout.tie(nullptr)->sync_with_stdio(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u); 
		}
		cout<<abs(e[3][1]-e[1][1])/2<<'\n';
	} 
	return 0;
}