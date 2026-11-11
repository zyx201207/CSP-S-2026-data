#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=514514;
int c,t;
vector<int>g[N];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)g[i].erase(g[i].begin(),g[i].end());
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
	}
	return 0;
}
