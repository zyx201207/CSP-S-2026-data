#include <iostream>
#include <vector>
using namespace std;
const int N=2e6+5;
int n,c,t,k,u,v;
vector <int> adj[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >>c>>t;
	while (t--){
		cin >>n>>k;
		for (int i=1;i<n;i++){
			cin >> u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}if (n==k) {
			cout << 0<<'\n';
		}else if (k==2){
			cout << n/3<<'\n';
		}else {
			int x;
			cout << (n-k)/3+x%(k+1)<<'\n';
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}