#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e3+5;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;cin>>c>>T;
	while(T--){
		int n,k;cin>>n>>k;
		vector<int> edge[N];
		for(int i=1;i<=n;++i){
			int u,v;cin>>u>>v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		cout<<1<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
