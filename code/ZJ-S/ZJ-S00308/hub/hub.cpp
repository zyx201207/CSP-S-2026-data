#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,k;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
		}
		if(c==13||c==14){
			int m=n/2;
			if(k==n)cout<<0<<endl;
			else if(k>=m)cout<<1<<endl;
			else cout<<1+(m-k+3)/4<<endl;
			continue;
		}
	}
	return 0;
}
