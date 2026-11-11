#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		int n,k,minn=1e9;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			if(abs(u-v)<minn){
				minn=abs(u-v);
			}
		}
		cout<<minn<<"\n";
	} 
	return 0;
}
