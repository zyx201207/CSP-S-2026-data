#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
vector<int> mp[50010];
//priority_queue<long long> qp;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	int ans;
	while(t--){
		cin>>n>>k;
		for(int i = 1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			mp[u].push_back(v);
			mp[v].push_back(u);
		}
		cout<<ans<<endl;
		ans++;
	}
	return 0;
} 
