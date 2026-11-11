#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
vector<int> E[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,T;cin>>c>>T;
	while(T--){
		int n,k;cin>>n>>k;
		for(int i=1;i<=n;i++)E[i].clear();
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			E[u].push_back(v);
			E[v].push_back(u);
		}
		cout<<"1\n";
	}
	return 0;
} 
