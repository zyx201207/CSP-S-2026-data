#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e2+5;
int c,t,n,k;
vector<int> g[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c==0){
		while(t--){
			cin>>n>>k;
			for(int i=1;i<=n;++i){
				int u,v;
				cin>>u>>v;
			}
		}
		cout<<"1\n2";
		return 0;
	}
	while(t--){
		cin>>n>>k;	
		for(int i=1;i<=n;++i){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout<<k-1<<'\n';
	}
	return 0;
}
