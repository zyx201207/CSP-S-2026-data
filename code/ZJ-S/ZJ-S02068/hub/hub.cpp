#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+5;
int n,k;
int x[N];
struct node{
	int di,u,st;
	bool operator <(const node w)const{
		return di>w.di;
	}
};
vector<int>g[N];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;++i){
			int u,v;cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int ans;
		cout<<ans<<"\n";
	}
	return 0;
}
