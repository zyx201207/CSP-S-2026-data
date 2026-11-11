#include <iostream>
#include <vector>

using namespace std;

const int INF = 4e18;
const int N = 1e6+10;
int c,t;

void solve(int n,int k){
	struct edge{
		int u,v;
	};
	edge e[N];
	vector<int> dist(n+5,INF);
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[i].u=u;
		e[i].v=v;
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,k=0;
		cin>>n>>k;
		solve();
	}
	
	return 0;
}
