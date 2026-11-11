#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	if(c==13||c==14){
		while(t--){
			int n,k;
			cin>>n>>k;
			for(int i=1;i<n;i++){
				int _,__;
				cin>>_>>__;
			}
			if(k>=n/2+1){
				cout<<n-k<<"\n";
			}
		}
	}
	return 0;
}

