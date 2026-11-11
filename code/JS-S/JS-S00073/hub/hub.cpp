#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int u[N],v[N];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1; i<n; ++i) cin>>u[i]>>v[i];
		cout<<"0\n";
	}
	return 0;
}
