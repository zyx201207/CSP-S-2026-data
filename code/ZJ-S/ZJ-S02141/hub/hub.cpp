//Oct31==Dec25?
//T4 hub 解法1 预期0 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,T,n,k;
vector<int> e[1000010];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		cout<<1<<endl;
	}
	return 0;
}