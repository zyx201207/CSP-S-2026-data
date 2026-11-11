#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf=0x3f3f3f3f;
const i64 INF=0x3f3f3f3f3f3f3f3f;
const int N=1e6+5;
int n,k;
vector<int> mp[N];
void solve(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
} 
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c;
	cin>>c;
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
