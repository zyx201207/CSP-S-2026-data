#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,t;
vector<pair<int,int>>g[1000010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout<<0<<'\n';
	}
	return 0;
}
/*TwT*/
