#include <iostream>
#include <vector>
using namespace std;
int c,t;
int n,k;
vector <int> a[4005];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
	}
	cin>>n>>k;
	
	return 0;
}

