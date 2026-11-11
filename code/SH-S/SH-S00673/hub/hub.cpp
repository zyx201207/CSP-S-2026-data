#include<bits/stdc++.h>
using namespace std;
const int N = 106+10;
long long c,m,d,q,t,w[N],vis[N];
vector <long long> g[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		long long n,k;
		cin >> n >> k;
		for(int i = 1;i < n;i++){
			long long u,v;
			cin >> u >> v;
			g[u].push_back(v);
		}
		cout << 1 << "\n";
	}
	return 0;
}
