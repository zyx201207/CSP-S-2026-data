#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,t,c;
vector<int> gr[1000005];
void mian(){
	//²»»á 
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		gr[u].push_back(v);
	}
}
signed main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--) mian();
	return 0;
} 
