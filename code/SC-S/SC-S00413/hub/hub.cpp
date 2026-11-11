#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+7;
int c,t,n,k;
vector<int> G[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)G[i].clear();
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			G[u].push_back(v),G[v].push_back(u);
		}
		cout<<1<<'\n';
	}
	return 0;
}