#include<iostream>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;
const int RP=1e18+7;

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
		}
		cout<<k/2<<'\n';
	}
	return 0;
}


