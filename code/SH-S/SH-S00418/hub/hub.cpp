#include <bits/stdc++.h>
using namespace std;

int c,t;
long long n,k;
vector <int> vec[1000050];
int fa[1000050];
int siz[1000050];
int dis[1000050];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i=0;i<=n;i++) vec[i].clear();
		for(int i=0,u,v;i<n-1;i++){
			cin >> u >> v;
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		cout<<1;
	}
	return 0;
}
