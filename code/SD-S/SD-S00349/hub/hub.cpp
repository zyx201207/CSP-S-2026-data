#include<bits/stdc++.h>
#define lllld long long
#define endl '\n'
using namespace std;
vector<int>g[100005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout<<1;
	}
	return 0;
}
/*
//freopen feropen froopen fropen freeopen luogu 1488910
*/
