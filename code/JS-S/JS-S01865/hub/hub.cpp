#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int ans=INT_MAX;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			if(i%2==0) ans=min(max(u,v)-min(u,v),ans);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
