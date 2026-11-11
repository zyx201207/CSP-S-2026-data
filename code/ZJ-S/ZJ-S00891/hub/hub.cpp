#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		int n,k,t;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
		}
		t=(n-k)/k;
		if(t==0)
			t=1;
		cout<<t<<'\n';
	}
	return 0;
}
