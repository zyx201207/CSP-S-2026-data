#include <iostream>
#include <vector>
using namespace std;

const int MAXN=2e6;
int c,t;
int n,k;
vector<int> mp[MAXN];
void solve(){
	cin >> n >> k;
	for(int i=1;i<=n;i++) mp[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin >> u >> v;
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	int m=(n-1)/2;
	if(k==n) cout << 0 << endl;
	else if(k>m) cout << 1 << endl;
	else cout << (m-k+2)/3+1 << endl;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin >> c >> t;
	while(t--){
		solve();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
