#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
int n,k;
vector<int> g[maxn];

int main(){
	srand(time(0));
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout<<rand()%n<<'\n';
		for(int i=1;i<=n;i++) g[i].clear();
	}
	
	return 0;
}